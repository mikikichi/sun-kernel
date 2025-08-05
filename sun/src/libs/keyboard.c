#include <stdbool.h>
#include <stdint.h>
#include "lib/io.h"
#include "lib/print.h"

bool shift_pressed = false;

#define MAX_INPUT_LENGTH 256

char ScanCodeToASCII(uint8_t scan_code, bool shift) {
    switch (scan_code) {
        case 0x1E: return shift ? 'A' : 'a';
        case 0x30: return shift ? 'B' : 'b';
        case 0x2E: return shift ? 'C' : 'c';
        case 0x20: return shift ? 'D' : 'd';
        case 0x12: return shift ? 'E' : 'e';
        case 0x21: return shift ? 'F' : 'f';
        case 0x22: return shift ? 'G' : 'g';
        case 0x23: return shift ? 'H' : 'h';
        case 0x17: return shift ? 'I' : 'i';
        case 0x24: return shift ? 'J' : 'j';
        case 0x25: return shift ? 'K' : 'k';
        case 0x26: return shift ? 'L' : 'l';
        case 0x32: return shift ? 'M' : 'm';
        case 0x31: return shift ? 'N' : 'n';
        case 0x18: return shift ? 'O' : 'o';
        case 0x19: return shift ? 'P' : 'p';
        case 0x10: return shift ? 'Q' : 'q';
        case 0x13: return shift ? 'R' : 'r';
        case 0x1F: return shift ? 'S' : 's';
        case 0x14: return shift ? 'T' : 't';
        case 0x15: return shift ? 'Y' : 'y';
        case 0x16: return shift ? 'U' : 'u';
        case 47: return shift ? 'V' : 'v';
        case 0x2D: return shift ? 'X' : 'x';
        case 0x11: return shift ? 'W' : 'w';
        case 0x28: return shift ? 'Y' : 'y';
        case 44: return shift ? 'Z' : 'z';
        
        // Numbers 0-9
        case 0xB: return shift ? '!' : '0';
        case 0x2: return shift ? '@' : '1';
        case 0x3: return shift ? '#' : '2';
        case 0x4: return shift ? '$' : '3';
        case 0x5: return shift ? '%' : '4';
        case 0x6: return shift ? '^' : '5';
        case 0x7: return shift ? '&' : '6';
        case 0x8: return shift ? '*' : '7';
        case 0x9: return shift ? '(' : '8';
        case 0xA: return shift ? ')' : '9';
        
        // Punctuation
        case 0x39: return ' '; // Space
        case 0x4A: return shift ? '_' : '-'; // Minus
        case 0x4C: return shift ? '+' : '='; // Equal
        case 0x35: return shift ? '~' : 0; // Grave
        case 0x33: return shift ? '{' : '['; // Left Bracket
        case 0x34: return shift ? '}' : ']'; // Right Bracket
        case 0x27: return shift ? ':' : ';'; // Semicolon
        case 0x37: return shift ? '"' : '\''; // Quote
        case 0x38: return shift ? '<' : ','; // Comma
        case 0x36: return shift ? '>' : '.'; // Period
        case 0x4E: return shift ? '?' : '/'; // Slash
        
        // Other
        case 0x1C: return '\n'; // Enter
        case 0x0E: return '\b'; // Backspace
        case 0x5D: return 0; // Right Control
        case 0x5B: return 0; // Left Control
        case 0x3A: return 0; // Caps Lock
        case 0xE0: return 0; // Special keys like Shift, Alt
        
        default: return 0; // unknown
    }
}

char sys_read()
{
    while (!(io_inb_8(0x64) & 0x01));

    uint8_t scan_code = io_inb_8(0x60);
    
    if (scan_code == 0x2A || scan_code == 0x36) { 
        shift_pressed = true;
        return 0;
    } 
    if (scan_code == 0x36) {  
        shift_pressed = true;  
        return 0; 
    } 
    else if (scan_code == 0xAA || scan_code == 0xB6) { 
        shift_pressed = false;
        return 0; 
    }
    else {
        char c = ScanCodeToASCII(scan_code, shift_pressed); 
        return c;
    }    
}

void print_input(const char* str) {
    while (*str) {  
        terminal_putchar(*str); 
        str++; 
    }
}

#define MAX_INPUT 256
//writing
void read_line(char* buffer, int max_len) {
    int index = 0;

    while (1) {
        char c = sys_read();

        if (c == 0)
            continue;

        if (c == '\n') {        //enter
            buffer[index] = '\0';
            return;
        }

        if (c == '\b') {
            if (index > 0) {
                index--;
                buffer[index] = '\0';
            }
        } else if (index < max_len - 1) {
            buffer[index++] = c;
            terminal_putchar(c);

        }
    }
}