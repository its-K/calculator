cmake_minimum_required(VERSION 3.5)
SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")

project(op)


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(
    op
    main.cpp
)

add_subdirectory(arithmetic)
add_subdirectory(algebric)
add_subdirectory(logrithm)

target_link_libraries(op arithmetic)
target_link_libraries(op algebric)
target_link_libraries(op logrithm)
target_link_libraries(op ${CONAN_LIBS})