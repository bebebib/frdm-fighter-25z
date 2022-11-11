add_library(CMSIS .)

set_target_properties(CMSIS PROPERTIES LINKER_LANGUAGE C)

target_include_directories(CMSIS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})