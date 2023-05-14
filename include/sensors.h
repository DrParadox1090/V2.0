#ifndef SENSORS_H
#define SENSORS_H
#include <Arduino.h>
#include <Wire.h>


void sensor_init(TwoWire wire);
void collect_data();
void fuse_data();
void display_data();

#endif