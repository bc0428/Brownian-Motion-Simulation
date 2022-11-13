cmake_minimum_required(VERSION 3.14)
project(Simulation) #

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/DynamicObjects.cpp src/DynamicObjects.h src/Ball.cpp src/Ball.h src/Constants.h src/StaticObjects.cpp src/StaticObjects.h) #
add_executable(Brownian_Motion_Simulation ${SOURCE_FILES}) #
include_directories(/opt/homebrew/Cellar/sfml/2.5.1_2/include) #

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Brownian_Motion_Simulation sfml-system sfml-window sfml-graphics sfml-audio sfml-network) #