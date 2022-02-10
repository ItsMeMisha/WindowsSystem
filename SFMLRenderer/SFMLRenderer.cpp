#include "SFMLRenderer.hpp"

SFMLRenderer* SFMLRenderer::renderer = nullptr;

SFMLRenderer& SFMLRenderer::getRenderer(const Point& size, const char* appName) {
  if (renderer == nullptr)
    renderer = new SFMLRenderer(size, appName);
  return *renderer;
}

/*
void SFMLRenderer::renderWindow(const Window* window) {

}
*/
void SFMLRenderer::renderRectangle(const Point& pos, const Point& size, const Color& color) {
  sf::RectangleShape rect;
  rect.setPosition(pos.x, pos.y);
  rect.setSize({(float)size.x, (float)size.y});
  rect.setFillColor({color.r, color.g, color.b});
  rootWin.draw(rect);
}

void SFMLRenderer::renderResult() {
  rootWin.display();
}

SFMLRenderer::SFMLRenderer(const Point& size, const char* appName) : 
  rootWin(sf::RenderWindow(sf::VideoMode(size.x, size.y), appName)) {}
