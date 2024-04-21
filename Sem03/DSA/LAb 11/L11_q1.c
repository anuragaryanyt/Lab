//Selection Sort.

#include<stdio.h>
#define Size 5
int main()
{
    int arr[Size];       

    printf("Enter Array Elements : ");
    for (int i = 0;i < Size;i++)
        scanf("%d", &arr[i]);

    for (int i = 0;i < Size;i++)
    {
        int min = i;
        for (int j = i + 1;j < Size;j++)
            if (arr[j] < arr[min])
                min = j;

        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    printf("\nSorted Array : ");
    for (int i = 0;i < Size;i++)
        printf("%d\t", arr[i]);
}
