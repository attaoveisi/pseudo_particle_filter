cmake_minimum_required(VERSION 3.5)
project(MCL VERSION 1.0.3)

set(CMAKE_CXX_STANDARD 17)

find_package(Matplot++)

add_executable(MCL main.cpp Robot.cpp Map.cpp Base.cpp)

target_link_libraries(MCL PUBLIC Matplot++::matplot)

