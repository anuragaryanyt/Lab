// Q2. Write a program to multiply two matrices and display it using function.

#include <stdio.h>
void multiply(int m, int n, int k, int a[][n], int b[][k], int c[][k])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int sum = 0;
            for (int p = 0; p < n; p++)
                sum += a[i][p] * b[p][j];

            c[i][j] = sum;
        }
    }
    printf("\n\nDisplay : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
            printf("%d\t", c[i][j]);
        printf("\n");
    }
}
void main()
{
    int m, n, k;
    printf("Enter value of m : ");
    scanf("%d", &m);
    printf("Enter value of n : ");
    scanf("%d", &n);
    printf("Enter value of k : ");
    scanf("%d", &k);

    int a[m][n], b[n][k], c[m][k];

    printf("Enter Matrix A :\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter Matrix B :\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            scanf("%d", &b[i][j]);

    multiply(m, n, k, a, b, c);
}