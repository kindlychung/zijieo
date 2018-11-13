cmake_minimum_required(VERSION 2.8)
project(MyHello CXX)

set(conan_cmake_file "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
if(EXISTS ${conan_cmake_file})
    include(${conan_cmake_file})
    conan_basic_setup()
endif()

add_executable(zijieo zijieo.cpp)
message("conan libs: ${CONAN_LIBS}")
target_link_libraries(zijieo ${CONAN_LIBS})
