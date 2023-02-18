cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME MY_TESTS)
project(${PROJECT_NAME})

set(HDRS
  # "${CMAKE_SOURCE_DIR}/../include/lcd.h"
  "${CMAKE_SOURCE_DIR}/../src/something.h"
)

set(SRCS
  # "${CMAKE_SOURCE_DIR}/../include/lcd.c"
  "${CMAKE_SOURCE_DIR}/../src/something.cpp"
)

set(TARGET_LINUX_LIB swing_linux_static)


add_library(${TARGET_LINUX_LIB} STATIC ${SRCS} ${HDRS})
target_include_directories(${TARGET_LINUX_LIB}
  PRIVATE
    "/usr/include"
    "/usr/lib/avr/include"
)



add_executable(${PROJECT_NAME}
  main.cpp
  test_template.cpp

)

find_package(GTest REQUIRED)

target_include_directories(${PROJECT_NAME}
    PRIVATE
      ${CMAKE_SOURCE_DIR}
      "${CMAKE_SOURCE_DIR}/../src/"
    PUBLIC
      ${GTEST_INCLUDE_DIR}
      "/usr/include"
      # "/usr/include/c++/11/"
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
