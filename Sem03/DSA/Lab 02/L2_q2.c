// WAP to search an element in array of n numbers

#include <stdio.h>

void search(int arr[], int item, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == item)
        {
            printf("Item Found");
            if (i < n)
                printf("The element is found at = %d", i + 1);
            return;
        }
    }
    printf("Item Not Found");
}

void main()
{
    int n;
    int item;

    printf("Enter Value of n : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter Array : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter Item to be searched : ");
    scanf("%d", &item);

    search(arr, item, n);
}
