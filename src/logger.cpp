#include "logger.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>

void Logger::log(const std::string& message) {

    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);

    std::tm *ptm = std::localtime(&time);

    std::cout << "["
              << std::put_time(ptm, "%Y-%m-%d %H:%M:%S")
              << "] "
              << message
              << std::endl;
}