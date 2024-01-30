#include <zephyr/kernel.h>

// Sensor support
#include <zephyr/drivers/sensor.h>

// Logging support
#include <zephyr/logging/log.h>

#include "led_handler.h"
#include "temp_sensor.h"

#define MODULE main
LOG_MODULE_REGISTER(MODULE, LOG_LEVEL_DBG);

int main(void)
{
    LOG_INF("Application starting...");

    int ret;

    ret = init_leds();
    if (ret < 0)
    {
        LOG_ERR("LED setup failed, error %d", ret);
        return 0;
    }

    ret = init_temp_sensor();
    if (ret < 0)
    {
        LOG_ERR("Temperature sensor setup failed, error %d", ret);
        return 0;
    }

    while (1)
    {
        float tempVal = get_temp();

        LOG_INF("Temperature: %f", tempVal);
        
        blink_led_color(LED_COLOR_BLUE, 4, 150);

        k_msleep(3000);
    }

    return 0;
}
