/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/interfaces/AgentBase.hpp>
#include <garkanoid/interfaces/AnimationBase.hpp>

namespace garkanoid {

class BallAgent : public AgentBase {
public:
  BallAgent(const CommandFactoryBasePtr &command_factory,
            const AgentId &agent_id, const Pose2D initial_pose,
            const AnimationPtr &animation);

  std::vector<CommandPtr> update(const WorldSummary &world_summary,
                                 const std::list<CollisionData> &collisions,
                                 const std::list<InputEvent> &events,
                                 const double delta_t) override;

  AgentType agentType() const override { return AgentType::BALL; }

  Footprint footprint() const override { return animation_->footprint(); }

  const Sprite &sprite() const override { return animation_->sprite(); }

private:
  const AnimationPtr animation_;
  const Speed2D initial_speed_{10, 10};

  Speed2D speed_{initial_speed_};

  bool leftTheScreen() const;

  void updateAnimationPose(const Pose2D &pose) override {
    animation_->setPose(pose);
  }
};

} // namespace garkanoid
