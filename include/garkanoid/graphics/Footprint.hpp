/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <cmath>

#include <garkanoid/utils/Pose2D.hpp>

namespace garkanoid {

class Footprint {
public:
  Footprint(const Pose2D &upper_left, const Pose2D &lower_right)
      : upper_left_{upper_left}, lower_right_{lower_right} {}

  Footprint() : Footprint(Pose2D{}, Pose2D{}) {}

  const Pose2D &upperLeft() const { return upper_left_; }

  const Pose2D &lowerRight() const { return lower_right_; }

  const double &width() const {
    return std::abs(lower_right_.x() - upper_left_.x());
  }

  const double &height() const {
    return std::abs(lower_right_.y() - upper_left_.y());
  }

private:
  Pose2D upper_left_;
  Pose2D lower_right_;
};

} // namespace garkanoid
