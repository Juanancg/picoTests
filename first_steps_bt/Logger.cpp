#include "Logger.h"
#include <stdio.h>

Logger::Logger() {}

void Logger::printMessage(const std::string &message) const
{
    printf("%s\n", message.c_str());
}