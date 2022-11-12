add_library(utils fsl_debug_console.c)

set_target_properties(utils PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries (utils PUBLIC drivers)