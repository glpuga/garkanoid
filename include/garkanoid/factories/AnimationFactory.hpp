/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/interfaces/AnimationFactoryBase.hpp>

namespace garkanoid {

class AnimationFactory : public AnimationFactoryBase {
public:
  AnimationPtr instantiateAnimation(const AgentType &agent_type) override;
};

using AnimationFactoryPtr = std::shared_ptr<AnimationFactoryBase>;

} // namespace garkanoid
