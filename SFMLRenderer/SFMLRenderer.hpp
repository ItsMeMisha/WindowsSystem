#ifndef __SFML_RENDERER_HPP__
#define __SFML_RENDERER_HPP__

//==============================================================================

#include "../Renderer/RendererBridge.hpp"

#include <SFML/Graphics.hpp>

class SFMLRenderer : public RendererBridge {
 public:
 // void renderWindow(const Window* window) override;
  void renderRectangle(const Point& pos, const Point& size, const Color& color) const override;
  void renderRootWindow(const Window* rootWindow) override;

 private:
  sf::RenderWindow rootWin;
  SFMLRenderer(const Window* rootWindow, const char* appName);
};

//==============================================================================

#endif //__SFML_RENDERER_HPP__