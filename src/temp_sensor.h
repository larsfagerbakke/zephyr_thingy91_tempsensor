/*
  * temp_sensor.h
  *
  * Created: 30/01/2021, by Lars Fagerbakke for the Nordic Semiconductor Thingy91
  * 
  * This relies on the CONFIG_SENSOR=y flag in prj.conf
*/
#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include <zephyr/kernel.h>
#include <zephyr/drivers/sensor.h>

// Initialize temperature sensor
int init_temp_sensor();

// Fetch temperature from sensor
float get_temp();

#endif /* TEMP_SENSOR_H_ */