/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// standard library
#include <cstdint>

namespace garkanoid {

struct PlayerState {
  int32_t lives{3};           /**< Remaining player lives */
  int32_t points{0};          /**< Current accumulated points */
  bool slow_ball_mode{false}; /**< Slow ball mode */

  LevelID current_level{LevelID::level_0};
};

} // namespace garkanoid
