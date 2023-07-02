cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME MY_TESTS)
project(${PROJECT_NAME})

add_compile_definitions(useSimuLogger)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=x86-64 -mtune=generic")

set(HDRS
  # "${CMAKE_SOURCE_DIR}/../include/lcd.h"
  "${CMAKE_SOURCE_DIR}/../src/SpiAdapter.h"
  "${CMAKE_SOURCE_DIR}/../src/SpiHandler.h"
  "${CMAKE_SOURCE_DIR}/../src/RegisterManager.h"
  "${CMAKE_SOURCE_DIR}/../src/UartManager.h"
  # "${CMAKE_SOURCE_DIR}/../src/ConfigGetter.h"
  "${CMAKE_SOURCE_DIR}/../src/AccelerometerHandler.h"
  # "${CMAKE_SOURCE_DIR}/../src/HardwareSetup.h"
  # "/usr/lib/avr/include/avr/iom328p.h"
  "${CMAKE_SOURCE_DIR}/../src/Adxl345ConfigGetter.h"
)

set(SRCS
  # "${CMAKE_SOURCE_DIR}/../include/lcd.c"
  "${CMAKE_SOURCE_DIR}/../src/SpiAdapter.cpp"
  "${CMAKE_SOURCE_DIR}/../src/SpiHandler.cpp"
  "${CMAKE_SOURCE_DIR}/../src/RegisterManager.cpp"
  "${CMAKE_SOURCE_DIR}/../src/UartManager.cpp"
  # "${CMAKE_SOURCE_DIR}/../src/ConfigGetter.cpp"
  "${CMAKE_SOURCE_DIR}/../src/AccelerometerHandler.cpp"
  "${CMAKE_SOURCE_DIR}/../src/Adxl345ConfigGetter.cpp"
)

set(TARGET_LINUX_LIB swing_linux_static)


add_library(${TARGET_LINUX_LIB} STATIC ${SRCS} ${HDRS})

target_include_directories(${TARGET_LINUX_LIB}
  PRIVATE
    /usr/lib/avr/include
    /usr/lib/avr/include/avr/x86_64-linux-gnu/include

)
include_directories(
  SYSTEM
    /usr/include/c++/9/
)

add_executable(${PROJECT_NAME}
  main.cpp
  test_SpiHandler.cpp
  test_RegisterManager.cpp
  test_UartManager.cpp
  test_AccelerometerHandler.cpp
  test_Adxl345ConfigGetter.cpp
  test_SpiAdapter.cpp

)

find_package(GTest REQUIRED)

target_include_directories(${PROJECT_NAME}
    PRIVATE
      ${CMAKE_SOURCE_DIR}
      "${CMAKE_SOURCE_DIR}/../src/"
    PUBLIC
      ${GTEST_INCLUDE_DIR}
      /usr/include
      /usr/include/c++/11/
)

# add_library(swing_static STATIC IMPORTED)
# set_target_properties(swing_static PROPERTIES IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../build/src/libswing_static_linux.a")

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    GTest::gtest
    ${TARGET_LINUX_LIB}
)


set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../build/src)


add_test(
  NAME ${PROJECT_NAME}
  COMMAND ${PROJECT_NAME}
)
