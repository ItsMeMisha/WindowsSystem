#include "Window.hpp"

void Window::render(const RendererBridge& renderer) const {
  shape->render(renderer);
}

void Window::addSubwindow(Window* wd) {
  wd->parentWd = this;
  subwindows.push_back(wd);
}

Shape& Window::getShape() {
  return *shape;
}