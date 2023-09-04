/*
Given a array, WAP to print the next greater element (NGE) for every element.
The next greater element for an element x is the first greater element on the right
side of x in array. Elements for which no greater element exist, consider next
greater element as -1. E.g. For the input array [2, 5, 3, 9, 7], the next greater
elements for each elements are as follows.
Element    NGE
 2 	       5
 5 	       9
 3 	       9
 9	      -1
 7 	      -1
*/

#include <stdio.h>
void nge(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                printf("%d : %d\n", arr[i], arr[j]);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("%d : %d\n", arr[i], -1);
    }
}

void main()
{
    int n;
    printf("Enter no of array : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter Array : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    nge(arr, n);
}