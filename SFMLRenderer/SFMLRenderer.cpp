#include "SFMLRenderer.hpp"
/*
void SFMLRenderer::renderWindow(const Window* window) {

}
*/
void SFMLRenderer::renderRectangle(const Point& pos, const Point& size, const Color& color) const {

}

void SFMLRenderer::renderRootWindow(const Window* rootWindow) {
  for (auto& wind : rootWindow->subwindows)
    wind->render(*this);

  rootWin.display();
}

SFMLRenderer::SFMLRenderer(const Window* rootWindow, const char* appName) : 
  rootWin(sf::RenderWindow(sf::VideoMode(rootWindow->getShape().getSize().x,
                                         rootWindow->getShape().getSize().y),
                                         appName)) {}
