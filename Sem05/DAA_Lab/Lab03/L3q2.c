/* Write a menu driven program to sort a list of elements in ascending order using Insertion Sort technique. The nature of the input data is choice based and a distinct file is considered for each choice. The sorted elements can be stored in a separate output file. After sorting display the content of the output file along with number of comparisons. Based on the number of comparisons, conclude the input scenario is either best or worst case. */

#include <stdio.h>

void insertion(int arr[], int num, int *comparison)
{
    int j, i, temp;
    *comparison = 0;
    for (int i = 1; i < num; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && temp <= arr[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*comparison)++;
        }
        arr[j + 1] = temp;
    }
}

void time_complexity(int comparisons)
{
    if (comparisons < 300)
    {
        printf("Scenario: Best-case");
    }
    else
    {
        printf("Scenario: Worst-case");
    }
}

int main()
{
    FILE *inputFile;
    int unsorted[300];
    int comparisons;
    while (1)
    {
        printf("MAIN MENU (INSERTION SORT)\n");
        printf("--------------------------\n");
        printf("1.Ascending Data\n");
        printf("2.Descending Data\n");
        printf("3.Random Data\n");
        printf("4.Exit\n");
        printf("--------------------------\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
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

            insertion(unsorted, 300, &comparisons);

            FILE *writeAscending = fopen("outInsAsce.dat", "w");
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
        }
        case 2:
        {
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

            insertion(unsorted, 300, &comparisons);

            FILE *writeDescending = fopen("outInsDesc.dat", "w");
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
        }
        case 3:
        {

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

            insertion(unsorted, 300, &comparisons);

            FILE *writeRandom = fopen("outInsRand.dat", "w");
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
