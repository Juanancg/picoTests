#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#include "Config.h"
#include "Logger.h"
#include "WifiManager.h"

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

    Logger logger;
    WifiManager wifi(logger);
    if (!wifi.init())
      return -1;

    //   if (!wifi.connect(WIFI_SSID, WIFI_PASSWORD, 15000)) {
    //     logger.error("Cannot continue without WiFi!");
    //     //   return -2;
    //   }

    while (true) {
      // printf("Hello, world!\n");
      logger.error("Hello, world from logger!");
      sleep_ms(1000);
    }
}
