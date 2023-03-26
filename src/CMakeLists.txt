cmake_minimum_required(VERSION 3.14)

project(SimpleDictionary)

set(SOURCE_LIB
    simple/consoleapplication.cpp
    simple/database.cpp
    simple/databasebuilder.cpp
    simple/entry.cpp
    simple/query.cpp
    simple/queryanswer.cpp
)

add_library(simple SHARED ${SOURCE_LIB})
target_include_directories(simple PRIVATE ${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE LIBRARY_HEADERS "${PROJECT_SOURCE_DIR}/include/*.h")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

install(
    TARGETS simple
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)

