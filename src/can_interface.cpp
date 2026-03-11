#include "can_interface.hpp"
#include "logger.hpp"
#include <iostream>

CanInterface::CanInterface() {}

void CanInterface::transmitState(ECSState state) {

    Logger::log("CAN TX | ID:0x100 STATE=" + std::to_string(static_cast<int>(state)));

}

void CanInterface::transmitSensors(const SensorData& sensors) {

    Logger::log(
        "CAN TX | ID:0x101 RPM=" + std::to_string((int)sensors.engine_rpm) +
        " TEMP=" + std::to_string((int)sensors.oil_temperature)
    );

    Logger::log(
        "CAN TX | ID:0x102 BATTERY=" + std::to_string(sensors.battery_voltage)
    );
}

void CanInterface::transmitFaults(const std::vector<Fault>& faults) {

    for (const auto& f : faults) {

        Logger::log(
            "CAN TX | ID:0x103 FAULT=" + std::to_string(static_cast<int>(f.code))
        );
    }
}