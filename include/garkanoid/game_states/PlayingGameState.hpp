/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/GameState.hpp>
#include <garkanoid/interfaces/GameStateBase.hpp>
#include <garkanoid/interfaces/LevelFactoryBase.hpp>
#include <garkanoid/interfaces/WindowBase.hpp>

namespace garkanoid {

class PlayingGameState : public GameStateBase {
public:
  PlayingGameState(const WindowPtr &window_handle,
                   const LevelFactoryPtr &level_factory);

  void processEvent(const InputEvent &event) override;

  void PlayingGameState::updateScreen() override;

private:
  const WindowPtr window_handle_;
  const LevelFactoryPtr level_factory_;
  std::chrono::system_clock::time_point latest_update_time_tag_;
  GameState game_state_;
  std::list<InputEvent> external_events_;

  const std::list<CollisionData> &findCollisions(const AgentBasePtr &agent,
                                                 const WorldSummary &summary);

  CollisionVector calculateCollisionVector(const Footprint &agent_footprint,
                                           const Footprint &other_footprint);
};

} // namespace garkanoid
