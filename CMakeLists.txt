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

# Below flags are super ugly.... need to fix them!!!!

# Set some compiler flags for fun/!!! These gotta be decoded somehow....
set(COMPILER_OPTIONS "-DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DDEBUG -DPRINTF_FLOAT_ENABLE=0 -DSCANF_FLOAT_ENABLE=0 -DPRINTF_ADVANCED_ENABLE=0 -DSCANF_ADVANCED_ENABLE=0 -DFRDM_KL25Z -DFREEDOM -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -O0 -fno-common -g -Wall -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -mcpu=cortex-m0plus -mthumb -fstack-usage")

set(CMAKE_C_FLAGS ${COMPILER_OPTIONS} )
set(CMAKE_CXX_FLAGS ${COMPILER_OPTIONS})

message("HEERR ${CMAKE_SOURCE_DIR}")

set(CMAKE_EXE_LINKER_FLAGS "-Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m0plus -mthumb --specs=nosys.specs -Xlinker -T ${CMAKE_SOURCE_DIR}/linker/autogen_linker.ld")

# Add our BSP
add_subdirectory(bsp)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER "usr/bin/arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/arm-none-eabi-g++")

# Our executable!
add_executable(main.out main.cpp)

target_link_libraries (main.out PUBLIC board startup)