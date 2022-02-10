#include <cstdio>

#include "Engine/Engine.hpp"
#include "SFMLRenderer/SFMLRenderer.hpp"
#include "Shape/Rectangle.hpp"

int main() {
  RendererBridge& renderer = SFMLRenderer::getRenderer(Point{800, 400}, "Deadwindow");
  Window rootWindow;
  rootWindow.setShape(new Rectangle(Point{0, 0}, Point{800, 400}));
  Engine::init(renderer, rootWindow);

  Engine::start();
  return 0;
}