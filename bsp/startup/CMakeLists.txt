add_library(startup startup_mkl25z4.c)

set_target_properties(startup PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(startup PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})