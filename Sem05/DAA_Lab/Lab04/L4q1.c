/* Write a menu driven program to sort list of array elements using Merge Sort technique and calculate the execution time only to sort the elements. Count the number of comparisons. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int comparisons = 0;

void merge(int arr[], int left, int middle, int right, int *comparisons)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        (*comparisons)++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right, int *comparisons)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle, comparisons);
        mergeSort(arr, middle + 1, right, comparisons);
        merge(arr, left, middle, right, comparisons);
    }
}

// void time_complexity(int comparisons)
// {
//     if (comparisons<300)
//     {
//         printf("Scenario: Best-case");
//     }
//     else
//     {
//         printf("Scenario: Worst-case");
//     }
// }

int main()
{
    FILE *inputFile;
    int unsorted[300];

    while (1)
    {
        printf("MAIN MENU (INSERTION SORT)\n");
        printf("**************************\n");
        printf("1.Ascending Data\n");
        printf("2.Descending Data\n");
        printf("3.Random Data\n");
        printf("4.Exit\n");
        printf("**************************\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            clock_t start1 = clock();
            FILE *readAscending = fopen("inAsce.dat", "r");
            if (readAscending == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }
            for (int i = 0; i < 300; i++)
            {
                fscanf(readAscending, "%d", &unsorted[i]);
            }
            fclose(readAscending);

            mergeSort(unsorted, 0, 299, &comparisons);

            FILE *writeAscending = fopen("outMergeAsce.dat", "w");
            for (int i = 0; i < 300; i++)
            {
                fprintf(writeAscending, "%d\n", unsorted[i]);
            }
            fclose(writeAscending);

            printf("Before Sorting: Content in input file\n");
            printf("After Sorting: Content in output file\n");
            printf("No.of Comparisions: %d\n", comparisons);
            // time_complexity(comparisons);

            clock_t end1 = clock();
            printf("Elapsed: %.3f ns\n", ((double)(end1 - start1) / CLOCKS_PER_SEC) * 100);

            printf("\nDONE!!\n");
            break;
        }
        case 2:

        {
            clock_t start2 = clock();
            FILE *readDescending = fopen("inDesc.dat", "r");

            if (readDescending == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }

            for (int i = 0; i < 300; i++)
            {
                fscanf(readDescending, "%d", &unsorted[i]);
            }

            fclose(readDescending);

            mergeSort(unsorted, 0, 299, &comparisons);

            FILE *writeDescending = fopen("outMergeDesc.dat", "w");
            for (int i = 0; i < 300; i++)
            {
                fprintf(writeDescending, "%d\n", unsorted[i]);
            }
            fclose(writeDescending);

            printf("Before Sorting: Content in input file\n");
            printf("After Sorting: Content in output file\n");
            printf("No.of Comparisions: %d\n", comparisons);
            // time_complexity(comparisons);
            clock_t end2 = clock();
            printf("Elapsed: %.3f ns\n", ((double)(end2 - start2) / CLOCKS_PER_SEC) * 100);

            printf("\nDONE!!\n");
            break;
        }

        case 3:
        {
            clock_t start3 = clock();

            FILE *readRandom = fopen("inRand.dat", "r");
            if (readRandom == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }
            for (int i = 0; i < 300; i++)
            {
                fscanf(readRandom, "%d", &unsorted[i]);
            }
            fclose(readRandom);

            mergeSort(unsorted, 0, 299, &comparisons);

            FILE *writeRandom = fopen("outMergeRand.dat", "w");
            for (int i = 0; i < 300; i++)
            {
                fprintf(writeRandom, "%d\n", unsorted[i]);
            }
            fclose(writeRandom);

            printf("Before Sorting: Content in input file\n");
            printf("After Sorting: Content in output file\n");
            printf("No.of Comparisions: %d\n", comparisons);
            // time_complexity(comparisons);
            clock_t end3 = clock();
            printf("Elapsed: %.3f ns\n", ((double)(end3 - start3) / CLOCKS_PER_SEC) * 100);

            printf("\nDONE!!\n");
            break;
        }

        default:
            break;
        }
        if (choice == 4)
        {
            break;
        }
    }
    printf("\nSuccessfully Exited!!\n\n");
    return 0;
}

// void insertion(int arr[], int num, int *comparison)
// {
//     int j, i, temp;
//     *comparison=0;
//     for (int i = 1; i < num; i++)
//     {
//         temp = arr[i];
//         j = i - 1;
//         while (j >= 0 && temp <= arr[j])
//         {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//             (*comparison)++;
//         }
//         arr[j + 1] = temp;
//     }
// }
