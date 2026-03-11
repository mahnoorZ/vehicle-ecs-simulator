#include "controller.hpp"
#include "logger.hpp"
#include <thread>
#include <chrono>

Controller::Controller() {}

void Controller::run() {

    Logger::log("Controller starting...");

    while (true) {

        sensor_manager.update();

        const SensorData& sensors = sensor_manager.getSensors();

        diagnostics_manager.evaluate(sensors);

        state_machine.update(
            sensors,
            diagnostics_manager.hasCriticalFault(),
            diagnostics_manager.hasWarning()
        );

        if (diagnostics_manager.hasCriticalFault()) {
            Logger::log("SYSTEM ENTERING FAULT STATE");
        }

        can_interface.transmitState(state_machine.getState());

        can_interface.transmitSensors(sensors);

        can_interface.transmitFaults(diagnostics_manager.getActiveFaults());

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

}