#ifndef LOG_H
#define LOG_H

#include "print.h"

// Function prototype for the error function
void sys_error(const char* message);
void sys_success(const char* message);
void sys_warn(const char* message);
void sys_info(const char* message);
void sys_stop(const char* message);

#endif 
