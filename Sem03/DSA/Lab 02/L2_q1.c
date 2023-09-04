// WAP to reverse the contents of a array of n elements.

#include <stdio.h>

void main()
{
    int a[100], reverse[100], i, n;

    printf("\nEnter no of elements - \n");
    scanf("%d", &n);

    printf("Enter the elements - \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        reverse[i] = a[n - i - 1];
    }

    printf("\n Reversed array - \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", reverse[i]);
    }
}