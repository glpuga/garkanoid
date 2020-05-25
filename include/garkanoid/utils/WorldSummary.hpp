/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// standard library
#include <list>

// garkanoid
#include <garkanoid/utils/Pose2D.hpp>
#include <garkanoid/utils/Speed2D.hpp>

namespace garkanoid {

struct WorldSummary {
  struct AgentExternalState {
    AgentId agent_id;
    AgentType agent_type;
    Pose2D pose;
    Footprint footprint;
  };

  std::vector<AgentExternalState> agent_state_vector;

  struct {
    double width;
    double height;
  } screen;
};

} // namespace garkanoid
