#include "temp_sensor.h"

static const struct device *const temp_sensor = DEVICE_DT_GET_ANY(bosch_bme680);

int init_temp_sensor()
{
	if (temp_sensor == NULL)
	{
		return 0;
	}

	if (!device_is_ready(temp_sensor))
	{
		return 0;
	}

	return 1;
}

float get_temp()
{
    struct sensor_value temp;

    sensor_sample_fetch(temp_sensor);
    sensor_channel_get(temp_sensor, SENSOR_CHAN_AMBIENT_TEMP, &temp);

    // Cast struct values to float and return
    return (float)temp.val1 + (float)temp.val2 / 1000000;;   
}