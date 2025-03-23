#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "Logger.h"

int main()
{
    stdio_init_all();

    // Initialise the Wi-Fi chip
    if (cyw43_arch_init())
    {
        printf("CYW43 arch init failed\n");
        return -1;
    }

    // Example to turn on the Pico W LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);

    // Create an instance of Logger
    Logger logger;

    while (true)
    {
        // printf("Hello, world!\n");
        logger.printMessage("Hello, world from logger!");
        sleep_ms(1000);
    }
}
