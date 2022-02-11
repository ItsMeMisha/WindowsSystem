#ifndef __RENDERER_BRIDGE_HPP__
#define __RENDERER_BRIDGE_HPP__

//==============================================================================

//#include "../Window/Window.hpp"
#include "../Utility/Point.hpp"
#include "../Utility/Color.hpp"

class RendererBridge {
 public:
  virtual ~RendererBridge() = default;
  virtual void renderResult() = 0;
  virtual void clear() = 0;
 // virtual void renderWindow(const Window* window);
  //static RendererBridge* init(); 

  virtual void renderRectangle(const Point& pos, const Point& size, const Color& color) = 0;
 protected:
 

//  Window* rootWindow;
};

//==============================================================================

#endif //__RENDERER_BRIDGE_HPP__