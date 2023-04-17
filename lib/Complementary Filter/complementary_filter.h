#ifndef COMPLEMENTARY_FILTER
#define COMPLEMENTARY_FILTER

#include <Arduino.h>
#include <dig_hpf.h>

class CF {
    private :
        float roll , pitch , yaw , alpha;
    public :
        CF() = default;
        CF(float Alpha );
        void update(float *tb , float *acc , float *gyro , float t);
};
#endif                       