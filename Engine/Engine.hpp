#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__

//==============================================================================

#include "../Window/Window.hpp"

class Engine {
 public:
  static void start();
  static void init();
  static void destroy();
 private:
  Engine();

  static Window rootWindow;
};

//==============================================================================

#endif //__ENGINE_HPP__