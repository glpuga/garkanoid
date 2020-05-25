/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

namespace garkanoid {

class Screen {
public:
  Screen(const double width, const double height) : width_{0.0}, height_{0.0} {}

  Screen() : Screen(0.0, 0.0) {}

  double width() const { return width_; }

  double height() const { return height_; }

private:
  double width_;
  double height_;
};

} // namespace garkanoid
