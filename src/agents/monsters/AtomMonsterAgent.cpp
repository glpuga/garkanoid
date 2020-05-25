/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

// standard library
#include <cmath>

#include <garkanoid/agents/monsters/AtomMonsterAgent.hpp>
#include <garkanoid/utils/CollisionVector.hpp>

namespace garkanoid {

AtomMonsterAgent::AtomMonsterAgent(const CommandFactoryBasePtr &command_factory,
                                   const AgentId &agent_id,
                                   const Pose2D initial_pose,
                                   const AnimationPtr &animation)
    : MonsterAgent(command_factory, agent_id, initial_pose),
      animation_{animation}, footprint_{animation->footprint()} {}

std::vector<CommandPtr>
AtomMonsterAgent::update(const WorldSummary &world_summary,
                         const std::list<CollisionData> &collisions,
                         const std::list<InputEvent> &events,
                         const double delta_t) {
  std::vector<CommandPtr> commands;

  for (const auto &other : collisions) {
    const auto &agent_type = other.agent_type;
    const auto &collision_vector = other.collision_vector;

    /* bounce anywhere */
    if (collision_vector) {
      speed_ = bounce(speed_, collision_vector);
    }
  }

  auto screen_height = world_summary.screen.lower_right.y() -
                       world_summary.screen.upper_left.y();
  if (pose().y() > screen_height * 0.75) {
    speed_ = bounce(speed_, {0, -1});
  }
  return commands;
}

} // namespace garkanoid
