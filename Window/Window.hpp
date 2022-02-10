#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

//==============================================================================

#include "../Shape/Shape.hpp"
#include <list>

class Window {
 public:
  virtual ~Window() = default;

  void render(RendererBridge& renderer) const;
  void addSubwindow(Window* wd);
  std::list<Window*> subwindows;
  const Shape& getShape() const;
  void setShape(Shape* shp);
 protected:
  Shape* shape = nullptr;

  Window* parentWd = nullptr;
};

//==============================================================================

#endif //__WINDOW_HPP__