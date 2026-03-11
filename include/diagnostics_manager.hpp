#ifndef DIAGNOSTICS_MANAGER_HPP
#define DIAGNOSTICS_MANAGER_HPP

#include "types.hpp"
#include <vector>

class DiagnosticsManager {

public:

    DiagnosticsManager();

    void evaluate(const SensorData& sensors);

    const std::vector<Fault>& getActiveFaults() const;

    bool hasCriticalFault() const;

    bool hasWarning() const;

private:

    std::vector<Fault> active_faults;

};

#endif