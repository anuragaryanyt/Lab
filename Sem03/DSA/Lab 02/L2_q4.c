/* Given an unsorted array of size n, WAP to find and display the number of elements between two elements a and b (both inclusive). E.g. Input : arr = [1, 2, 2, 7, 5, 4], a=2 and b=5, Output : 4 and the numbers are: 2, 2, 7, 5.*/

#include <stdio.h>
void main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter Array : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int a, b;
    printf("Enter Value of a : ");
    scanf("%d", &a);
    printf("Enter Value of b : ");
    scanf("%d", &b);

    int c = 0;
    int flag = 0;
    int present = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
            flag = 1;

        if (flag == 1)
        {
            present = 1;
            printf("%d\t", arr[i]);
        }

        if (arr[i] == b && flag == 1)
            break;
    }
    if (present == 0)
        printf("Element not found");
}