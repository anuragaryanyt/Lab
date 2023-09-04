/* write a C program to extract each byte from a given number and store them in separate character variables and print the content of those variables.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    printf("Given number=%d\n", num);

    // Extracting each byte using bitwise operations
    char byte4 = (num >> 24) & 0xFF;
    char byte3 = (num >> 16) & 0xFF;
    char byte2 = (num >> 8) & 0xFF;
    char byte1 = num & 0xFF;

    // Printing the content of each byte
    printf("Digit in Byte 1: %hhi\n", byte1);
    printf("Digit in Byte 2: %hhi\n", byte2);
    printf("Digit in Byte 3: %hhi\n", byte3);
    printf("Digit in Byte 4: %hhi\n", byte4);

    return 0;
}