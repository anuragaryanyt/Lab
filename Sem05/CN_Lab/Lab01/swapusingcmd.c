#include <stdio.h>
#include <stdlib.h>
void main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        printf("Number %d is: %s\n", i, argv[i]);
    }
    int x, y, temp;
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    temp = x;
    x = y;
    y = temp;
    printf("Swapping: x=%d y=%d\n", x,y);
}