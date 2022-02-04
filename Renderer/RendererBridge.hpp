#ifndef __RENDERER_BRIDGE_HPP__
#define __RENDERER_BRIDGE_HPP__

//==============================================================================

#include "../Window/Window.hpp"
#include "../Utility/Point.hpp"
#include "../Utility/Color.hpp"

class RendererBridge {
 public:
  virtual void renderWindow(const Window* window);
  static RendererBridge* init(); 

  virtual void renderRectangle(const Point& pos, const Point& size, const Color& color) const;
 protected:

 private:
  RendererBridge();
};

//==============================================================================

#endif //__RENDERER_BRIDGE_HPP__