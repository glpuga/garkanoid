/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

// standard library
#include <vector>

#include <garkanoid/agents/VausAgent.hpp>

namespace garkanoid {

VausAgent::VausAgent(const CommandFactoryBasePtr &command_factory,
                     const AgentId &agent_id, const Pose2D &initial_pose,
                     AnimationPtr &animation)
    : AgentBase(command_factory, agent_id, initial_pose), animation_{animation},
      footprint_{animation->footprint()} {}

std::vector<CommandPtr>
VausAgent::update(const WorldSummary &world_summary,
                  const std::list<CollisionData> &collisions,
                  const std::list<InputEvent> &events, const double delta_t) {
  std::vector<CommandPtr> commands;

  bool left_available{true};
  bool right_available{true};

  for (const auto &other : collisions) {
    const auto &collision_vector = other.collision_vector;

    if (collision_vector.x() > 0) {
      left_available = false;
    }
    if (collision_vector.x() < 0) {
      right_available = false;
    }
  }

  auto updated_pose{pose()};
  for (const auto &event : events) {
    if (left_available && (event == InputEvent::KEY_LEFT)) {
      updated_pose.x() -= delta_x_;
    } else if (right_available && (event == InputEvent::KEY_RIGHT)) {
      updated_pose.x() += delta_x_;
      break;
    }
  }
  setPose(updated_pose);

  return commands;
}

} // namespace garkanoid
