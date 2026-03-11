cmake_minimum_required(VERSION 3.16)

project(vehicle_ecs_simulator)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(vehicle_ecs_simulator

    src/main.cpp
    src/controller.cpp
    src/logger.cpp
    src/sensor_manager.cpp
    src/state_machine.cpp
    src/diagnostics_manager.cpp
    src/can_interface.cpp

)
