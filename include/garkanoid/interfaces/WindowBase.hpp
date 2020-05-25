/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// standard library
#include <memory>

// garkanoid
#include <garkanoid/graphics/Sprite.hpp>

namespace garkanoid {

class WindowBase {
public:
  virtual ~WindowBase() = default;

  virtual void clear() = 0;

  virtual void draw(const Sprite &sprite) = 0;

  virtual void display() = 0;
};

using WindowPtr = std::shared_ptr<WindowBase>;

} // namespace garkanoid
