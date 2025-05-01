#ifndef SERIAL_H
#define SERIAL_H

int serial_init();
int serial_received();
char read_serial();
int is_transmit_empty();
void write_serial(char a);
void writeser(const char* serial);

#endif