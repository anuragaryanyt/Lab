/* Write a menu driven program to sort a list of elements in ascending order using Quick Sort technique. Each choice for the input data has its own disc file.  A separate output file can be used for sorted elements. After sorting display the content of the output file along with number of comparisons. Based on the partitioning position for each recursive call, conclude the input scenario is either best-case partitioning or worst-case partitioning. */

#include <stdio.h>
int comparisons = 0;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        comparisons++;
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
void time_complexity(int comparisons)
{
    if (comparisons < 80000)
    {
        printf("Execution time: Best Case");
    }
    else
    {
        printf("Execution time: Worst Case");
    }
}
int main()
{
    FILE *inputFile;
    int unsorted[300];
    while (1)
    {
        printf("MAIN MENU (QUICK SORT)\n");
        printf("--------------------------\n");
        printf("1.Ascending Data\n");
        printf("2.Descending Data\n");
        printf("3.Random Data\n");
        printf("4.Error\n");
        printf("--------------------------\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
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

            quickSort(unsorted, 0, 300 - 1);

            FILE *writeAscending = fopen("outQuickAsce.dat", "w");
            for (int i = 0; i < 300; i++)
            {
                fprintf(writeAscending, "%d\n", unsorted[i]);
            }
            fclose(writeAscending);

            printf("Before Sorting: Content in input file\n");
            printf("After Sorting: Content in output file\n");
            printf("No.of Comparisions: %d\n", comparisons);
            time_complexity(comparisons);

            printf(".\n.\n.\nDONE!!\n\n");
            break;
        case 2:
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

            quickSort(unsorted, 0, 300 - 1);

            FILE *writeDescending = fopen("outQuickDesc.dat", "w");
            for (int i = 0; i < 300; i++)
            {
                fprintf(writeDescending, "%d\n", unsorted[i]);
            }
            fclose(writeDescending);

            printf("Before Sorting: Content in input file\n");
            printf("After Sorting: Content in output file\n");
            printf("No.of Comparisions: %d\n", comparisons);
            time_complexity(comparisons);

            printf(".\n.\n.\nDONE!!\n\n");
            break;

        case 3:

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

            quickSort(unsorted, 0, 300 - 1);

            FILE *writeRandom = fopen("outQuickRand.dat", "w");
            for (int i = 0; i < 300; i++)
            {
                fprintf(writeRandom, "%d\n", unsorted[i]);
            }
            fclose(writeRandom);

            printf("Before Sorting: Content in input file\n");
            printf("After Sorting: Content in output file\n");
            printf("No.of Comparisions: %d\n", comparisons);
            time_complexity(comparisons);

            printf(".\n.\n.\nDONE!!\n\n");
            break;

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

