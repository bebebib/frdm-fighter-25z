add_library(libfcn 
    syscalls.c)

set_target_properties(libfcn PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(libfcn PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})