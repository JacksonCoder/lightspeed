cmake_minimum_required(VERSION 2.6)
project(lightspeed)

add_executable(lightspeed main.cpp)

install(TARGETS lightspeed RUNTIME DESTINATION bin)
