/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// standard library
#include <cstdint>
#include <cstdlib>

namespace garkanoid {

class CollisionVector {
public:
  CollisionVector() = default;

  CollisionVector(const int32_t x, const int32_t y) {
    x_ = normalize(x);
    y_ = normalize(y);
  }

  int32_t x() const { return x_; }
  int32_t y() const { return y_; }

  operator bool() const { return ((x_ != 0) || (y_ != 0)); }

  CollisionVector &operator+=(const CollisionVector &rhs) {
    x_ += rhs.x();
    y_ += rhs.y();
    return *this;
  }

  CollisionVector operator+(const CollisionVector &rhs) const {
    CollisionVector aux{*this};
    aux += rhs;
    return aux;
  }

private:
  int32_t x_;
  int32_t y_;

  int32_t normalize(const int32_t x) const {
    if (x) {
      return x / abs(x);
    }
    return 0;
  }
};

} // namespace garkanoid
