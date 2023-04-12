cmake_minimum_required(VERSION 3.16)

project(Dictionary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
set(CMAKE_AUTOMOC ON) 
set(CMAKE_AUTORCC ON) 
set(CMAKE_AUTOUIC ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(src)

add_executable(Dictionary ${PROJECT_SOURCE_DIR}/example/main.cpp)
target_include_directories(Dictionary PRIVATE ${PROJECT_SOURCE_DIR}/example)
target_include_directories(Dictionary PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(Dictionary simple)

set_target_properties(Dictionary PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
