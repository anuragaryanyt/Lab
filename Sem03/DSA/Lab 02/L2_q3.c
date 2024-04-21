// WAP to sort a array of n numbers in Descending Order

#include <stdio.h>
void search(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    printf("Sorted Array :\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
}

void main()
{
    int n;
    printf("Enter Value of n : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter Array : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    search(arr, n);
} 
