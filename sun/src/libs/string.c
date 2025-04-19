#include <stdint.h>

int strcmp(const char *s1, const char *s2) {
	const unsigned char *p1 = ( const unsigned char * )s1;
	const unsigned char *p2 = ( const unsigned char * )s2;
	
	while ( *p1 && *p1 == *p2 ) ++p1, ++p2;
	
    return ( *p1 > *p2 ) - ( *p2  > *p1 );
}

void uint8_to_string(uint8_t num, char* str) {
    int i = 0;
    
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0'; 
        return;
    }

    char temp[3];
    int j = 0;
    
    while (num > 0) {
        temp[j++] = (num % 10) + '0';
        num /= 10;
    }

    for (int k = j - 1; k >= 0; k--) {
        str[i++] = temp[k];
    }
    
    str[i] = '\0';
}