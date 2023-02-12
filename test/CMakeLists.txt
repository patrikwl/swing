cmake_minimum_required(VERSION 3.22)

message(STATUS "Building tests -------------- ${CMAKE_SOURCE_DIR} and ........... ${CMAKE_CURRENT_SOURCE_SIR}")

set(PROJECT_NAME MY_TESTS)
project(${PROJECT_NAME})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}
  main.cpp
  test_template.cpp
  /workspaces/swing/src/something.cpp
  /workspaces/swing/src/something.h

)

include_directories(/usr/include /workspaces/swing/src)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_SOURCE_DIR}
        /workspaces/swing/src
        ${GTEST_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  ${GTEST_LIBRARIES}
)


add_test(
  NAME ${PROJECT_NAME}
  COMMAND ${PROJECT_NAME}
)
#gtest_discover_tests(hello_test)
