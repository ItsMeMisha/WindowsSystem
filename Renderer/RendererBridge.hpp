#ifndef __RENDERER_BRIDGE_HPP__
#define __RENDERER_BRIDGE_HPP__

//==============================================================================

#include "../Window/Window.hpp"

class RendererBridge {
 public:
  virtual void renderWindow(const Window* window);
  static RendererBridge* init(); 

 protected:

 private:
  RendererBridge();
};

//==============================================================================

#endif //__RENDERER_BRIDGE_HPP__