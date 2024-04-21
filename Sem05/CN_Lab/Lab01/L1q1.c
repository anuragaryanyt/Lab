/* write a C program to swap the content of 2 variables entered through the command line using function and pointer*/

#include<stdio.h>
#include<stdlib.h>
void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void main(int argc, char *argv[])
{
    int a,b;
    a=atoi(argv[1]);
    b=atoi(argv[2]);
    printf("No before swapping is: a=%d , b=%d\n", a,b);
    swap(&a,&b);
    printf("No after swapping is: a=%d , b=%d\n", a,b);
}

