#ifndef EXCEPTIONHAN_H
#define EXCEPTIONHAN_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "lib/print.h"
#include "lib/log.h"
#include "lib/serial.h"
#include "exc/exception.h"

void exception(int x);

#endif