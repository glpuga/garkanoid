/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// standard library
#include <list>
#include <memory>
#include <vector>

// garkanoid
#include <garkanoid/graphics/Sprite.hpp>
#include <garkanoid/interfaces/CommandFactoryBase.hpp>
#include <garkanoid/utils/CollistonData.hpp>
#include <garkanoid/utils/Pose2D.hpp>
#include <garkanoid/utils/WorldSummary.hpp>

namespace garkanoid {

class AgentBase {
public:
  AgentBase(const CommandFactoryBasePtr &command_factory,
            const AgentId &agent_id, const Pose2D initial_pose)
      : command_factory_{command_factory}, agent_id_{agent_id},
        pose_{initial_pose} {}

  virtual ~AgentBase() = default;

  const AgentId &id() const { return agent_id_; }

  const Pose2D &pose() const { return pose_; }

  virtual AgentType agentType() const = 0;

  virtual Footprint footprint() const = 0;

  virtual const Sprite &sprite() const = 0;

  /** Update the block state given a colission matrix */
  virtual std::vector<CommandPtr>
  update(const WorldSummary &world_summary,
         const std::list<CollisionData> &collisions,
         const std::list<InputEvent> &events, const double delta_t) = 0;

protected:
  static Speed2D bounce(const Speed2D &initial_speed,
                        const CollisionVector &collision_vector) {
    Speed2D speed{initial_speed};

    if ((speed.vy() > 0) && (collision_vector.y() < 0)) {
      speed.vy() *= collision_vector.y();
    } else if ((speed.vy() < 0) && (collision_vector.y() > 0)) {
      speed.vy() *= -collision_vector.y();
    }

    if ((speed.vx() > 0) && (collision_vector.x() < 0)) {
      speed.vx() *= collision_vector.x();
    } else if ((speed.vx() < 0) && (collision_vector.x() > 0)) {
      speed.vx() *= -collision_vector.x();
    }

    return speed;
  }

  bool leftTheScreen(const WorldSummary &world_summary) const {
    const auto agent_footprint = footprint();
    const auto &ul = agent_footprint.upperLeft();
    const auto &lr = agent_footprint.lowerRight();
    if ((lr.x() > world_summary.screen.width) && (ul.x() < 0.0) &&
        (lr.y() > world_summary.screen.height) && (ul.y() < 0.0)) {
      return true;
    }
    return false;
  }

  void setPose(const Pose2D &pose) {
    pose_ = pose;
    updateAnimationPose(pose);
  }

  const CommandFactoryBasePtr &commandFactory() const {
    return command_factory_;
  };

  virtual void updateAnimationPose(const Pose2D &pose) = 0;

private:
  const CommandFactoryBasePtr command_factory_;

  AgentId agent_id_;
  Pose2D pose_;
};

using AgentBasePtr = std::shared_ptr<AgentBase>;

} // namespace garkanoid
