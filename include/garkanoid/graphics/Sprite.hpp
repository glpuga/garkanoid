/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// standard library
#include <memory>

// External
#include <SFML/Graphics.hpp>

// garkanoid
#include <garkanoid/graphics/Footprint.hpp>
#include <garkanoid/graphics/Texture.hpp>
#include <garkanoid/utils/Pose2D.hpp>

namespace garkanoid {

struct Sprite {
  struct Rectangle {
    double x, y, w, h;
  };

  Sprite(const std::shared_ptr<Texture> &texture, const Rectangle &rect,
         const Pose2D &mass_center);

  Sprite(const std::shared_ptr<Texture> &texture, const Rectangle &rect)
      : Sprite(texture, rect, Pose2D{rect.w / 2.0, rect.h / 2.0}) {}

  void setPose(const Pose2D &pose);

  Footprint footprint() const;

  sf::Sprite handle;

private:
  const Pose2D mass_center_;
  const double width_;
  const double height_;
  Pose2D pose_;
  std::shared_ptr<Texture> texture_;
};

using SpritePtr = std::shared_ptr<Sprite>;

} // namespace garkanoid
