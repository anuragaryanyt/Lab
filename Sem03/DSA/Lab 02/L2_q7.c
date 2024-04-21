// WAP to arrange the elements of a array such that all even numbers are followed by all odd numbers.

#include <stdio.h>
void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] % 2 == 0)
                {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
    printf("Rearranged Array : \n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
}

void main()
{
    int n;
    printf("Enter no of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter Array : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, n);
}