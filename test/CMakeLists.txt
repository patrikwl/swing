message(STATUS "Building tests")
set(MY_TESTS test_swing)

add_executable(${MY_TESTS}
  main.cpp
  test_template.cpp
)

target_include_directories(${MY_TESTS}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
        "${CMAKE_CURRENT_SOURCE_SIR}"

)

target_link_libraries(${MY_TESTS} PRIVATE ${TARGET_LIBRARY} gtest)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bins)

include(GoogleTest)
#gtest_discover_tests(hello_test)
