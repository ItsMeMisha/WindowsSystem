add_library(RendererBridge)
set_target_properties(RendererBridge PROPERTIES LINKER_LANGUAGE CXX)
set(INCDIR ${PROJECT_SOURCE_DIR}/Renderer)

target_sources(RendererBridge
  PUBLIC
    ${INCDIR}/RendererBridge.hpp)

target_link_libraries(RendererBridge PUBLIC Utility)