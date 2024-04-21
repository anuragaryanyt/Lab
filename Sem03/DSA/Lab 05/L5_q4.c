// Write a program to represent a sparse matrix in three tuple format using an array and perform addition.

#include <stdio.h>
void main()
{
    int m, n, count = 0, sum = 0, x = 0;
    printf("Enter the dimensions: ");
    scanf("%d %d", &m, &n);
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Element %d , %d : ", i, j);
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
                count++;
        }
    }
    int b[count][3];
    b[x][0] = m;
    b[x][1] = n;
    b[x][2] = 0;
    x++;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                b[x][0] = i;
                b[x][1] = j;
                b[x][2] = a[i][j];
                x++;
            }
        }
    }

    for (int i = 1; i <= count; i++)
        b[0][2] += b[i][2];

    printf("\nThe sum is %d.\n", b[0][2]);
}
