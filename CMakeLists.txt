cmake_minimum_required(VERSION 3.23)
project(snezhinka_cocka)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(snezhinka_cocka main.cpp Fractal.cpp Fractal.h Globals.h Button.cpp Button.h)

target_link_libraries(snezhinka_cocka sfml-graphics sfml-audio)