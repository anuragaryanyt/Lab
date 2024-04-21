/* Write a function to ROTATE_RIGHT(p1, p2 ) right an array for first p2 elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the numbers p & q. Parameter p1 be the starting address of the array and p2 be the number of elements to be rotated. */

#include <stdio.h>

void exchange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void rotate_right(int *arr, int n, int k)
{
    for (int i = 0; i < k - 1; i++)
    {
        exchange(&arr[i], &arr[k - 1]);
    }
}
int main()
{
    printf("Enter the array size: ");
    int n;
    scanf("%d", &n);
    int arr[10];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter position to swap:");
    int k;
    scanf("%d", &k);
    printf("Original Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    rotate_right(arr, n, k);
    printf("\nArray after swap: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
