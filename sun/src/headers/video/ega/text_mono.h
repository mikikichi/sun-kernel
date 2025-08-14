#ifndef TEXT_MONO_H
#define TEXT_MONO_H


#define COLOR_BUFFER 0xB8000
#define MAX_BUFFER 0xB9000
#define BUFFER_LENGTH 4096
#define MAX_HEIGHT_M 25
#define MAX_WIDTH_M 80

#include <stdint.h>
#include <stddef.h>

void text_mono_init(void);
void mono_cursor(uint16_t position);
void mono_print(uint16_t position, char c);
void print_string(uint16_t position, const char *string);
void clear(uint16_t position);
//16 for now
extern uint16_t position;
extern volatile uint8_t* color_buffer;
extern uint16_t base;
extern int y;
extern int x;

#endif