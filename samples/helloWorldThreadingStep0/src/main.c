/*
 * Copyright (c) 2020 Thomas Popp
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>


// ---- defines LED0 for the LED pin -------------------------------------------
// the devicetree node identifier for the "led0" alias.
#define LED0_NODE DT_ALIAS(led0)

#if DT_NODE_HAS_STATUS(LED0_NODE, okay)
#define LED0	DT_GPIO_LABEL(LED0_NODE, gpios)
#define PIN	DT_GPIO_PIN(LED0_NODE, gpios)
#define FLAGS	DT_GPIO_FLAGS(LED0_NODE, gpios)
#else
// a build error here means your board isn't set up to blink an LED.
#error "Unsupported board: led0 devicetree alias is not defined"
#define LED0	""
#define PIN	0
#define FLAGS	0
#endif


// ---- defines, configs and static vars for the LED0 thread -------------------
#define LED0_THREAD_STACK_SIZE 100
#define LED0_THREAD_PRIORITY 5

K_THREAD_STACK_DEFINE(led0_thread_stack_area, LED0_THREAD_STACK_SIZE);
static struct k_thread led0_thread_data;
static k_tid_t led0_thread_tid;


// ---- the thread for the LED0 task -------------------------------------------
void led0_thread (void *unused0, void *unused1, void *unused2) {
    const struct device *dev;
    int32_t rc;

    // init the LED
    dev = device_get_binding(LED0);
    if (dev == NULL) {
        return;
    }

    rc = gpio_pin_configure(dev, PIN, GPIO_OUTPUT_ACTIVE | FLAGS);
    if (rc < 0) {
        return;
    }    
    
    // run the thread for ever    
    while (true) {
        gpio_pin_set(dev, PIN, (int)true);
        k_msleep(100);        
        gpio_pin_set(dev, PIN, (int)false);
        k_msleep(900);        
    }
}


// -----------------------------------------------------------------------------
void main (void) {
    // init the thread
    led0_thread_tid = k_thread_create(&led0_thread_data, led0_thread_stack_area,
            K_THREAD_STACK_SIZEOF(led0_thread_stack_area),
            led0_thread,
            NULL, NULL, NULL,
            LED0_THREAD_PRIORITY, 0, K_NO_WAIT);

    // that's it! Let's have a Café!
}
