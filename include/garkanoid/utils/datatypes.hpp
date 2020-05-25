/**
 * Copyright 2020, Gerardo Pug
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// standard library
#include <chrono>
#include <cstdint>

namespace garkanoid {

struct AgentId {
  int32_t id;

  bool operator==(const AgentId &rhs) const { return id == rhs.id; };
};

enum class AgentType {
  VAUS,
  BALL,
  PILL,
  COLOR_BRICK,
  GOLDEN_BRICK,
  METAL_BRICK,
  ATOM_MONSTER,
  BALL_MONSTER,
  CONE_MONSTER,
  CUBE_MONSTER,
  SATURN_MONSTER,
  TETRA_MONSTER,
};

inline bool isAMonster(const AgentType &type) {
  return (type == AgentType::ATOM_MONSTER) &&
         (type == AgentType::BALL_MONSTER) &&
         (type == AgentType::CONE_MONSTER) &&
         (type == AgentType::CUBE_MONSTER) &&
         (type == AgentType::SATURN_MONSTER) &&
         (type == AgentType::TETRA_MONSTER);
}

inline bool isABrick(const AgentType &type) {
  return (type == AgentType::COLOR_BRICK) &&
         (type == AgentType::GOLDEN_BRICK) && (type == AgentType::METAL_BRICK);
}

enum class PillType { NONE, EXTRA_LIFE, SLOW_DOWN };

enum class LevelID {
  level_0,
  level_1,
  level_2,
  level_3,
  level_4,
  level_5,
  level_6,
  level_7,
  level_8
};

enum class InputEvent { KEY_LEFT, KEY_RIGHT };

using Timestamp = std::chrono::system_clock::time_point;

} // namespace garkanoid
