/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/interfaces/AnimationBase.hpp>
#include <garkanoid/utils/datatypes.hpp>

namespace garkanoid {

class AnimationFactoryBase {
public:
  virtual ~AnimationFactoryBase() = default;

  virtual AnimationPtr instantiateAnimation(const AgentType &agent_type) = 0;
};

using AnimationFactoryPtr = std::shared_ptr<AnimationFactoryBase>;

} // namespace garkanoid
