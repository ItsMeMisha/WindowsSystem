#ifndef __SFML_RENDERER_HPP__
#define __SFML_RENDERER_HPP__

//==============================================================================

#include "../Renderer/RendererBridge.hpp"

#include <SFML/Graphics.hpp>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

class SFMLRenderer : public RendererBridge {
 public:
  ~SFMLRenderer() = default;
  static SFMLRenderer& getRenderer(const Point& size, const char* appName);
 // void renderWindow(const Window* window) override;
  void renderResult() override;
  void clear() override;

  void start() override;
  void stop() override;
  sf::RenderWindow* getRootWindow();
  bool isRunning();

  void renderLine(const Point& start, const Point& finish) override;
  void renderRectangle(const Point& pos, const Vector2d& size, const Color& color) override;
  void renderBox(const Point& pos, const Vector2d& size) override;
  void renderText(const std::string& text, const Vector2d& pos, size_t size) override;
  void renderTexture(const Point& pos, const char* image_name) override;
  void renderTexture(const Point& pos, const sf::Texture& sf_texture) override;
  void renderBitmap(const vector<uint8_t>& image, const Point& pos, const Vector2d& size) override;

  void pushTarget(const Vector2d& size, const Vector2d& offset) override;
  void popTargetToDisplay(const Point& pos) override;


 private:
  static SFMLRenderer* renderer;
  sf::RenderWindow rootWin;
  SFMLRenderer(const Point& size, const char* appName);
  SFMLRenderer(const SFMLRenderer&) = delete;
  SFMLRenderer() = default;
  stack<sf::RenderTarget*> targetsToRender;
  stack<Vector2d> renderingOffsets;

  sf::Vector2f to_sfVect2f(const Vector2d& vect);
  Vector2d eff_pos(const Point& pos);
};

//==============================================================================

#endif //__SFML_RENDERER_HPP__