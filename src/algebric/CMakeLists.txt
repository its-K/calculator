cmake_minimum_required(VERSION 3.5)

project(algebric)
set(source ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB files ${source}/*.cpp)

add_library(algebric ${files})

target_include_directories(algebric PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(op PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
