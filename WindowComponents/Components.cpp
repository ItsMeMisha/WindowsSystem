#include "Components.hpp"

void Movable::onMousePressed(const Point& pos) {
  isPressed = true;
}

void Movable::onMouseReleased(const Point& pos) {
  isPressed = false;
}

void Movable::onMouseMoved(const Point& pos) {
  if (isPressed) {
    moveTo(pos);
  }
}