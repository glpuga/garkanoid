/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/LevelState.hpp>
#include <garkanoid/graphics/Screeen.hpp>
#include <garkanoid/interfaces/AgentFactoryBase.hpp>
#include <garkanoid/interfaces/LevelFactoryBase.hpp>

namespace garkanoid {

class LevelFactory : public LevelFactoryBase {
public:
  LevelFactory(const AgentFactoryPtr &agent_factory, const Screen &screen)
      : agent_factory_{agent_factory}, screen_{screen} {}

  LevelState buildLevel(const LevelID &level_id) const override;

private:
  const AgentFactoryPtr agent_factory_;
  const Screen screen_;
  const double brick_block_relative_y_offset_{0.2};
  const double vaus_ship_relative_y_offset_{0.8};
  const double ball_relative_y_offset_{0.7};
};

} // namespace garkanoid
