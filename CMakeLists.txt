cmake_minimum_required (VERSION 3.10.2)

# Skip compiler tests...
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

# Pretty...

message(" ________  _______     ______   ____    ____  ")
message("|_   __  ||_   __ \\   |_   _ `.|_   \\ \ /   _| ")
message("  | |_ \\_|  | |__) |    | | `. \\ |   \\/   |   ")
message("  |  _|     |  __ /     | |  | | | |\\  /| |   ")
message(" _| |_     _| |  \\ \\_  _| |_.' /_| |_\\/_| |_  ")
message("|_____|   |____| |___||______.'|_____||_____| ")
                                              
project(frdm_cli_game)

# Generic ARM build
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Set our compiler (generic location)
set(CMAKE_C_COMPILER "/usr/bin/arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/arm-none-eabi-g++")

# Include
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/ArmCompileLink.cmake)

# Add our subdirs
add_subdirectory(bsp)
add_subdirectory(libfcn)

# Our executable!
add_executable(main.out 
                src/main.cpp
                src/clock.cpp
                src/clock.h
                src/led.cpp
                src/led.h)

# Link the BSP to our main
target_link_libraries (main.out PUBLIC board startup libfcn)