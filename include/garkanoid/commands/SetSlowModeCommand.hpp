/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// standard library
#include <memory>

// garkanoid
#include <garkanoid/GameState.hpp>
#include <garkanoid/interfaces/CommandBase.hpp>

namespace garkanoid {

class SetSlowBallModeCommand : public CommandBase {
public:
  bool execute(const GameStatePtr &world) override {
    world->player_state.slow_ball_mode = true;
    return true;
  };
};

} // namespace garkanoid
