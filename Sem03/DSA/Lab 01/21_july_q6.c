/*Q6. WAP to search a particular number from the array.*/
#include <stdio.h>
int main()
{
    int size, i, s, arr[30];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    printf("Enter the elements: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the item to be searched: ");
    scanf("%d", &s);
    
    i = 0;
    while (i < size && s != arr[i])
        i++;
    if (i < size)
        printf("The element is found at = %d", i + 1);
    else
        printf("Element not found!");
    return 0;
}