/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// standard library
#include <vector>

// garkanoid
#include <garkanoid/interfaces/AgentFactoryBase.hpp>

namespace garkanoid {

struct LevelState {
  std::vector<AgentBasePtr> agents; /**< Active agents within the game. */
};

} // namespace garkanoid
