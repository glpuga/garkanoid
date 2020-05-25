/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#include <garkanoid/agents/BallAgent.hpp>
#include <garkanoid/agents/PillAgent.hpp>
#include <garkanoid/agents/VausAgent.hpp>
#include <garkanoid/agents/bricks/ColorBrickAgent.hpp>
#include <garkanoid/agents/bricks/GoldenBrickAgent.hpp>
#include <garkanoid/agents/bricks/MetalBrickAgent.hpp>
#include <garkanoid/agents/monsters/AtomMonsterAgent.hpp>
#include <garkanoid/agents/monsters/BallMonsterAgent.hpp>
#include <garkanoid/agents/monsters/ConeMonsterAgent.hpp>
#include <garkanoid/agents/monsters/CubeMonsterAgent.hpp>
#include <garkanoid/agents/monsters/SaturnMonsterAgent.hpp>
#include <garkanoid/agents/monsters/TetraMonsterAgent.hpp>
#include <garkanoid/factories/AgentFactory.hpp>

namespace garkanoid {

AgentBasePtr AgentFactory::createVaus(const Pose2D &initial_pose) {
  /* TBD */
  return nullptr;
}

AgentBasePtr AgentFactory::createBall(const Pose2D &initial_pose,
                                      const Speed2D &initial_speed) {
  /* TBD */
  return nullptr;
}

AgentBasePtr createColoredBrick(const Pose2D &initial_pose,
                                const PillType hidden_pill = PillType::NONE) {
  /* TBD */
  return nullptr;
}
AgentBasePtr AgentFactory::createMetalBrick(const Pose2D &initial_pose) {
  /* TBD */
  return nullptr;
}

AgentBasePtr AgentFactory::createGoldenBrick(const Pose2D &initial_pose) {
  /* TBD */
  return nullptr;
}

AgentBasePtr AgentFactory::createPill(const Pose2D &initial_pose,
                                      const PillType pill_type) {
  /* TBD */
  return nullptr;
}

AgentBasePtr AgentFactory::createAtomMonster(const Pose2D &initial_pose) {
  /* TBD */
  return nullptr;
}

AgentBasePtr AgentFactory::createBallMonster(const Pose2D &initial_pose) {
  /* TBD */
  return nullptr;
}

AgentBasePtr AgentFactory::createConeMonster(const Pose2D &initial_pose) {
  /* TBD */
  return nullptr;
}

AgentBasePtr AgentFactory::createCubeMonster(const Pose2D &initial_pose) {
  /* TBD */
  return nullptr;
}

AgentBasePtr AgentFactory::createSaturnMonster(const Pose2D &initial_pose) {
  /* TBD */
  return nullptr;
}

AgentBasePtr AgentFactory::createTetraMonster(const Pose2D &initial_pose) {
  /* TBD */
  return nullptr;
}

} // namespace garkanoid
