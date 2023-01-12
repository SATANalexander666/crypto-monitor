cmake_minimum_required(VERSION 3.25)
project(server)

set(CMAKE_CXX_STANDARD 17)

add_executable(server src/server.cpp include/server.hpp)

target_include_directories(server PRIVATE include)
target_link_libraries(server oatpp)

