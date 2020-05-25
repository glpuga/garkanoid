/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// standard library
#include <memory>

// garkanoid
#include <garkanoid/interfaces/AgentBase.hpp>
#include <garkanoid/utils/Pose2D.hpp>
#include <garkanoid/utils/Speed2D.hpp>

namespace garkanoid {

class AgentFactoryBase {
public:
  virtual ~AgentFactoryBase() = default;

  virtual AgentBasePtr createVaus(const Pose2D &initial_pose) = 0;
  virtual AgentBasePtr createBall(const Pose2D &initial_pose,
                                  const Speed2D &initial_speed) = 0;

  virtual AgentBasePtr
  createColoredBrick(const Pose2D &initial_pose,
                     const PillType hidden_pill = PillType::NONE) = 0;
  virtual AgentBasePtr createMetalBrick(const Pose2D &initial_pose) = 0;
  virtual AgentBasePtr createGoldenBrick(const Pose2D &initial_pose) = 0;

  virtual AgentBasePtr createPill(const Pose2D &initial_pose,
                                  const PillType pill_type) = 0;

  virtual AgentBasePtr createAtomMonster(const Pose2D &initial_pose) = 0;
  virtual AgentBasePtr createBallMonster(const Pose2D &initial_pose) = 0;
  virtual AgentBasePtr createConeMonster(const Pose2D &initial_pose) = 0;
  virtual AgentBasePtr createCubeMonster(const Pose2D &initial_pose) = 0;
  virtual AgentBasePtr createSaturnMonster(const Pose2D &initial_pose) = 0;
  virtual AgentBasePtr createTetraMonster(const Pose2D &initial_pose) = 0;
};

using AgentFactoryPtr = std::shared_ptr<AgentFactoryBase>;

} // namespace garkanoid
