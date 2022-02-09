#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

//==============================================================================

#include "../Shape/Shape.hpp"
#include <list>

class Window {
 public:
  void render(const RendererBridge& renderer) const;
  void addSubwindow(Window* wd);
  std::list<Window*> subwindows;
  const Shape& getShape() const;
 protected:
  Shape* shape = nullptr;

  Window* parentWd = nullptr;
};

//==============================================================================

#endif //__WINDOW_HPP__