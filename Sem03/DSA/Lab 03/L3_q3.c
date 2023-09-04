// Q3. WAP to find the Trace(sum of the diagonal element) of a given mxn matrix using function .

#include <stdio.h>
int trace(int n, int arr[][n])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i][i];
    return sum;
}

void main()
{
    int n;
    printf("Enter order of the matrix: ");
    scanf("%d", &n);

    int arr[n][n];
    printf("Enter Matrix  :\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    int res = trace(n, arr);
    printf("Trace of the matrix: %d\n", res);
}