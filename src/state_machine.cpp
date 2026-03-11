#include "state_machine.hpp"
#include "logger.hpp"

StateMachine::StateMachine() {

    current_state = ECSState::Off;

}

void StateMachine::update(const SensorData& sensors, bool critical_fault, bool warning) {

    switch (current_state) {

        case ECSState::Off:

            if (sensors.ignition_on) {
                Logger::log("Transition OFF -> BOOT");
                current_state = ECSState::Boot;
            }

            break;

        case ECSState::Boot:

            Logger::log("System Boot Complete");
            current_state = ECSState::Idle;

            break;

        case ECSState::Idle:

            if (critical_fault) {
                Logger::log("FAULT detected during IDLE");
                current_state = ECSState::Fault;
            }

            else if (sensors.start_command) {
                Logger::log("Transition IDLE -> RUNNING");
                current_state = ECSState::Running;
            }

            break;

        case ECSState::Running:

            if (sensors.emergency_stop) {
                Logger::log("EMERGENCY STOP ACTIVATED");
                current_state = ECSState::EmergencyStop;
            }

            else if (critical_fault) {
                Logger::log("Critical fault detected");
                current_state = ECSState::Fault;
            }

            else if (warning) {
                current_state = ECSState::Warning;
            }

            break;

        case ECSState::Warning:

            if (critical_fault) {
                Logger::log("Warning escalated to fault");
                current_state = ECSState::Fault;
            }

            break;

        default:
            break;
    }

}

ECSState StateMachine::getState() const {

    return current_state;

}