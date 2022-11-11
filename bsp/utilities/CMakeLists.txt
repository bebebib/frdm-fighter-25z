add_library(utils .)

set_target_properties(utils PROPERTIES LINKER_LANGUAGE C)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries (utils LINK_PUBLIC drivers)