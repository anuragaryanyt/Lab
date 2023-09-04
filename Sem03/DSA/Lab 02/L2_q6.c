/*
Given an unsorted array arr and two numbers x and y, find the minimum distance
between x and y in arr. The array might also contain duplicates. You may assume
that both x and y are different and present in arr.
Input: arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, x = 3, y = 6
Output: Minimum distance between 3 and 6 is 4.
*/

#include <stdio.h>

void minDist(int arr[], int x, int y, int n)
{
    int min = n;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] == y)
                {
                    int dist = j - i;
                    if (dist < min)
                        min = dist;
                }
            }
        }
    }
    printf("Minimum distance : %d\n", min);
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

    int x, y;
    printf("Enter Value of X: ");
    scanf("%d", &x);
    printf("Enter Value of Y: ");
    scanf("%d", &y);

    minDist(arr, x, y, n);
}