/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#include <garkanoid/agents/bricks/MetalBrickAgent.hpp>

namespace garkanoid {

MetalBrickAgent::MetalBrickAgent(const CommandFactoryBasePtr &command_factory,
                                 const AgentId &agent_id,
                                 const Pose2D &initial_pose,
                                 const AnimationPtr &animation)
    : BrickAgent(command_factory, agent_id, initial_pose),
      animation_{animation} {}

std::vector<CommandPtr>
MetalBrickAgent::update(const WorldSummary &world_summary,
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
      --hits_left_;
      animation_->start(animation_rate_, false);
      if (hits_left_ == 0) {
        commands.emplace_back(commandFactory()->createKillAgentCommand(id()));
      }
    }
  }
  return commands;
}

} // namespace garkanoid
