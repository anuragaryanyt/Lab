/*Q10.WAP to store numbers into an array of n integers, where the array must contain some duplicates. Find out the most repeating element in the array.*/

#include <stdio.h>
void main()
{
    int i, size, j, arr[50];
    printf("Enter the size of array-- "); // size of array
    scanf("%d", &size);

    printf("Enter the numbers--");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Duplicate elements are-- \n");

    // Searches for duplicate element
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
                printf("%d\n", arr[j]);
        }
    }
}