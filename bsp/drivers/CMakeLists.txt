add_library(drivers 
    fsl_clock.c
    fsl_common.c
    fsl_flash.c
    fsl_gpio.c
    fsl_lpsci.c 
    fsl_smc.c
    fsl_uart.c)

set_target_properties(drivers PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(drivers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries (drivers PUBLIC CMSIS utils)