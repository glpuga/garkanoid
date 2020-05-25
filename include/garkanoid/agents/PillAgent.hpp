/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/interfaces/AgentBase.hpp>
#include <garkanoid/interfaces/AnimationBase.hpp>

namespace garkanoid {

class PillAgent : public AgentBase {
public:
  PillAgent(const CommandFactoryBasePtr &command_factory,
            const AgentId &agent_id, const Pose2D initial_pose,
            const AnimationPtr &animation, const PillType &pill_type);

  std::vector<CommandPtr> update(const WorldSummary &world_summary,
                                 const std::list<CollisionData> &collisions,
                                 const std::list<InputEvent> &events,
                                 const double delta_t) override;

  AgentType agentType() const override { return AgentType::PILL; }

  Footprint footprint() const override { return animation_->footprint(); }

  const Sprite &sprite() const override { return animation_->sprite(); }

private:
  const AnimationPtr animation_;
  const PillType pill_type_;
  const Footprint footprint_;
  const Speed2D fall_speed_{0.0, 5.0};

  void updateAnimationPose(const Pose2D &pose) override {
    animation_->setPose(pose);
  }
};

} // namespace garkanoid
