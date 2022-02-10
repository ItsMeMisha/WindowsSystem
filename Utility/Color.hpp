#ifndef __COLOR_HPP__
#define __COLOR_HPP__

//==============================================================================

#include <cstdint>

struct Color {
  Color(const uint8_t r, const uint8_t g, const uint8_t b) :
    r(r), g(g), b(b) {}

  Color(const Color& clr) = default;
  Color() = default;
  uint8_t r = 0;
  uint8_t g = 0;
  uint8_t b = 0;
};



//==============================================================================

#endif //__COLOR_HPP__