#ifndef WIFIMANAGER_HPP
#define WIFIMANAGER_HPP

#include <cstdint>
#include "Logger.h"

class WifiManager
{
public:
    explicit WifiManager(const Logger &logger);
    
    bool init();
    bool connect(const char *ssid, const char *password, uint32_t timeout_ms = 15000);
    bool isConnected() const;
    void ensureConnected(const char *ssid, const char *password);
private:
    const Logger &log_;
};

#endif // WIFIMANAGER_HPP