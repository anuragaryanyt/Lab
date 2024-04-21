// Insertion Sort

#include <stdio.h>
#define Size 5
int main()
{
    int arr[Size];
    printf("Enter Array Elements : ");
    for (int i = 0; i < Size; i++)
        scanf("%d", &arr[i]);

    for (int i = 1; i < Size; i++)
    {
        int j = i - 1;
        int cp = arr[i]; // copy elements
        while (j >= 0 && arr[j] > cp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = cp;
    }
    printf("\nSorted Array : ");
    for (int i = 0; i < Size; i++)
        printf("%d\t", arr[i]);
}
