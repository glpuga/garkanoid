/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

namespace garkanoid {

class Pose2D {
public:
  Pose2D(const double x, const double y, const double theta = 0.0)
      : x_{x}, y_{y}, theta_{theta} {}

  Pose2D(){};

  double &x() { return x_; }
  const double &x() const { return x_; }

  double &y() { return y_; }
  const double &y() const { return y_; }

  double &theta() { return theta_; }
  const double &theta() const { return theta_; }

  static double rad2deg(const double theta) { return (pi_ * theta / 180.0); }

private:
  static const double pi_{3.141592};

  double x_{0.0};
  double y_{0.0};
  double theta_{0.0};
};
}; // namespace garkanoid
