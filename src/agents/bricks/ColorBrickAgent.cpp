/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#include <garkanoid/agents/bricks/ColorBrickAgent.hpp>

namespace garkanoid {

ColorBrickAgent::ColorBrickAgent(const CommandFactoryBasePtr &command_factory,
                                 const AgentId &agent_id,
                                 const Pose2D &initial_pose,
                                 const AnimationPtr &animation,
                                 const PillType &hidden_pill_type)
    : BrickAgent(command_factory, agent_id, initial_pose),
      animation_{animation}, hidden_pill_type_{hidden_pill_type} {}

std::vector<CommandPtr>
ColorBrickAgent::update(const WorldSummary &world_summary,
                        const std::list<CollisionData> &collisions,
                        const std::list<InputEvent> &events,
                        const double delta_t) {
  std::vector<CommandPtr> commands;

  for (const auto &other : collisions) {
    const auto &agent_type = other.agent_type;
    const auto &collision_vector = other.collision_vector;

    /* if there's a collision with a ball, then destroy the block and spawn a
       pill if there's a hidden pill behind it */
    if ((agent_type == AgentType::BALL) && collision_vector) {
      commands.emplace_back(commandFactory()->createKillAgentCommand(id()));
      if (hidden_pill_type_ != PillType::NONE) {
        commands.emplace_back(commandFactory()->createSpawnPillCommand(
            pose(), hidden_pill_type_));
      }
    }
  }
  return commands;
}

} // namespace garkanoid
