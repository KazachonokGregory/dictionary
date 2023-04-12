cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

qt_add_executable(dictionary
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_link_libraries(dictionary PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(dictionary PRIVATE simple)

qt_finalize_executable(dictionary)
