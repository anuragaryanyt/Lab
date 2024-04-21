/*Q4. WAP to display the array elements in ascending order.*/

#include <stdio.h>
void main()
{
    int i, j, temp, si, arr[50];
    printf("Enter the size of array-- ");   // size of array
    scanf("%d", &si); 

    printf("Enter the numbers--");
    for (i = 0; i < si; i++)
        scanf("%d", &arr[i]);               // taking input

    for (i = 0; i < si; i++)
    {
        for (j = i + 1; j < si; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("The numbers arranged in ascending order-- ");
    for (i = 0; i < si; i++)
        printf("%d \t", arr[i]);
}