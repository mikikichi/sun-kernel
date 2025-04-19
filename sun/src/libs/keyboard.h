#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdbool.h>
#include <stdint.h>

#define MAX_INPUT_LENGTH 256

extern char input_buffer[MAX_INPUT_LENGTH];

char ScanCodeToASCII(uint8_t scan_code, bool shift);
char sys_read();
void print_input(const char* str);
void read_line();
#endif