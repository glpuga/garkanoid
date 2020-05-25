/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// standard library
#include <list>

// garkanoid
#include <CollisionVector.hpp>
#include <garkanoid/utils/datatypes.hpp>

namespace garkanoid {

struct CollisionData {
  AgentId agent_id;
  AgentType agent_type;
  CollisionVector collision_vector;
};

} // namespace garkanoid
