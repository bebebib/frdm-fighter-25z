add_library(drivers .)

set_target_properties(drivers PROPERTIES LINKER_LANGUAGE C)

target_include_directories(drivers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})