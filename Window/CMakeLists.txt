add_library(Window)
set(INCDIR ${PROJECT_SOURCE_DIR}/Window)

target_sources(Window
  PUBLIC
    ${INCDIR}/Window.hpp
  PRIVATE
    Window.cpp)

target_link_libraries(Window PUBLIC Utility Shape RendererBridge)