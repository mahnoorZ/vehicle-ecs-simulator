#ifndef SENSOR_MANAGER_HPP
#define SENSOR_MANAGER_HPP

#include "types.hpp"

class SensorManager {

public:

    SensorManager();

    void update();

    const SensorData& getSensors() const;

private:

    SensorData sensors;

};

#endif