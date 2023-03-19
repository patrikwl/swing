cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME MY_TESTS)
project(${PROJECT_NAME})

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=x86-64 -mtune=generic")
set(CMAKE_BUILD_TYPE Debug)

set(HDRS
  # "${CMAKE_SOURCE_DIR}/../include/lcd.h"
  "${CMAKE_SOURCE_DIR}/../src/something.h"
  "${CMAKE_SOURCE_DIR}/../src/EventLoop.h"
)

set(SRCS
  # "${CMAKE_SOURCE_DIR}/../include/lcd.c"
  "${CMAKE_SOURCE_DIR}/../src/something.cpp"
  "${CMAKE_SOURCE_DIR}/../src/EventLoop.cpp"
)

set(TARGET_LINUX_LIB swing_linux_static)


add_library(${TARGET_LINUX_LIB} STATIC ${SRCS} ${HDRS})

target_include_directories(${TARGET_LINUX_LIB}
  PRIVATE
    /usr/lib/avr/include
)

include_directories(
  SYSTEM
    /usr/include/c++/11/
    ${CMAKE_SOURCE_DIR}/../external-libs/StandardCplusplus
)

add_executable(${PROJECT_NAME}
  main.cpp
  test_template.cpp
  test_EventLoop.cpp
  # ${CMAKE_SOURCE_DIR}/../external-libs/StandardCplusplus/func_exception.cpp
)

find_package(GTest REQUIRED)

target_include_directories(${PROJECT_NAME}
    PRIVATE
      ${CMAKE_SOURCE_DIR}
      "${CMAKE_SOURCE_DIR}/../src/"
    PUBLIC
      ${GTEST_INCLUDE_DIR}
      /usr/lib/avr/include
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
