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
  virtual void start();
  virtual void stop();

  virtual void renderLine(const Point& start, const Point& finish);
  virtual void renderRectangle(const Point& pos, const Vector2d& size, const Color& color);
  virtual void renderBox(const Point& pos, const Vector2d& size);
  virtual void renderText(const std::string& text, const Vector2d& pos, size_t size);
  virtual void renderTexture(const Point& pos, const char* image_name);    
  virtual void renderTexture(const Point& pos, const sf::Texture& sf_texture);
  virtual void renderBitmap(const vector<uint8_t>& image, const Point& pos, const Vector2d& size);

  virtual void pushTarget(const Vector2d& size, const Vector2d& offset);
  virtual void popTargetToDisplay(const Point& pos);
 protected:
 
 

//  Window* rootWindow;
};

//==============================================================================

#endif //__RENDERER_BRIDGE_HPP__