#ifndef CAN_INTERFACE_HPP
#define CAN_INTERFACE_HPP

#include "types.hpp"
#include <vector>

class CanInterface {

public:

    CanInterface();

    void transmitState(ECSState state);

    void transmitSensors(const SensorData& sensors);

    void transmitFaults(const std::vector<Fault>& faults);

};

#endif