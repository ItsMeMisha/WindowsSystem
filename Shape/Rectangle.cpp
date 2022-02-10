#include "Rectangle.hpp"

void Rectangle::render(RendererBridge& renderer) const {
  if (visible)
    renderer.renderRectangle(position, size, color);
}

bool Rectangle::containsPoint(const Point& point) const {
  if (point.x >= position.x && point.x <= position.x + size.x &&
      point.y >= position.y && point.y <= position.y + size.y)
    return true;
  
  return false;
}

Rectangle::Rectangle(const Point& pos, const Size& sz) {
  setPosition(pos);
  setSize(sz);
}