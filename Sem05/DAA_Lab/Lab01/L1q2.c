/* Given an array arr[] of size N, find the prefix sum of the array. A prefix sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] . . . arr[i]. */

#include <stdio.h>

int main()
{
    int n;
    printf("\nEnter the number of Elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int temp = 0, prefixSum[5];
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    printf("prefix array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ,", prefixSum[i]);
    }
}
