# zephyr_thingy91_tempsensor

This repository contains a small (minimal* with logging) sample of fetching temperature from [Nordic Semiconductor Thingy91's](https://www.nordicsemi.com/Products/Development-hardware/Nordic-Thingy-91) included [BME680 temperature sensor](https://infocenter.nordicsemi.com/topic/ug_thingy91/UG/thingy91/hw_description/env_sensors.html) ... Radical stuff! :boom:

\* _I have a SEGGER J-Link so thats why the extra configs are there. CONFIG_FPU=y is not needed (printing floats in debug), but part of my included configs._

## Init

The best approach to use this sample is to use Visual Studio nRF extension and create a new project and drop the sample code in there. This will set up the board you are working with and such, given it supports the leds in the board definition file.

### Led handler

I included the led handler to give some visual feedback, it's also on [GitHub](https://github.com/larsfagerbakke/zephyr_thingy91_blinky)

### Like?

Give my project a star! =) Want to use it? Feel free! Have suggestions? Make a PR!