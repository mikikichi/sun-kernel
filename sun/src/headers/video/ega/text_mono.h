#ifndef TEXT_MONO_H
#define TEXT_MONO_H


#define COLOR_BUFFER 0xB8000
#define MAX_BUFFER 0xB9000
#define BUFFER_LENGTH 4096
#define MAX_HEIGHT_M 25
#define MAX_WIDTH_M 80

#include <stdint.h>
#include <stddef.h>
#include "lib/strings.h"





void text_mono_init(void);
void mono_cursor(uint16_t position);
void buffer_write(uint16_t position, char c);
void buffer_string(uint16_t position, const char *string, uint16_t size);
void clear(uint16_t position);
void print(char *string);
//16 for now
//TO DO clean this shit up
extern uint16_t position;
extern volatile uint8_t* color_buffer;
extern uint16_t base;
extern int esc_seq[3];
extern int y;
extern int x;

#endif