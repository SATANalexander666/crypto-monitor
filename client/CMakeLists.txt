cmake_minimum_required(VERSION 3.18.4)

project(crypto-alarm VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_executable(app main.cpp
    src/MainWindow.cpp include/MainWindow.hpp
    src/ToolBar.cpp include/ToolBar.hpp
    src/Reciever.cpp include/Reciever.hpp
    src/DataManager.cpp include/DataManager.hpp
    #src/TableBuilder.cpp include/TableBuilder.hpp
    src/TableModel.cpp include/TableModel.hpp
    src/TableLinker.cpp include/TableLinker.hpp
    src/TableView.cpp include/TableView.hpp
)

target_include_directories(app PRIVATE include)

target_link_libraries(app PRIVATE Qt6::Widgets)
target_link_libraries(app PRIVATE zmq)


set_target_properties(app PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)


