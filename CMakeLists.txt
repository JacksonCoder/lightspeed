cmake_minimum_required(VERSION 2.6)
project(lightspeed)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

add_executable(lightspeed-bin lightspeed/core/main.cpp lightspeed/core/src/utils/help.cpp lightspeed/core/src/utils/globals.cpp)

install(TARGETS lightspeed-bin RUNTIME DESTINATION bin)
