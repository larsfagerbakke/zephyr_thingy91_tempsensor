cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(zephyr_thingy91_tempsensor)

# Get a list of all .c files in the src directory
file(GLOB app_sources src/*.c)

# Add the source files to the target
target_sources(app PRIVATE ${app_sources})
