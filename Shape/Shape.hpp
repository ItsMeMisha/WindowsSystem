#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

//==============================================================================

#include "../Renderer/RendererBridge.hpp"

#include <utility>
using Position = std::pair<std::size_t, std::size_t>;

class Shape {

 public:
  virtual void render(const RendererBridge& renderer) const;
 protected:
  Position pos;
};

//==============================================================================

#endif //__SHAPE_HPP__