/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

// standard library
#include <cmath>

#include <garkanoid/graphics/Animation.hpp>

namespace garkanoid {

Animation::Animation(const std::vector<SpritePtr> &sprites)
    : sprites_{sprites} {
  if (sprites_.size()) {
    auto it = sprites.begin();

    auto first_sprite_footprint = (*it)->footprint()();
    auto ul = first_sprite_footprint.upperLeft();
    auto lr = first_sprite_footprint.lowerRight();

    while (++it != sprites_.end()) {
      auto sprite_footprint = (*it)->footprint()();
      const auto &ul_sprite = sprite_footprint.upperLeft();
      const auto &lr_sprite = sprite_footprint.upperLeft();

      ul.x() = std::min(ul.x(), ul_sprite.x());
      ul.y() = std::min(ul.y(), ul_sprite.y());

      lr.x() = std::max(lr.x(), lr_sprite.x());
      lr.y() = std::max(lr.y(), lr_sprite.y());
    }

    enclosing_footprint_ = Footprint{ul, lr};
  }
}

void Animation::start(const double rate, bool repeat_in_loop = true) {
  repeat_in_loop_ = repeat_in_loop;
  phase_ = 0.0;
  rate_ = rate;
  latest_update_timestamp_ = std::chrono::system_clock::now();
  started_ = true;
}

void Animation::stop() { started_ = false; }

void Animation::update() {
  if (started_) {
    auto current_timestamp = std::chrono::system_clock::now();
    auto delta_duration = current_timestamp - latest_update_timestamp_;
    auto delta_sec = static_cast<double>(
                         std::chrono::duration_cast<std::chrono::milliseconds>(
                             delta_duration)
                             .count()) /
                     1000.0;
    phase_ += delta_sec * rate_;
    latest_update_timestamp_ = current_timestamp;

    if (repeat_in_loop_ && (phase_ >= 1.0)) {
      started_ = false;
      phase_ = 0.0;
    }
  }
}

const Sprite &Animation::sprite() const {
  auto sprite_count = sprites_.size();
  auto delta_phase = 1.0 / static_cast<double>(sprite_count);
  auto index = static_cast<int32_t>(floor(phase_ / delta_phase));
  index = (index >= sprite_count) ? (sprite_count - 1) : index;
  sprites_[index]->setPose(current_pose_);
  return *sprites_[index];
}

Footprint Animation::footprint() const { sprite().footprint(); }

void Animation::setPose(const Pose2D &pose) { current_pose_ = pose; }

} // namespace garkanoid
