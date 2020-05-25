/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

namespace garkanoid {

class GameStateBase {
public:
  virtual void processEvent(const InputEvent &event) {}

  virtual void updateScreen() = 0;

  virtual ~GameStateBase() = default;
};

} // namespace garkanoid
