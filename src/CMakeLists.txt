set(AVR_MCU "atmega328p")
set(MCU_SPEED "4000000UL")

set(AVR_PROGRAMMER usbasp)
set(AVR_UPLOADTOOL avrdude)
set(AVR_UPLOADTOOL_BAUDRATE 9600)

# Awesome fuse helper gui: https://www.engbedded.com/fusecalc/
set(AVR_H_FUSE 0xd9)
set(AVR_L_FUSE 0xc3)

message(STATUS "AVR is set to: ${AVR}")


#####################################################################
# simple AVR executable
#####################################################################
add_avr_executable(${PROJECT_NAME}
   main.cpp
   )



#####################################################################
# libraries to link to
#####################################################################

set(HDRS
   something.h
)

set(SRC
   something.cpp
)


add_avr_library(${TARGET_LIBRARY} STATIC ${SRC} ${HDRS})

avr_target_include_directories(${TARGET_LIBRARY} PUBLIC ${PROJECT_SOURCE_DIR}/src)

target_sources(${PROJECT_NAME} PRIVATE ${SRC})
