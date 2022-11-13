
# Symbols for frdm kl25z
set(PROJECT_SYMBOLS "-DCPU_MKL25Z128VLK4 \
-DCPU_MKL25Z128VLK4_cm0plus \
-DDEBUG \
-DPRINTF_FLOAT_ENABLE=0 \
-DSCANF_FLOAT_ENABLE=0 \
-DPRINTF_ADVANCED_ENABLE=0 \
-DSCANF_ADVANCED_ENABLE=0 \
-DFRDM_KL25Z -DFREEDOM \
-DSDK_DEBUGCONSOLE=1 \
-DCR_INTEGER_PRINTF \
-D__MCUXPRESSO \
-D__USE_CMSIS ")

# No optimization
set(OPTIMIZATION_LEVEL "-O0")

# Warnings and misc settings
set(WARNING_FLAGS "-fno-common -Wall -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fstack-usage")

# Compiler options for all code
set(COMPILER_OPTIONS "${PROJECT_SYMBOLS} ${OPTIMIZATION_LEVEL} ${WARNING_FLAGS} -g -mcpu=cortex-m0plus -mthumb")

# Our linker script
set(PROJECT_LINKER_SCRIPT "-Xlinker -T ${CMAKE_SOURCE_DIR}/linker/autogen_linker.ld")

# Linker flags
set(CMAKE_EXE_LINKER_FLAGS "--specs=nosys.specs -Xlinker --gc-sections  ${PROJECT_LINKER_SCRIPT} ${COMPILER_OPTIONS}")

set(CMAKE_C_FLAGS ${COMPILER_OPTIONS} )
set(CMAKE_CXX_FLAGS ${COMPILER_OPTIONS})