cmake_minimum_required(VERSION 2.8)
project(consumer C)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

execute_process(COMMAND toolset  ${CMAKE_CURRENT_LIST_DIR}/tool-set.c
                OUTPUT_VARIABLE result
                ERROR_VARIABLE error)
add_executable(consumer consumer.c)
target_link_libraries(consumer libtoolset)

install(TARGETS consumer
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
