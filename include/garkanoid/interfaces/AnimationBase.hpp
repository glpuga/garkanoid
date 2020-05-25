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

class AnimationBase {
public:
  virtual ~AnimationBase() = default;

  virtual void start(const double rate, bool repeat_in_loop = true) = 0;

  virtual void stop() = 0;

  virtual void update() = 0;

  virtual Footprint footprint() const = 0;

  virtual void setPose(const Pose2D &pose) = 0;

  virtual const Sprite &sprite() const = 0;
};

using AnimationPtr = std::shared_ptr<AnimationBase>;

} // namespace garkanoid
