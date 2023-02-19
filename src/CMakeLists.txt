#####################################################################
# simple AVR executable
#####################################################################
add_avr_executable(${PROJECT_NAME}
   main.cpp
   something.cpp
   "${PROJECT_SOURCE_DIR}/include/lcd.c"
   )

avr_target_include_directories(${PROJECT_NAME}
   PUBLIC
      ${PROJECT_SOURCE_DIR}/src
      ${PROJECT_SOURCE_DIR}/include
)
