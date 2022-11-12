add_library(CMSIS system_MKL25Z4.c)

set_target_properties(CMSIS PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(CMSIS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})