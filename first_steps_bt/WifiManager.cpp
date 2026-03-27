#include "WifiManager.h"
#include <cstdint>
#include "lwip/ip4_addr.h"
#include "pico/cyw43_arch.h"

WifiManager::WifiManager(const Logger &logger) : log_(logger) {}

bool WifiManager::init() {
  log_.info("Initializing CYW43...");
  // Temporary commenting because we already do this in the main to initialize
  // the led if (cyw43_arch_init()) {
  //   log_.error("cyw43_arch_init() failed");
  //   return false;
  // }

  cyw43_arch_enable_sta_mode();

  log_.info("CYW43 init OK, STA mode enabled");

  return true;
}

bool WifiManager::connect(const char *ssid, const char *password,
                          uint32_t timeout_ms) {

  log_.info("Connecting to Wi-Fi SSID='%s' timeout=%u ms", ssid, timeout_ms);

  int rc = cyw43_arch_wifi_connect_timeout_ms(
      ssid, password, CYW43_AUTH_WPA2_AES_PSK, timeout_ms);

  if (rc) {
    log_.error("wi-Fi connect failed rc=%d", rc);
    return false;
  }

  if (netif_default) {
    const ip4_addr_t *ip = netif_ip4_addr(netif_default);
    log_.info("Wi-Fi connected, IP=%s", ip4addr_ntoa(ip));
  } else {
    log_.warn("Wi-Fi connected but netif_default is null");
  }

  return true;
}

bool WifiManager::isConnected() const
{
  int status = cyw43_tcpip_link_status(&cyw43_state, CYW43_ITF_STA);
  return status == CYW43_LINK_UP;
}

void WifiManager::ensureConnected(const char *ssid, const char *password) {

  if (!isConnected()) {
    log_.warn("Wi-Fi link down, reconnecting...");
    connect(ssid, password, 10000);
  }
}