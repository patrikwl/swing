#####################################################################
# simple AVR executable
#####################################################################

set(target ${PROJECT_NAME})

add_avr_executable(${target}
   main.cpp
   SpiAdapter.cpp
   SpiHandler.cpp
   RegisterAccessor.cpp
   "${PROJECT_SOURCE_DIR}/include/lcd.c"
   )

avr_target_include_directories(${target}
   PUBLIC
      ${CMAKE_SOURCE_DIR}
      ${PROJECT_SOURCE_DIR}/include
    SYSTEM 
      /usr/lib/avr/include/
)

include_directories(
   PUBLIC
   ${PROJECT_SOURCE_DIR}
   ${PROJECT_SOURCE_DIR}/include
   SYSTEM
      /usr/lib/avr/include/
)
# set(CMAKE_VERBOSE_MAKEFILE ON)
