#include "diagnostics_manager.hpp"
#include "logger.hpp"

DiagnosticsManager::DiagnosticsManager() {}

void DiagnosticsManager::evaluate(const SensorData& sensors) {

    active_faults.clear();

    // Battery diagnostics

    if (sensors.battery_voltage < 10.5) {

        active_faults.push_back({
            FaultCode::LowBattery,
            FaultSeverity::Critical,
            "Battery voltage critically low"
        });

        Logger::log("CRITICAL: Battery voltage critically low");

    }

    else if (sensors.battery_voltage < 11.5) {

        active_faults.push_back({
            FaultCode::LowBattery,
            FaultSeverity::Warning,
            "Battery voltage low"
        });

        Logger::log("WARNING: Battery voltage low");

    }

    // Oil temperature diagnostics

    if (sensors.oil_temperature > 95) {

        active_faults.push_back({
            FaultCode::OverTemperature,
            FaultSeverity::Critical,
            "Oil temperature too high"
        });

        Logger::log("CRITICAL: Oil temperature too high");

    }

    else if (sensors.oil_temperature > 85) {

        active_faults.push_back({
            FaultCode::OverTemperature,
            FaultSeverity::Warning,
            "Oil temperature high"
        });

        Logger::log("WARNING: Oil temperature high");

    }

    // Communication check

    if (!sensors.communication_ok) {

        active_faults.push_back({
            FaultCode::CommunicationLoss,
            FaultSeverity::Critical,
            "Communication lost"
        });

        Logger::log("CRITICAL: Communication lost");

    }

}

const std::vector<Fault>& DiagnosticsManager::getActiveFaults() const {

    return active_faults;

}

bool DiagnosticsManager::hasCriticalFault() const {

    for (const auto& f : active_faults)
        if (f.severity == FaultSeverity::Critical)
            return true;

    return false;

}

bool DiagnosticsManager::hasWarning() const {

    for (const auto& f : active_faults)
        if (f.severity == FaultSeverity::Warning)
            return true;

    return false;

}