


#####################################################################
# simple AVR executable
#####################################################################
add_avr_executable(${PROJECT_NAME}
   main.cpp
   something.cpp

)

avr_target_include_directories(${PROJECT_NAME}
   PRIVATE
      ${PROJECT_SOURCE_DIR}/src
      ${PROJECT_SOURCE_DIR}/include

)



#####################################################################
# libraries to link to
#####################################################################

# set(HDRS
#    something.h
# )

# set(SRC
#    main.cpp
#    something.cpp
# )

# add_avr_library(${TARGET_LIBRARY} STATIC ${SRC} ${HDRS})

# target_include_directories(${TARGET_LIBRARY}
#    PUBLIC
#       ${PROJECT_SOURCE_DIR}/src
# )

# target_link_libraries(${TARGET_LIBRARY}
#    PUBLIC
#       ${PROJECT_SOURCE_DIR}/src
# )

target_sources(${PROJECT_NAME} PRIVATE ${SRC})

avr_target_include_directories(${PROJECT_NAME}
   PUBLIC
      ${PROJECT_SOURCE_DIR}/src
)


# avr_target_link_libraries(${PROJECT_NAME} PRIVATE ${TARGET_LIBRARY})
#target_link_libraries(${PROJECT_NAME}  PRIVATE ${TARGET_LIBRARY} )
