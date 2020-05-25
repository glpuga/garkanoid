/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/GameState.hpp>

namespace garkanoid {

class CommandBase {
public:
  virtual ~CommandBase() = default;
  virtual bool execute(const GameStatePtr &world) = 0;
};

using CommandPtr = std::shared_ptr<CommandBase>;

} // namespace garkanoid
