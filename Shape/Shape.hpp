#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

//==============================================================================

#include "../Renderer/RendererBridge.hpp"
#include "../Utility/Point.hpp"
#include "../Utility/Color.hpp"

class Shape {

 public:
  virtual ~Shape() = default;
  Shape() = default;
  using Size = Point;

  virtual void render(RendererBridge& renderer) const = 0;
  virtual bool containsPoint(const Point& point) const = 0;
  void makeInvisible();
  void makeVisible();
  void setPosition(const Point& pos);
  Point getPosition() const;
  void setColor(const Color& clr);
  Color getColor() const;
  void setSize(const Size& sz);
  Size getSize() const;
 protected:
  Point position;
  bool visible = true;
  Color color;
  Size size;
};

//==============================================================================

#endif //__SHAPE_HPP__