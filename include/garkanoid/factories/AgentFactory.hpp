/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/interfaces/AgentBase.hpp>
#include <garkanoid/interfaces/AnimationFactoryBase.hpp>

namespace garkanoid {

class AgentFactory : public AgentFactoryBase {
public:
  AgentFactory(const CommandFactoryBasePtr &command_factory,
               const AnimationFactoryPtr &animation_factory)
      : command_factory_{command_factory_},
        animation_factory_{animation_factory} {}

  AgentBasePtr createVaus(const Pose2D &initial_pose) override;

  AgentBasePtr createBall(const Pose2D &initial_pose,
                          const Speed2D &initial_speed) override;

  AgentBasePtr
  createColoredBrick(const Pose2D &initial_pose,
                     const PillType hidden_pill = PillType::NONE) override;

  AgentBasePtr createMetalBrick(const Pose2D &initial_pose) override;

  AgentBasePtr createGoldenBrick(const Pose2D &initial_pose) override;

  AgentBasePtr createPill(const Pose2D &initial_pose,
                          const PillType pill_type) override;

  AgentBasePtr createAtomMonster(const Pose2D &initial_pose) override;

  AgentBasePtr createBallMonster(const Pose2D &initial_pose) override;

  AgentBasePtr createConeMonster(const Pose2D &initial_pose) override;

  AgentBasePtr createCubeMonster(const Pose2D &initial_pose) override;

  AgentBasePtr createSaturnMonster(const Pose2D &initial_pose) override;

  AgentBasePtr createTetraMonster(const Pose2D &initial_pose) override;

private:
  const CommandFactoryBasePtr command_factory_;
  const AnimationFactoryPtr animation_factory_;
};

using AgentFactoryPtr = std::shared_ptr<AgentFactoryBase>;

} // namespace garkanoid
