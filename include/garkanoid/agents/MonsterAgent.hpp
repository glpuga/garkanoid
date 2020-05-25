/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/interfaces/AgentBase.hpp>
#include <garkanoid/interfaces/AnimationBase.hpp>

namespace garkanoid {

class MonsterAgent : public AgentBase {
public:
  MonsterAgent(const CommandFactoryBasePtr &command_factory,
               const AgentId &agent_id, const Pose2D initial_pose)
      : AgentBase(command_factory, agent_id, initial_pose) {}
};

} // namespace garkanoid
