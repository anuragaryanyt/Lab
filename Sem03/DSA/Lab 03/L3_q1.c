// Q1. Write a program to add two matrices and display it using function.


#include <stdio.h>
void add(int col, int res[][col], int a[][col], int b[][col], int row)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            res[i][j] = a[i][j] + b[i][j];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d\t", res[i][j]);
        printf("\n");
    }
}

void main()
{
    int row, col;
    printf("Enter the no of Row: ");
    scanf("%d", &row);
    printf("Enter the no of Column: ");
    scanf("%d", &col);

    int a[row][col], b[row][col], res[row][col];

    printf("Enter the elements of Array 1 : \n");
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the elements of Array 2 : \n");
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &b[i][j]);

    add(col, res, a, b, row);
}