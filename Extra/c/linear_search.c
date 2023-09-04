#include <stdio.h>

int linear(int arr[], int x, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            printf("element %d found at position %d \n", x, i + 1);
            break;
        }
    }

    if (i >= n)
    {
        printf("Element not found!!\n");
    }
}

int main()
{
    int x, n, array[50];

    printf("Enter the no of array elements: ");
    scanf("%d", &n);

    printf("Enter the array: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    linear(array, x, n);
    return 0;
}
