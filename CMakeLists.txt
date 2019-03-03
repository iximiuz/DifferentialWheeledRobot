cmake_minimum_required(VERSION 3.12.4)

project(DifferentialWheeledRobot VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")

find_package(SDL2 REQUIRED)

include_directories(
  ${SDL2_INCLUDE_DIRS}
  "${CMAKE_SOURCE_DIR}/src"
  "${CMAKE_SOURCE_DIR}/src/engine"
)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp" "src/**/*.cpp")

add_executable(drw ${SOURCES})
target_link_libraries(drw ${SDL2_LIBRARIES})

