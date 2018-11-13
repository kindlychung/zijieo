cmake_minimum_required(VERSION 2.8)
project(MyHello CXX)

message("cmake bin dir: ${CMAKE_BINARY_DIR}")
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
add_executable(zijieo zijieo.cpp)
target_link_libraries(zijieo ${CONAN_LIBS})
