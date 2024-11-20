cmake_minimum_required(VERSION 3.25)
project(foo)
add_executable(foo WIN32 main.cpp)
target_link_libraries(foo gdi32)
