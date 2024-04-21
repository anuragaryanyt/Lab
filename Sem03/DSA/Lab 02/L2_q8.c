/*
Let A be nXn square matrix. WAP by using appropriate user defined functions for the following:
a) Find the number of nonzero elements in A
b) Find the sum of the elements above the leading diagonal.
c) Display the elements below the minor diagonal.
d) Find the product of the diagonal elements.
*/

#include <stdio.h>
int n;
void nonzero(int A[][n])
{
    int c = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] != 0)
                c++;

    printf("Total Number of Non Zero Element: %d\n", c);
}

void sum(int A[][n])
{
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            res += A[i][j];

    printf("\nSum of elements above leading diagonal: %d\n", res);
}
void disp(int A[][n])
{
    printf("\nElements below the minor diagonal : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1 - i; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

void product(int A[][n])
{
    int prod = 1;

    for (int i = 0; i < n; i++)
        prod *= A[i][i];

    printf("\nProduct of diagonal elements: %d\n", prod);
}

void main()
{
    printf("Enter the no of array: ");
    scanf("%d", &n);

    int A[n][n];
    printf("Enter Array : \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    printf("\n\n");
    nonzero(A);
    sum(A);
    disp(A);
    product(A);
}