cmake_minimum_required(VERSION 3.25)

project(crypto-alarm VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_executable(app main.cpp
    src/MainWindow.cpp include/MainWindow.hpp
)

target_link_libraries(app PRIVATE Qt6::Widgets)
target_include_directories(app PRIVATE include)

set_target_properties(app PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)


