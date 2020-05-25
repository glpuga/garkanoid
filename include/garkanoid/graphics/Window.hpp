/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// Standard library
#include <cstdint>

// External
#include <SFML/Graphics.hpp>

// garkanoid
#include <garkanoid/interfaces/WindowBase.hpp>

namespace garkanoid {

class Window : public WindowBase {
public:
  Window(const size_t width, const size_t height, const std::string &title)
      : handle_{sf::VideoMode(width, height), title} {}

  void clear() override { handle_.clear(sf::Color::Black); };

  void draw(const Sprite &sprite) override { handle_.draw(sprite.handle); }

  void display() override { handle_.display(); }

private:
  sf::RenderWindow handle_;
};

} // namespace garkanoid
