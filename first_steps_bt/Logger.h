#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger
{
public:
    Logger();
    void printMessage(const std::string &message) const;

private:
};

#endif // LOGGER_H