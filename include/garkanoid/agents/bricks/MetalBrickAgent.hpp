/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/agents/BrickAgent.hpp>
#include <garkanoid/interfaces/AnimationBase.hpp>

namespace garkanoid {

class MetalBrickAgent : public BrickAgent {
  MetalBrickAgent(const CommandFactoryBasePtr &command_factory,
                  const AgentId &agent_id, const Pose2D &initial_pose,
                  const AnimationPtr &animation);

  std::vector<CommandPtr> update(const WorldSummary &world_summary,
                                 const std::list<CollisionData> &collisions,
                                 const std::list<InputEvent> &events,
                                 const double delta_t) override;

  AgentType agentType() const override { return AgentType::METAL_BRICK; }

  Footprint footprint() const override { return animation_->footprint(); }

  const Sprite &sprite() const override { return animation_->sprite(); }

private:
  const int32_t block_strength_{3};
  const double animation_rate_{1.0};
  const AnimationPtr animation_;

  int32_t hits_left_{block_strength_};

  void updateAnimationPose(const Pose2D &pose) override {
    animation_->setPose(pose);
  }
};

} // namespace garkanoid
