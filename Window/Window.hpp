#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

//==============================================================================

#include "../Shape/Shape.hpp"
#include "../Events/Event.hpp"
#include <list>

class Window {
 public:
  virtual ~Window() = default;

  void render(RendererBridge& renderer);
  void addSubwindow(Window* wd);
  const Shape& getShape() const;
  void setShape(Shape* shp);
  bool isOpen() const;
  virtual void handleEvent(const Event* event);

  std::list<Window*> subwindows;
 protected:
  Shape* shape = nullptr;

  Window* parentWd = nullptr;

  bool isOpenFlag = true;
};

//==============================================================================

#endif //__WINDOW_HPP__