/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/LevelState.hpp>
#include <garkanoid/PlayerState.hpp>

namespace garkanoid {

struct GameState {
  PlayerState player_state;
  LevelState level_state;
};

using GameStatePtr = std::shared_ptr<GameState>;

} // namespace garkanoid
