// Write a program to read ‘n’ integers from a disc file that must contain some duplicate values and store them into an array. Perform the following operations on the array.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    int i = 0;
    printf("Enter the no. of elements to be read from file:");
    scanf("%d", &n);
    int arr[n];
    FILE *fptr;
    fptr = fopen("3.txt", "r");
    char c;
    if (fptr == NULL)
    {
        printf("file cant be open");
    }
    else
    {
        do
        {
            fscanf(fptr, "%d ", &arr[i]);
            i++;
        } while (!feof(fptr) && i != n);
    }
    if (i != n)
    {
        printf("Not enough elements in the file");
    }
    else
    {
        int temp = 0, a = 1, max = 0, element = arr[0], dup = 0;
        printf("\nThe %d elements in the file are:", n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            a = 1;
            for (int j = 0; j < n - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    a = 0;
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            if (a == 1)
            {
                break;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                temp++;
            }
            else
            {
                temp = 0;
            }
            if (temp > max)
            {
                max = temp;
                element = arr[i];
            }
            if (temp == 1)
            {
                dup++;
            }
        }
        printf("\ntotal number of duplicate elements : %d", dup);
        printf("\nthe most repeating element is : %d", element);
    }

    fclose(fptr);
}

