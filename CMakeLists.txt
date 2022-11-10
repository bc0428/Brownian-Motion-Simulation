cmake_minimum_required(VERSION 3.14)
project(Simulation) #

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Updates.cpp src/Updates.h src/Ball.cpp src/Ball.h src/Constants.h) #
add_executable(Course_Scheduler ${SOURCE_FILES}) #
include_directories(/opt/homebrew/Cellar/sfml/2.5.1_2/include) #

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Course_Scheduler sfml-system sfml-window sfml-graphics sfml-audio sfml-network) #