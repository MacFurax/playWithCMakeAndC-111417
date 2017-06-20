cmake_minimum_required( VERSION 3.5)
project(playWithChrono)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} ./src/playWithChrono.cpp)

install (TARGETS ${PROJECT_NAME} DESTINATION bin)
