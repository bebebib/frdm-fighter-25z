cmake_minimum_required (VERSION 3.16.3)

set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

# Pretty...
message("")
message("    >=>    >=>       >=>          >===>                                        >=>")
message(" >=>   >=> >=>       >=>        >>    >=>                                      >=>")
message(">=>        >=>       >=>       >=>            >=> >=>  >===>>=>>==>    >==>    >=>")
message(">=>        >=>       >=>       >=>          >=>   >=>   >=>  >>  >=> >>   >=>  >> ")
message(">=>        >=>       >=>       >=>   >===> >=>    >=>   >=>  >>  >=> >>===>>=> >> ")
message(">=>   >=> >=>       >=>        >=>    >>   >=>   >=>   >=>  >>  >=> >>           ")
message("   >===>   >=======> >=>         >====>      >==>>>==> >==>  >>  >=>  >====>   >=>")
message("")

project (frdm_cli_game)

# prevents test compile errors
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER "usr/bin/arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/arm-none-eabi-g++")

# Nosys TODO: get rid of this
set(CMAKE_EXE_LINKER_FLAGS "--specs=nosys.specs" CACHE INTERNAL "")

# Our executable!
add_executable(main.out main.cpp)