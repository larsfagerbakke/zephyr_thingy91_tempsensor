/*
  * led_handler.h
  *
  * Created: 28/01/2021, by Lars Fagerbakke for the Nordic Semiconductor Thingy91
  * 
  * No needed flags in prj.conf
*/
#ifndef LED_HANDLER_H_
#define LED_HANDLER_H_

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

// Define LED enumeration
enum led_num
{
    LED_0, // Red
    LED_1, // Green
    LED_2  // Blue
};

// Define Color enumeration
enum led_color
{
    LED_COLOR_RED,
    LED_COLOR_GREEN,
    LED_COLOR_BLUE,
    LED_COLOR_YELLOW,
    LED_COLOR_WHITE
};

// Initialize LEDs
int init_leds();

// Toggle LED
int toggle_led(enum led_num);

// Toggle LED with color
int toggle_led_color(enum led_color color);

// Blink LED with color
// num_times must be an even number to end off!
int blink_led_color(enum led_color color, int num_times, int sleep_time_ms);

#endif /* LED_HANDLER_H_ */