add_library(Shape)
set(INCDIR ${PROJECT_SOURCE_DIR}/Shape)

target_sources(Shape
  PUBLIC
    ${INCDIR}/Shape.hpp
    ${INCDIR}/Rectangle.hpp
  PRIVATE
    Shape.cpp
    Rectangle.cpp
)

target_link_libraries(Shape PUBLIC Utility RendererBridge)