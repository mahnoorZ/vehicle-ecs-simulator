#ifndef TYPES_HPP
#define TYPES_HPP

enum class ECSState {
    Off,
    Boot,
    Idle,
    Running,
    Warning,
    Fault,
    EmergencyStop
};

#endif