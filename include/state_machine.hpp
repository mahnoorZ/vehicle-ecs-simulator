#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include "types.hpp"

class StateMachine {

public:

    StateMachine();

    void update(const SensorData& sensors, bool critical_fault, bool warning);

    ECSState getState() const;

private:

    ECSState current_state;

};

#endif