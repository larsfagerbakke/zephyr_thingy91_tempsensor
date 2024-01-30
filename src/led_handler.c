#include "led_handler.h"

#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)
#define LED2_NODE DT_ALIAS(led2)

static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
static const struct gpio_dt_spec led2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);

static int setup_led(struct gpio_dt_spec led_spec)
{
    if (!gpio_is_ready_dt(&led_spec))
    {
        return -ENODEV;
    }

    int ret = gpio_pin_configure_dt(&led_spec, GPIO_OUTPUT_INACTIVE);
    if (ret < 0)
    {
        return ret;
    }

    return 0;
}

int init_leds()
{
    int ret;

    ret = setup_led(led0);
    if (ret < 0)
    {
        return ret;
    }

    ret = setup_led(led1);
    if (ret < 0)
    {
        return ret;
    }

    ret = setup_led(led2);
    if (ret < 0)
    {
        return ret;
    }

    return 0;
}

int toggle_led(enum led_num led)
{
    switch (led)
    {
    case LED_0:
        return gpio_pin_toggle_dt(&led0);
    case LED_1:
        return gpio_pin_toggle_dt(&led1);
    case LED_2:
        return gpio_pin_toggle_dt(&led2);
    default:
        return -EINVAL;
    }
}

int toggle_led_color(enum led_color color)
{
    switch (color)
    {
    case LED_COLOR_RED:
        // Toggle red LED
        return gpio_pin_toggle_dt(&led0);
    case LED_COLOR_GREEN:
        // Toggle green LED
        return gpio_pin_toggle_dt(&led1);
    case LED_COLOR_BLUE:
        // Toggle blue LED
        return gpio_pin_toggle_dt(&led2);
    case LED_COLOR_YELLOW:
        // Toggle yellow LED (combination of red and green)
        gpio_pin_toggle_dt(&led0);
        return gpio_pin_toggle_dt(&led1);
    case LED_COLOR_WHITE:
        gpio_pin_toggle_dt(&led0);
        gpio_pin_toggle_dt(&led1);
        return gpio_pin_toggle_dt(&led2);
    default:
        return -EINVAL;
    }
}

int blink_led_color(enum led_color color, int num_times, int sleep_time_ms) {
    for (int i = 0; i < num_times; i++) {
        int ret = toggle_led_color(color);
        if (ret < 0) {
            return ret;
        }
        k_msleep(sleep_time_ms);
    }
    return 0;
}