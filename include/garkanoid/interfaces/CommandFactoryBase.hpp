/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// standard library
#include <memory>

// garkanoid
#include <garkanoid/interfaces/CommandBase.hpp>
#include <garkanoid/utils/Pose2D.hpp>
#include <garkanoid/utils/Speed2D.hpp>

namespace garkanoid {

class CommandFactoryBase {
public:
  virtual ~CommandFactoryBase() = default;

  virtual CommandPtr createIncrementLivesCommand() const = 0;

  virtual CommandPtr createSetSlowDownCommand() const = 0;

  virtual CommandPtr createSpawnBallCommand(const Pose2D &pose,
                                            const Speed2D &speed) const = 0;

  virtual CommandPtr createSpawnPillCommand(const Pose2D &initial_pose,
                                            const PillType &type) const = 0;

  virtual CommandPtr createKillAgentCommand(const AgentId &agent_id) const = 0;
};

using CommandFactoryBasePtr = std::shared_ptr<CommandFactoryBase>;

} // namespace garkanoid
