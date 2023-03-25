cmake_minimum_required(VERSION 3.14)

project(Dictionary)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/example)

add_subdirectory(include/simple)

add_executable(Dictionary ${PROJECT_SOURCE_DIR}/example/main.cpp)
target_link_libraries(Dictionary SimpleDictionary)

