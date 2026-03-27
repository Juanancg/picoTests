#ifndef LOGGER_H
#define LOGGER_H

#include <cstdarg>
#include <string>

enum class LogLevel { DEBUG, INFO, WARN, ERROR };

class Logger
{
public:
    Logger();

    void setMinLevel(LogLevel level);

    void debug(const char *fmt, ...) const;
    void info(const char *fmt, ...) const;
    void warn(const char *fmt, ...) const;
    void error(const char *fmt, ...) const;

  private:
    const char *levelToStr(LogLevel level) const;
    void vlog(LogLevel level, const char *fmt, va_list args) const;
    static LogLevel s_minLevel;
};

#endif // LOGGER_H