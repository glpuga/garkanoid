/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

namespace garkanoid {

class Speed2D {
public:
  Speed2D(const double vx, const double vy) : vx_{vx}, vy_{vy} {}
  Speed2D() : vx_{0.0}, vy_{0.0} {};

  double &vx() { return vx_; }
  const double &vx() const { return vx_; }

  double &vy() { return vy_; }
  const double &vy() const { return vy_; }

private:
  double vx_;
  double vy_;
};

}; // namespace garkanoid
