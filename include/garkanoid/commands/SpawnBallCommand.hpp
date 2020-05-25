/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/GameState.hpp>
#include <garkanoid/agents/BallAgent.hpp>
#include <garkanoid/interfaces/AgentFactoryBase.hpp>
#include <garkanoid/interfaces/CommandBase.hpp>
#include <garkanoid/utils/Pose2D.hpp>
#include <garkanoid/utils/Speed2D.hpp>

namespace garkanoid {

class SpawnBallCommand : public CommandBase {
public:
  SpawnBallCommand(const AgentFactoryPtr &agent_factory, const Pose2D &pose,
                   const Speed2D &speed)
      : agent_factory_{agent_factory}, pose_{pose}, speed_{speed} {}

  bool execute(const GameStatePtr &world) override {
    world->level_state.agents.push_back(
        agent_factory_->createBall(pose_, speed_));
    return true;
  };

private:
  const Pose2D pose_;
  const Speed2D speed_;
  const AgentFactoryPtr agent_factory_;
};

} // namespace garkanoid
