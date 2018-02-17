cmake_minimum_required(VERSION 2.6)
project(lightspeed)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
add_executable(lightspeed-bin 
lightspeed/core/main.cpp 
lightspeed/core/src/utils/core/help.cpp 
lightspeed/core/src/utils/core/globals.cpp 
lightspeed/core/src/utils/core/enviroment.cpp 
lightspeed/core/src/utils/core/inputhandling.cpp
lightspeed/core/src/utils/file/file.cpp
lightspeed/core/src/utils/file/fileloader.cpp
lightspeed/core/src/utils/core/optionswitch.cpp
lightspeed/core/src/parsing/configparser.cpp
lightspeed/core/src/compilation/cmakegenerator.cpp
lightspeed/core/src/utils/file/codegrab.cpp
lightspeed/core/src/network/httpconnection.cpp
lightspeed/core/src/utils/helpers/netutils.cpp
lightspeed/core/src/utils/core/errormanager.cpp
)
add_executable(lightspeed-test
lightspeed/tests/main.cpp
)
add_library(ls_libs
lightspeed/core/src/utils/core/help.cpp 
lightspeed/core/src/utils/core/globals.cpp 
lightspeed/core/src/utils/core/enviroment.cpp 
lightspeed/core/src/utils/core/inputhandling.cpp
lightspeed/core/src/utils/file/file.cpp
lightspeed/core/src/utils/file/fileloader.cpp
lightspeed/core/src/utils/core/optionswitch.cpp
lightspeed/core/src/parsing/configparser.cpp
lightspeed/core/src/compilation/cmakegenerator.cpp
lightspeed/core/src/utils/file/codegrab.cpp
lightspeed/core/src/network/httpconnection.cpp
lightspeed/core/src/utils/helpers/netutils.cpp
lightspeed/core/src/utils/core/errormanager.cpp
)
target_link_libraries(ls_libs ${Boost_LIBRARIES} curl)
target_link_libraries(lightspeed-bin ${Boost_LIBRARIES} curl)
add_subdirectory(lightspeed/tests/external/googletest/googletest)
target_link_libraries(lightspeed-test gtest gtest_main ls_libs)
install(TARGETS lightspeed-bin RUNTIME DESTINATION bin)
