#include "Rectangle.hpp"

void Rectangle::render(const RendererBridge& renderer) const {
  if (visible)
    renderer.renderRectangle(position, size, color);
}

bool Rectangle::containsPoint(const Point& point) const {
  if (point.x >= position.x && point.x <= position.x + size.x &&
      point.y >= position.y && point.y <= position.y + size.y)
    return true;
  
  return false;
}

void Rectangle::setSize(const Point& sz) {
  size = sz;
}

Point Rectangle::getSize() const {
  return size;
}