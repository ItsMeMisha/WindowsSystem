#include "BasicElements.hpp"

void BasicButton::onMousePressed(const Point& pos) {
  if (shape->containsPoint(pos)) {
    isPressed = true;
  }
}

void BasicButton::onMouseReleased(const Point& pos) {
  isPressed = false;
}

void BasicButton::onMouseMoved(const Point& pos) {
  return;
}

void BasicButton::handleEvent (const Event* event) {
  Window::handleEvent(event);

  Point pos;
  switch (event->getEventType()) {
  case EventType::MousePress:
    pos = (dynamic_cast<const MouseEvent*> (event))->getPos();
    onMousePressed(pos);
    break;
  
  case EventType::MouseRelease:
    pos = (dynamic_cast<const MouseEvent*> (event))->getPos();
    onMouseReleased(pos);
    break;
  
  case EventType::MouseMove:
    pos = (dynamic_cast<const MouseEvent*> (event))->getPos();
    onMouseMoved(pos);
    break;
  }
}

void ScrollSlider::onMousePressed(const Point& pos) {

}

void ScrollSlider::onMouseReleased(const Point& pos) {

}

void ScrollSlider::onMouseMoved(const Point& pos) {

}

void ScrollSlider::moveTo(const Point& newPos) {

}

void ScrollSlider::handleEvent(const Event* event) {

}

void ScrollBar::onMousePressed(const Point& pos) {

}

void ScrollBar::onMouseReleased(const Point& pos) {

}

void ScrollBar::onMouseMoved(const Point& pos) {

}

void ScrollBar::handleEvent(const Event* event) {

}

void ScrollWindow::scrollTo(const Vector2f& scrollPos) {

}

void ScrollWindow::handleEvent(const Event* event) {

}

ScrollWindow::ScrollWindow(const Point& pos, const Vector2d& size) {

}