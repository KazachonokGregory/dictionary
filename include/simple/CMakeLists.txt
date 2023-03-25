cmake_minimum_required(VERSION 3.14)

project(SimpleDictionary)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/dist)

add_library(SimpleDictionary SHARED dictionary.h)

set_target_properties(SimpleDictionary PROPERTIES LINKER_LANGUAGE CXX)

install(TARGETS SimpleDictionary DESTINATION lib)

