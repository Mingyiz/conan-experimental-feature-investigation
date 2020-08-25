cmake_minimum_required(VERSION 2.8)
project(tool-set C)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
if(BUILD_SHARED_LIBS)
    add_definitions(-DBUILD_SHARED_LIBS=true)
else()
    add_definitions(-DBUILD_SHARED_LIBS=false)
endif()

add_library(libtoolset libtoolset.c)
add_executable(toolset toolset.c)
target_link_libraries(toolset libtoolset)

set_target_properties(libtoolset PROPERTIES PUBLIC_HEADER src/libtooset.h)

install(TARGETS libtoolset
  PUBLIC_HEADER DESTINATION include
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
  
install(TARGETS toolset
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
