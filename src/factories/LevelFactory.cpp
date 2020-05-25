/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#include <garkanoid/factories/LevelFactory.hpp>

namespace garkanoid {

LevelState LevelFactory::buildLevel(const LevelID & /*level_id*/) const {
  const int32_t rows{6};
  const int32_t cols{10};
  const auto brick_footprint{
      agent_factory_->createColoredBrick(Pose2D(0.0, 0.0))->footprint()};

  LevelState level_state;

  /**
   * Bricks */
  {
    const Pose2D corner_pose{
        0.5 * (screen_.width() - cols * brick_footprint.width()),
        (screen_.width() * brick_block_relative_y_offset_)};

    Pose2D brick_pose(0.0, 0.0);
    for (int32_t i = 0; i < rows; ++i) {
      for (int32_t j = 0; j < cols; ++j) {
        level_state.agents.push_back(
            agent_factory_->createColoredBrick(brick_pose));
        brick_pose.x() += brick_footprint.width();
      }
      brick_pose.x() = 0.0;
      brick_pose.y() += brick_footprint.height();
    }
  }

  /**
   * Wall */
  {
    Pose2D ceiling_brick(0.0, 0.0);
    while (ceiling_brick.x() < screen_.width()) {
      level_state.agents.push_back(
          agent_factory_->createColoredBrick(ceiling_brick));
      ceiling_brick.x() += brick_footprint.width();
    }
  }
  {
    Pose2D left_brick{0.0, brick_footprint.height()};
    Pose2D right_brick{screen_.width(), brick_footprint.height()};

    while (left_brick.y() < screen_.height()) {
      level_state.agents.push_back(
          agent_factory_->createColoredBrick(right_brick));
      level_state.agents.push_back(
          agent_factory_->createColoredBrick(left_brick));
      right_brick.y() += brick_footprint.height();
      left_brick.y() += brick_footprint.height();
    }
  }

  /**
   * Ball */
  {
    const Pose2D initial_ball_pose{screen_.width() / 2.0,
                                   screen_.height() * ball_relative_y_offset_};
    const Speed2D initial_ball_speed{screen_.width() / 4.0,
                                     -screen_.height() / 4.0};
    level_state.agents.push_back(
        agent_factory_->createBall(initial_ball_pose, initial_ball_speed));
  }

  /**
   * Vaus */
  {
    const Pose2D initial_vaus_pose{
        screen_.width() / 2.0, screen_.height() * vaus_ship_relative_y_offset_};
    level_state.agents.push_back(agent_factory_->createVaus(initial_vaus_pose));
  }

  return level_state;
}

} // namespace garkanoid
