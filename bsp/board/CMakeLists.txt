add_library(board clock_config.c pin_mux.c board.c)

set_target_properties(board PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(board PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries (board PUBLIC drivers utils)