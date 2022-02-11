#ifndef __SFML_RENDERER_HPP__
#define __SFML_RENDERER_HPP__

//==============================================================================

#include "../Renderer/RendererBridge.hpp"

#include <SFML/Graphics.hpp>

class SFMLRenderer : public RendererBridge {
 public:
  //~SFMLRenderer() = default;
  static SFMLRenderer& getRenderer(const Point& size, const char* appName);
 // void renderWindow(const Window* window) override;
  void renderRectangle(const Point& pos, const Point& size, const Color& color) override;
  void renderResult() override;
  void clear() override;

 private:
  static SFMLRenderer* renderer;
  sf::RenderWindow rootWin;
  SFMLRenderer(const Point& size, const char* appName);
  SFMLRenderer(const SFMLRenderer&) = delete;
};

//==============================================================================

#endif //__SFML_RENDERER_HPP__