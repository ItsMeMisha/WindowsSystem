#ifndef __BASIC_ELEMENTS_HPP__
#define __BASIC_ELEMENTS_HPP__

//==============================================================================

#include "../WindowComponents/Components.hpp"
#include "../Window/Window.hpp"

class BasicButton : public Window, public Clickable {
 protected:
  void onMousePressed(const Point& pos) override;
  void onMouseReleased(const Point& pos) override;
  void onMouseMoved(const Point& pos) override;

 public:
  void handleEvent(const Event* event) override;
};

class ScrollSlider : public Window, public Movable {
 protected:
  void onMousePressed(const Point& pos) override;
  void onMouseReleased(const Point& pos) override;
  void onMouseMoved(const Point& pos) override;

  void moveTo(const Point& newPos) override;
 public:
  void handleEvent(const Event* event) override;
};

class ScrollBar : public Window, public Clickable {
 protected:
  void onMousePressed(const Point& pos) override;
  void onMouseReleased(const Point& pos) override;
  void onMouseMoved(const Point& pos) override;
 public:
  void handleEvent(const Event* event) override;
};

class ScrollWindow : public Window, public Scrollable {
 protected:
  void scrollTo(const Vector2f& scrollPos) override;
 public:
  void handleEvent(const Event* event) override;
  ScrollWindow(const Point& pos, const Vector2d& size);
};

//==============================================================================

#endif //__BASIC_ELEMENTS_HPP__