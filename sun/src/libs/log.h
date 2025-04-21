#ifndef LOG_H
#define LOG_H

void error(const char* message);
void warn(const char* message);
void info(const char* message);
void success(const char* message);
void begin(const char* message);
void fatal(const char* message);

#endif