#include "Window.hpp"

void Window::render(RendererBridge& renderer) {
  for(auto& winds : subwindows)
    winds->render(renderer);

  shape->render(renderer);
}

void Window::addSubwindow(Window* wd) {
  wd->parentWd = this;
  subwindows.push_back(wd);
}

const Shape& Window::getShape() const{
  return *shape;
}

void Window::setShape(Shape* shp) {
  shape = shp;
}

bool Window::isOpen() const {
  return isOpenFlag;
}