cmake_minimum_required(VERSION 2.6)
project(lightspeed)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

add_executable(lightspeed-bin 
lightspeed/core/main.cpp 
lightspeed/core/src/utils/help.cpp 
lightspeed/core/src/utils/globals.cpp 
lightspeed/core/src/utils/enviroment.cpp 
lightspeed/core/src/utils/inputhandling.cpp
lightspeed/core/src/utils/file.cpp
lightspeed/core/src/utils/fileloader.cpp
lightspeed/core/src/utils/optionswitch.cpp
lightspeed/core/src/parsing/configparser.cpp
lightspeed/core/src/compilation/cmakegenerator.cpp
lightspeed/core/src/utils/codegrab.cpp
)
add_executable(lightspeed-test
lightspeed/tests/main.cpp
)
add_subdirectory(lightspeed/tests/external/googletest/googletest)
target_link_libraries(lightspeed-test gtest gtest_main)
install(TARGETS lightspeed-bin RUNTIME DESTINATION bin)
