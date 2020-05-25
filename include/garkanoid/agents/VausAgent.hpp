/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/interfaces/AgentBase.hpp>
#include <garkanoid/interfaces/AnimationBase.hpp>

namespace garkanoid {

class VausAgent : public AgentBase {
public:
  VausAgent(const CommandFactoryBasePtr &command_factory,
            const AgentId &agent_id, const Pose2D &initial_pose,
            const AnimationPtr &animation);

  std::vector<CommandPtr> update(const WorldSummary &world_summary,
                                 const std::list<CollisionData> &collisions,
                                 const std::list<InputEvent> &events,
                                 const double delta_t) override;

  AgentType agentType() const override { return AgentType::VAUS; }

  Footprint footprint() const override { return animation_->footprint(); }

  const Sprite &sprite() const override { return animation_->sprite(); }

private:
  const double delta_x_{5};

  const AnimationPtr animation_;
  const Footprint footprint_;

  void updateAnimationPose(const Pose2D &pose) override {
    animation_->setPose(pose);
  }
};

} // namespace garkanoid
