#include <iostream>
#include "controller.hpp"

int main() {
    std::cout << "Vehicle ECS Simulator starting..." << std::endl;

    Controller controller;
    controller.run();

    return 0;
}