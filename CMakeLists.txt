cmake_minimum_required(VERSION 2.6)
project(lightspeed)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

add_executable(lightspeed main.cpp src/help.cpp src/globals.cpp)

install(TARGETS lightspeed RUNTIME DESTINATION bin)
