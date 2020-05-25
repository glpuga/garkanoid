/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#include <garkanoid/agents/PillAgent.hpp>

namespace garkanoid {

PillAgent::PillAgent(const CommandFactoryBasePtr &command_factory,
                     const AgentId &agent_id, const Pose2D initial_pose,
                     const AnimationPtr &animation, const PillType &pill_type)
    : AgentBase(command_factory, agent_id, initial_pose), animation_{animation},
      pill_type_{pill_type}, footprint_{animation->footprint()} {}

std::vector<CommandPtr>
PillAgent::update(const WorldSummary &world_summary,
                  const std::list<CollisionData> &collisions,
                  const std::list<InputEvent> &events, const double delta_t) {
  std::vector<CommandPtr> commands;

  bool hit_vaus{false};
  for (const auto &other : collisions) {
    const auto &agent_type = other.agent_type;
    const auto &collision_vector = other.collision_vector;

    /* destroy the pill only when it touches the vaus */
    if ((agent_type == AgentType::VAUS) && collision_vector) {
      hit_vaus = true;
      break;
    }
  }

  if (hit_vaus) {
    commands.emplace_back(commandFactory()->createKillAgentCommand(id()));

    switch (pill_type_) {
    case PillType::NONE:
      break;
    case PillType::EXTRA_LIFE:
      commands.emplace_back(commandFactory()->createIncrementLivesCommand());
      break;
    case PillType::SLOW_DOWN:
      commands.emplace_back(commandFactory()->createSetSlowDownCommand());
      break;
    }
  }

  if (leftTheScreen(world_summary)) {
    commands.emplace_back(commandFactory()->createKillAgentCommand(id()));
  }

  setPose(Pose2D{pose().x() + fall_speed_.vx() * delta_t,
                 pose().y() + fall_speed_.vy() * delta_t});

  return commands;
}

} // namespace garkanoid
