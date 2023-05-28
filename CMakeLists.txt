cmake_minimum_required(VERSION 2.8.12)



if(NOT DEFINED AVR)
   set(AVR 1)
endif(NOT DEFINED AVR)



set(AVR_MCU "atmega328")
set(MCU_SPEED "8000000UL")

set(AVR_PROGRAMMER usbasp)
set(AVR_UPLOADTOOL avrdude)
set(AVR_UPLOADTOOL_BAUDRATE 19200)

# Awesome fuse helper gui: https://www.engbedded.com/fusecalc/
set(AVR_H_FUSE 0xda)
set(AVR_L_FUSE 0xe2)
set(AVR_E_FUSE 0xfd)

message(STATUS "AVR is set to: ${AVR}")



# set(AVR_ROOT "/usr/lib")
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/cmake/gcc-avr.toolchain.cmake")
set(PROJECT_NAME swing)
project(${PROJECT_NAME})

##########################################################################
# export compile flags for clang language server
##########################################################################
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

message(STATUS "Current uploadtool is: ${AVR_UPLOADTOOL}")
message(STATUS "Current programmer is: ${AVR_PROGRAMMER}")
message(STATUS "Current upload port is: ${AVR_UPLOADTOOL_PORT}")
message(STATUS "Current uploadtool options are: ${AVR_UPLOADTOOL_OPTIONS}")
message(STATUS "Current MCU is set to: ${AVR_MCU}")
message(STATUS "Current H_FUSE is set to: ${AVR_H_FUSE}")
message(STATUS "Current L_FUSE is set to: ${AVR_L_FUSE}")
message(STATUS "Current E_FUSE is set to: ${AVR_E_FUSE}")

if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

##########################################################################
# set compiler options for build types
##########################################################################
if(CMAKE_BUILD_TYPE MATCHES Release)
   set(CMAKE_C_FLAGS_RELEASE "-Os")
   set(CMAKE_CXX_FLAGS_RELEASE "-Os")
endif(CMAKE_BUILD_TYPE MATCHES Release)

if(CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
   set(CMAKE_C_FLAGS_RELWITHDEBINFO "-Os -save-temps -g -gdwarf-3 -gstrict-dwarf")
   set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-Os -save-temps -g -gdwarf-3 -gstrict-dwarf")
endif(CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)

if(CMAKE_BUILD_TYPE MATCHES Debug)
   set(CMAKE_C_FLAGS_DEBUG "-O0 -save-temps -g -gdwarf-3 -gstrict-dwarf")
   set(CMAKE_CXX_FLAGS_DEBUG "-O0 -save-temps -g -gdwarf-3 -gstrict-dwarf")
endif(CMAKE_BUILD_TYPE MATCHES Debug)


add_definitions("-DF_CPU=${MCU_SPEED}")
add_definitions("-fpack-struct")
add_definitions("-fshort-enums")
add_definitions("-Wall")
add_definitions("-Werror")
add_definitions("-Wunused-variable")
add_definitions("-pedantic")
add_definitions("-pedantic-errors")
add_definitions("-funsigned-char")
add_definitions("-funsigned-bitfields")
add_definitions("-ffunction-sections")
add_definitions("-c")

# message(STATUS "AVR is se2222222t to: ${AVR}")

##########################################################################
# include search paths
##########################################################################
# include_directories("${PROJECT_SOURCE_DIR}")

##########################################################################
# building library and application in their subdirectories
##########################################################################
# set(TARGET_LIBRARY swing_static)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")

# message(STATUS "AVR is set to: ${AVR}")
