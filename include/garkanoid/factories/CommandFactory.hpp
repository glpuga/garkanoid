/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/interfaces/CommandFactoryBase.hpp>

namespace garkanoid {

class CommandFactory : public CommandFactoryBase {
public:
  CommandFactory(const AgentFactoryPtr &agent_factory)
      : agent_factory_{agent_factory} {}

  CommandPtr createIncrementLivesCommand() const override;

  CommandPtr createSetSlowDownCommand() const override;

  CommandPtr createSpawnBallCommand(const Pose2D &pose,
                                    const Speed2D &speed) const override;

  CommandPtr createSpawnPillCommand(const Pose2D &initial_pose,
                                    const PillType &type) const override;

  CommandPtr createKillAgentCommand(const AgentId &agent_id) const override;

private:
  const AgentFactoryPtr agent_factory_
};

} // namespace garkanoid
