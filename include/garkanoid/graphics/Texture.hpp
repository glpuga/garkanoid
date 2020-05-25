/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// standard library
#include <memory>

// External
#include <SFML/Graphics.hpp>

namespace garkanoid {

struct Texture {
  sf::Texture handle;
};

using TexturePtr = std::shared_ptr<Texture>;

} // namespace garkanoid
