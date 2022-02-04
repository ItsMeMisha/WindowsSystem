#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

//==============================================================================

#include "../Renderer/RendererBridge.hpp"
#include "../Utility/Point.hpp"

class Shape {

 public:
  virtual void render(const RendererBridge& renderer) const;
  virtual bool containsPoint(const Point& point) const;
  void setPosition(const Point& position);
  Point getPosition() const;
 protected:
  Point position;
  bool visible = true;
};

//==============================================================================

#endif //__SHAPE_HPP__