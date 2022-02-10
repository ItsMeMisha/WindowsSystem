#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

//==============================================================================

#include "Shape.hpp"

class Rectangle : public Shape {
  public:
    void render(RendererBridge& renderer) const override;
    bool containsPoint(const Point& point) const override;

    Rectangle(const Point& pos, const Size& sz);
    Rectangle() = default;
    ~Rectangle() = default;
  protected:
};

//==============================================================================

#endif //__RECTANGLE_HPP__