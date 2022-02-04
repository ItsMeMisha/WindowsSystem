#include "Shape.hpp"

void Shape::makeInvisible() {
  visible = false;
}

void Shape::makeVisible() {
  visible = true;
}

void Shape::setPosition(const Point& pos) {
  position = pos;
}

Point Shape::getPosition() const {
  return position;
}

void Shape::setColor(const Color& clr) {
  color = clr;
}

Color Shape::getColor() const {
  return color;
}