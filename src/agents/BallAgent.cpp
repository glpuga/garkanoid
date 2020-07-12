/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

// standard library
#include <cmath>

#include <garkanoid/agents/BallAgent.hpp>

namespace garkanoid {

BallAgent::BallAgent(const CommandFactoryBasePtr &command_factory,
                     const AgentId &agent_id, const Pose2D initial_pose,
                     const AnimationPtr &animation)
    : AgentBase(command_factory, agent_id, initial_pose),
      animation_{animation} {}

std::vector<CommandPtr>
BallAgent::update(const WorldSummary &world_summary,
                  const std::list<CollisionData> &collisions,
                  const std::list<InputEvent> &events, const double delta_t) {
  std::vector<CommandPtr> commands;

  for (const auto &other : collisions) {
    const auto &agent_type = other.agent_type;
    const auto &collision_vector = other.collision_vector;

    /* bounce on any kind of object on the screen */
    if (collision_vector) {
      speed_ = bounce(speed_, collision_vector);
    }

    /* If the ball left the screen, remove it from the list of agents */
    if (leftTheScreen(world_summary)) {
      commands.emplace_back(commandFactory()->createKillAgentCommand(id()));
    }

    setPose(Pose2D{pose().x() + speed_.vx() * delta_t,
                   pose().y() + speed_.vy() * delta_t});
  }
  return commands;
}

} // namespace garkanoid
