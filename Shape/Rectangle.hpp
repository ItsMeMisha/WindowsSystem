#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

//==============================================================================

#include "Shape.hpp"

class Rectangle : public Shape {
  public:
    void render(const RendererBridge& renderer) const override;
    bool containsPoint(const Point& point) const override;
    void setSize(const Size& sz);
    Size getSize() const;
  protected:
    Size size;
};

//==============================================================================

#endif //__RECTANGLE_HPP__