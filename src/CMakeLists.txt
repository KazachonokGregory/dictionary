cmake_minimum_required(VERSION 3.16)

project(SimpleDictionary)

file(GLOB_RECURSE LIBRARY_HEADERS "${CMAKE_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE SOURCE_FILES "${PROJECT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE UI_FILES "${PROJECT_SOURCE_DIR}/*.ui")

set(SOURCE_LIB
    ${SOURCE_FILES}
    ${UI_FILES}
    ${LIBRARY_HEADERS}
)

add_library(simple SHARED ${SOURCE_LIB})
target_include_directories(simple PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(simple Qt6::Sql)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

install(
    TARGETS simple
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)

set(CONSOLE_DICT_SOURCES
        simple/consoleapplication.cpp
)

add_executable(console_dictionary
    ${CONSOLE_DICT_SOURCES}
)

target_link_libraries(console_dictionary PRIVATE simple)

