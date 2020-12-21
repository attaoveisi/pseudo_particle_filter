cmake_minimum_required(VERSION 3.5)
project(MCL)
find_package(PythonLibs REQUIRED)
set(CMAKE_CXX_STANDARD 11)
set(PYTHON_EXECUTABLE "/usr/bin/python2.7")
set(PYTHON_INCLUDE_DIR "/usr/include/python2.7")
set(PYTHON_LIBRARIES "/usr/lib/x86_64-linux-gnu/libpython2.7.so")

#include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(MCL main.cpp Robot.cpp Map.cpp Base.cpp)
#add_executable(MCL main.cpp Robot.cpp Map.cpp Base.cpp ${SOURCES})

#target_link_libraries(MCL ${PYTHON_LIBRARIES})


