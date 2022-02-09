add_library(Utility)
set_target_properties(Utility PROPERTIES LINKER_LANGUAGE CXX)
set(INCDIR ${PROJECT_SOURCE_DIR}/Utility)

target_sources(Utility
  PUBLIC
    ${INCDIR}/Color.hpp
    ${INCDIR}/Point.hpp)