#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>

enum class ECSState {
    Off,
    Boot,
    Idle,
    Running,
    Warning,
    Fault,
    EmergencyStop
};

enum class FaultSeverity {
    None,
    Warning,
    Critical
};

enum class FaultCode {
    None,
    LowBattery,
    OverTemperature,
    LowHydraulicPressure,
    EngineOverspeed,
    CommunicationLoss
};

struct Fault {

    FaultCode code = FaultCode::None;
    FaultSeverity severity = FaultSeverity::None;
    std::string description;

};

struct SensorData {

    bool ignition_on = false;
    bool start_command = false;
    bool emergency_stop = false;

    float battery_voltage = 12.5;
    float engine_rpm = 0.0;
    float hydraulic_pressure = 120.0;
    float oil_temperature = 60.0;
    float vehicle_speed = 0.0;

    bool communication_ok = true;

};

struct CANFrame {

    uint32_t id;
    uint8_t data[8];
    uint8_t dlc = 8;

};

#endif