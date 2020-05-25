/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/game_states/PlayingGameState.hpp>

namespace garkanoid {

PlayingGameState::PlayingGameState(const WindowPtr &window_handle,
                                   const LevelFactoryPtr &level_factory)
    : window_handle_{window_handle}, level_factory_{level_factory},
      latest_update_time_tag_{std::chrono::system_clock::now()} {

  game_state_.player_state.lives = 3;
  game_state_.player_state.points = 0;
  game_state_.player_state.slow_ball_mode = false;
  game_state_.player_state.current_level = LevelID::level_0;

  game_state_.level_state =
      level_factory->buildLevel(game_state_.player_state.current_level);
}

void PlayingGameState::processEvent(const InputEvent &event) {
  external_events_.push_back(event);
}

void PlayingGameState::updateScreen() {
  window_handle_->clear();

  // Update the time tag, and determine the time delta
  auto current_time = std::chrono::system_clock::now();
  auto delta_t = std::chrono::duration_cast<std::chrono::milliseconds>(
      current_time - latest_update_time_tag_);
  auto delta_t_sec = static_cast<double>(delta_t.count()) / 1000.0;
  latest_update_time_tag_ = current_time;

  // Build world summary
  WorldSummary summary;
  for (const auto &agent : game_state_.level_state.agents) {
    summary.agent_state_vector.emplace_back(agent->id(), agent->agentType(),
                                            agent->pose(), agent->footprint());
  }

  // Update game state
  std::vector<CommandPtr> commands;
  for (auto &agent : game_state_.level_state.agents) {
    auto new_cmds = agent->update(summary, findCollisions(agent, summary),
                                  (agent->agentType() == AgentType::VAUS)
                                      ? external_events_
                                      : std::list<InputEvent>{},
                                  delta_t_sec);

    std::move(new_cmds.begin(), new_cmds.end(), std::back_inserter(commands));
  }

  // Clear event queue
  external_events_.clear();

  // Process the resulting list of commands
  for (const auto &command : commands) {
  }

  // Now that all agents have been updated, draw their resulting state
  for (const auto &agent : game_state_.level_state.agents) {
    window_handle_->draw(agent->sprite());
  }

  window_handle_->display();
}

const std::list<CollisionData> &
PlayingGameState::findCollisions(const AgentBasePtr &agent,
                                 const WorldSummary &summary) {
  std::list<CollisionData> collision_data;
  for (const auto &other_agent_summary : summary.agent_state_vector) {
    const auto collision_vector = calculateCollisionVector(
        agent->footprint(), other_agent_summary.footprint);
    if (collision_vector) {
      collision_data.emplace_back(other_agent_summary.agent_id,
                                  other_agent_summary.agent_type,
                                  collision_vector);
    }
  }
}

CollisionVector
PlayingGameState::calculateCollisionVector(const Footprint &agent_footprint,
                                           const Footprint &other_footprint) {
  auto is_within = [](const Pose2D &point, const Footprint &footprint) {
    if ((footprint.upperLeft().x() <= point.x()) &&
        (footprint.lowerRight().x() >= point.x()) &&
        (footprint.upperLeft().y() <= point.y()) &&
        (footprint.lowerRight().y() >= point.y())) {
      return true;
    }
    return false;
  };

  // Get the four points in the footprint
  const Pose2D &ul = agent_footprint.upperLeft();
  const Pose2D &lr = agent_footprint.lowerRight();
  const Pose2D ur{lr.x(), ul.y()};
  const Pose2D ll{ul.x(), lr.y()};

  CollisionVector cv;

  if (is_within(ll, other_footprint)) {
    cv += CollisionVector{1, -1};
  }
  if (is_within(lr, other_footprint)) {
    cv += CollisionVector{-1, -1};
  }
  if (is_within(ul, other_footprint)) {
    cv += CollisionVector{1, 1};
  }
  if (is_within(ur, other_footprint)) {
    cv += CollisionVector{-1, 1};
  }

  return cv;
}

} // namespace garkanoid
