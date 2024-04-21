/*Q5.WAP Input N element into an array.find out sum of all even number and multiply all odd no.*/

#include <stdio.h>
int main()
{
    int Size, i, a[100];
    int even_sum = 0, odd_mul = 1;

    printf("\n Please Enter the Size of an Array : ");
    scanf("%d", &Size);

    printf("\nPlease Enter the Array Elements\n");
    for (i = 0; i < Size; i++)
        scanf("%d", &a[i]);
        
    for (i = 0; i < Size; i++)
    {
        if (a[i] % 2 == 0)
        {
            even_sum = even_sum + a[i];
        }
        else
        {
            odd_mul = odd_mul * a[i];
        }
    }
    printf("\n Sum of Even Numbers in this Array = %d ", even_sum);
    printf("\n Multiplication of Odd Numbers in this Array = %d ", odd_mul);
    return 0;
}