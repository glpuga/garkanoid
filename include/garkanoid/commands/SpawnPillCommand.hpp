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

namespace garkanoid {

class SpawnPillCommand : public CommandBase {
public:
  SpawnPillCommand(const AgentFactoryPtr &agent_factory, const Pose2D &pose,
                   const PillType &pill_type)
      : agent_factory_{agent_factory}, pose_{pose}, pill_type_{pill_type} {}

  bool execute(const GameStatePtr &world) override {
    world->level_state.agents.push_back(
        agent_factory_->createPill(pose_, pill_type_));
    return true;
  };

private:
  const AgentFactoryPtr agent_factory_;
  const Pose2D pose_;
  const PillType pill_type_;
};

} // namespace garkanoid
