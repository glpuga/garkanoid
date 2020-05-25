/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// standard library
#include <algorithm>
#include <chrono>
#include <memory>
#include <vector>

// garkanoid
#include <garkanoid/interfaces/AnimationBase.hpp>

namespace garkanoid {

class Animation : public AnimationBase {
public:
  Animation(const std::vector<SpritePtr> &sprites);

  void start(const double rate, bool repeat_in_loop = true) override;

  void stop() override;

  void update() override;

  Footprint footprint() const override;

  void setPose(const Pose2D &pose) override;

  const Sprite &sprite() const override;

private:
  std::vector<SpritePtr> sprites_;
  bool repeat_in_loop_;
  double phase_{0.0};
  double rate_{0.0};
  bool started_{false};

  Pose2D current_pose_;

  std::chrono::system_clock::time_point latest_update_timestamp_;
};

using AnimationPtr = std::shared_ptr<Animation>;

} // namespace garkanoid
