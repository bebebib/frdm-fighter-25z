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

project(frdm_cli_game)

# prevents test compile errors
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER "usr/bin/arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/arm-none-eabi-g++")

# Nosys TODO: get rid of this
set(CMAKE_EXE_LINKER_FLAGS "--specs=nosys.specs" CACHE INTERNAL "")

# Set some compiler flags for fun/!!! These gotta be decoded somehow....
set(COMPILER_OPTIONS "-DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DDEBUG -DPRINTF_FLOAT_ENABLE=0 -DSCANF_FLOAT_ENABLE=0 -DPRINTF_ADVANCED_ENABLE=0 -DSCANF_ADVANCED_ENABLE=0 -DFRDM_KL25Z -DFREEDOM -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -D__REDLIB__ -O0 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage")

set(CMAKE_C_FLAGS ${COMPILER_OPTIONS})
set(CMAKE_CXX_FLAGS ${COMPILER_OPTIONS})

# Add our BSP
add_subdirectory(bsp)

# Our executable!
add_executable(main.out main.cpp)

target_link_libraries (main.out LINK_PUBLIC CMSIS utils board)