add_library(board .)

set_target_properties(board PROPERTIES LINKER_LANGUAGE C)

target_include_directories(board PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})