#include "sensor_manager.hpp"
#include <cstdlib>

SensorManager::SensorManager() {}

void SensorManager::update() {
    // simulate ignition turning on
    sensors.ignition_on = true;

    // simulate operator pressing start
    sensors.start_command = true;

    // emergency stop not pressed
    sensors.emergency_stop = false;

    // simulate sensors

    sensors.engine_rpm = rand() % 2500;

    sensors.battery_voltage = 11.5 + static_cast<float>(rand()) / RAND_MAX;

    sensors.hydraulic_pressure = 100 + rand() % 50;

    sensors.oil_temperature = 50 + rand() % 20;

    sensors.vehicle_speed = rand() % 20;

    sensors.communication_ok = true;

//     // intentionally force abnormal values for testing
//     sensors.engine_rpm = 1800.0;
//     sensors.battery_voltage = 10.2;      // critical low battery
//     sensors.hydraulic_pressure = 110.0;
//     sensors.oil_temperature = 98.0;      // critical overtemperature
//     sensors.vehicle_speed = 12.0;
//     sensors.communication_ok = true;
}


const SensorData& SensorManager::getSensors() const {

    return sensors;

}