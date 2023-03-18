#####################################################################
# simple AVR executable
#####################################################################
add_avr_executable(${PROJECT_NAME}
   main.cpp
   something.cpp
   EventLoop.cpp
   "${PROJECT_SOURCE_DIR}/external-libs/lcd.c"
   )

avr_target_include_directories(${PROJECT_NAME}
   PUBLIC
      ${PROJECT_SOURCE_DIR}/src
      ${PROJECT_SOURCE_DIR}/external-libs
)

include_directories(
   include
   SYSTEM
      /usr/lib/avr/include
)

# set(CMAKE_VERBOSE_MAKEFILE ON)
