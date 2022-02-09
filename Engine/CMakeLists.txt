add_library(Engine)
set_target_properties(Engine PROPERTIES LINKER_LANGUAGE CXX)
set(INCDIR ${PROJECT_SOURCE_DIR}/Engine)

target_sources(Engine
  PUBLIC
    ${INCDIR}/Engine.hpp)

target_link_libraries(Engine PUBLIC Window)