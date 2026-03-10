cmake_minimum_required(VERSION 3.16)

project(vehicle_ecs_simulator VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_executable(vehicle_ecs_simulator
    src/main.cpp
    src/controller.cpp
)