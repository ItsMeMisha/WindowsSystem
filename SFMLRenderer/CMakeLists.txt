add_library(SFMLRenderer)
set(INCDIR ${PROJECT_SOURCE_DIR}/SFMLRenderer)

target_sources(SFMLRenderer
  PUBLIC
    ${INCDIR}/SFMLRenderer.hpp
  PRIVATE
    SFMLRenderer.cpp)

target_link_libraries(SFMLRenderer PUBLIC RendererBridge sfml-graphics)