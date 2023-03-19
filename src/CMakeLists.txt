#####################################################################
# simple AVR executable
#####################################################################
add_avr_executable(${PROJECT_NAME}
   main.cpp
   something.cpp
   EventLoop.cpp
   "${PROJECT_SOURCE_DIR}/external-libs/lcd.c"
   # ${PROJECT_SOURCE_DIR}/external-libs/StandardCplusplus/new_handler.cpp
   # ${PROJECT_SOURCE_DIR}/external-libs/StandardCplusplus/new_opnt.cpp
   # ${PROJECT_SOURCE_DIR}/external-libs/StandardCplusplus/new_opnt.cpp
   # ${PROJECT_SOURCE_DIR}/external-libs/StandardCplusplus/new_opv.cpp
   # ${PROJECT_SOURCE_DIR}/external-libs/StandardCplusplus/new_opvnt.cpp
   ${PROJECT_SOURCE_DIR}/external-libs/StandardCplusplus/func_exception.cpp
   )

avr_target_include_directories(${PROJECT_NAME}
   PUBLIC
      ${PROJECT_SOURCE_DIR}/src
      ${PROJECT_SOURCE_DIR}/external-libs
      ${PROJECT_SOURCE_DIR}/external-libs/StandardCplusplus
)

# find_package(StandardCplusplus REQUIRED)
# set(CPP_LIB CppStatic)

# add_avr_library(${CPP_LIB} StandardCplusplus)

# avr_target_link_libraries(${PROJECT_NAME}
#    PRIVATE
#       ${CPP_LIB}
# )

# target_link_libraries(${PROJECT_NAME}
#   PRIVATE
#     GTest::gtest
#     ${TARGET_LINUX_LIB}
# )


include_directories(
   include
   SYSTEM
      /usr/lib/avr/include
)

# set(CMAKE_VERBOSE_MAKEFILE ON)
