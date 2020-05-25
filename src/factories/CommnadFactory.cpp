/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#include <garkanoid/commands/IncrementLivesCommand.hpp>
#include <garkanoid/commands/KillAgentCommand.hpp>
#include <garkanoid/commands/SetSlowModeCommand.hpp>
#include <garkanoid/commands/SpawnBallCommand.hpp>
#include <garkanoid/commands/SpawnPillCommand.hpp>
#include <garkanoid/factories/CommandFactory.hpp>

namespace garkanoid {

CommandPtr CommandFactory::createIncrementLivesCommand() const {
  return std::make_shared<IncrementLivesCommand>();
}

CommandPtr CommandFactory::createSetSlowDownCommand() const {
  return std::make_shared<SetSlowBallModeCommand>();
}

CommandPtr CommandFactory::createSpawnBallCommand(const Pose2D &pose,
                                                  const Speed2D &speed) const {
  return std::make_shared<SpawnBallCommand>(agent_factory_, pose, speed);
}

CommandPtr
CommandFactory::createSpawnPillCommand(const Pose2D &initial_pose,
                                       const PillType &pill_type) const {
  return std::make_shared<SpawnPillCommand>(agent_factory_, initial_pose,
                                            pill_type);
}

CommandPtr
CommandFactory::createKillAgentCommand(const AgentId &agent_id) const {
  return std::make_shared<KillAgentCommand>(agent_id);
}

} // namespace garkanoid
