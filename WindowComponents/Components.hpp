#ifndef __COMPONENTS_HPP__
#define __COMPONENTS_HPP__

//==============================================================================

#include "../Utility/Point.hpp"

class Clickable {
 protected:
  virtual void onMousePressed(const Point& pos) = 0;
  virtual void onMouseReleased(const Point& pos) = 0;
  virtual void onMouseMoved(const Point& pos) = 0;

  bool isPressed = false;
 public:
  virtual ~Clickable() = default;
};

class Movable : public Clickable {
 protected:
  void onMousePressed(const Point& pos) override;
  void onMouseReleased(const Point& pos) override;
  void onMouseMoved(const Point& pos) override;

  virtual void moveTo(const Point& newPos) = 0;

 public:
  virtual ~Movable() = default;
};

class Scrollable {
 protected:
  virtual void scrollTo(const Vector2f& scrollPos) = 0;
 public:
  virtual ~Scrollable() = default;
};

//==============================================================================

#endif //__COMPONENTS_HPP__