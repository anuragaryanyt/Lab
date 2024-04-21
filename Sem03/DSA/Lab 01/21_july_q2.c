/*Q2. WAP to find out the sum of the numbers stored in an array of integers.*/

#include <stdio.h>
int main()
{
    int arr[100], size, i, sum = 0;

    printf("Enter the size of the array--");
    scanf("%d", &size);                                     //size of array

    printf("Enter the elements of array--\n");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);                              //taking input

    for (i = 0; i < size; i++)
        sum += arr[i];                                     //sum
 
    printf("Sum of the array = %d\n", sum);

    return 0;
}