/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/PlayerState.hpp>
#include <garkanoid/utils/datatypes.hpp>

namespace garkanoid {

class LevelFactoryBase {
public:
  virtual ~LevelFactoryBase() = default;

  virtual LevelState buildLevel(const LevelID &level_id) const = 0;
};

using LevelFactoryPtr = std::shared_ptr<LevelFactoryBase>;

} // namespace garkanoid
