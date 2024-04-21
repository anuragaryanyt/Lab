#include <stdio.h>
#include<stdlib.h>
void swap(double *a, double *b)
{
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Enter the number first!!");
    }

    double fno, sno;
    fno = atoi(argv[1]);
    sno = atoi(argv[2]);
    swap(&fno, &sno);
    // return 0;

    printf("first no= %d, sno= %d", fno, sno);
}

// int main()
// {
//     int x=20,y=30;
//     swap(&x,&y);
//     printf("x=%d y=%d\n",x,y);
// }

// void swap(int x, int y)
// {
//     int temp;
//     temp=x;
//     x=y;
//     y=temp;
//     printf("a=%d,b=%d\n",x,y);
//     // return (x,y);
// }

// int main()
// {
//     int a=20;
//     int b=30;
//     swap(a,b);
// }
