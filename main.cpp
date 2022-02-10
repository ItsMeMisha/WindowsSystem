#include <cstdio>

#include "Engine/Engine.hpp"
#include "SFMLRenderer/SFMLRenderer.hpp"
#include "Shape/Rectangle.hpp"

int main() {
  RendererBridge& renderer = SFMLRenderer::getRenderer(Point{800, 400}, "Deadwindow");
  Window rootWindow;
  rootWindow.setShape(new Rectangle(Point{200, 100}, Point{400, 200}, Color(255, 255, 255)));

  Engine::init(renderer, rootWindow);

  Engine::start();

  Engine::destroy();
  return 0;
}