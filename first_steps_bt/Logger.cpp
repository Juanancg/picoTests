#include "Logger.h"
#include "pico/stdlib.h"
#include <cinttypes>
#include <cstdio>

LogLevel Logger::s_minLevel = LogLevel::DEBUG;

Logger::Logger() {}

void Logger::setMinLevel(LogLevel level) { s_minLevel = level; }

const char *Logger::levelToStr(LogLevel level) const {

  switch (level) {
  case LogLevel::DEBUG:
    return "DEBUG";
  case LogLevel::INFO:
    return "INFO";
  case LogLevel::WARN:
    return "WARN";
  case LogLevel::ERROR:
    return "ERROR";
  default:
    return "UNK";
  }
}

void Logger::vlog(LogLevel level, const char *fmt, va_list args) const {

  if ((int)level < (int)s_minLevel)
    return;

  uint64_t ms = to_ms_since_boot(get_absolute_time());

  printf("[%10" PRIu64 " ms] [%s]: ", ms, levelToStr(level));

  vprintf(fmt, args);

  printf("\n");
}

void Logger::debug(const char *fmt, ...) const {
  va_list args;
  va_start(args, fmt);
  vlog(LogLevel::DEBUG, fmt, args);
  va_end(args);
}

void Logger::info(const char *fmt, ...) const {
  va_list args;
  va_start(args, fmt);
  vlog(LogLevel::DEBUG, fmt, args);
  va_end(args);
}

void Logger::warn(const char *fmt, ...) const {
  va_list args;
  va_start(args, fmt);
  vlog(LogLevel::DEBUG, fmt, args);
  va_end(args);
}

void Logger::error(const char *fmt, ...) const {
  va_list args;
  va_start(args, fmt);
  vlog(LogLevel::DEBUG, fmt, args);
  va_end(args);
}