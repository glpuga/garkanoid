/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#include <garkanoid/graphics/Sprite.hpp>

namespace garkanoid {

Sprite::Sprite(const std::shared_ptr<Texture> &texture, const Rectangle &rect,
               const Pose2D &mass_center)
    : mass_center_{mass_center}, width_{rect.w}, height_{rect.h} {
  handle.setTexture(texture->handle);
  handle.setTextureRect(sf::IntRect(rect.x, rect.y, rect.w, rect.h));
}

Sprite::Sprite(const std::shared_ptr<Texture> &texture, const Rectangle &rect)
    : Sprite(texture, rect, Pose2D{rect.w / 2.0, rect.h / 2.0}) {}

void Sprite::setPose(const Pose2D &pose) {
  pose_ = pose;
  handle.setPosition(
      sf::Vector2f(pose.x() - mass_center_.x(), pose.y() - mass_center_.y()));
  handle.setRotation(Pose2D::rad2deg(pose.theta()));
}

Footprint Sprite::footprint() const {
  Pose2D upper_left{pose_.x() - mass_center_.x() - width_ / 2.0,
                    pose_.y() - mass_center_.y() - height_ / 2.0};
  Pose2D lower_right{upper_left.x() + width_, upper_left.y() + height_};
  return Footprint{upper_left, lower_right};
}

} // namespace garkanoid
