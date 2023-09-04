/* Write a menu driven program to sort a list of elements in ascending order using Insertion Sort technique. The nature of the input data is choice based and a distinct file is considered for each choice. The sorted elements can be stored in a separate output file. After sorting display the content of the output file along with number of comparisons. Based on the number of comparisons, conclude the input scenario is either best or worst case.  */

#include <stdio.h>

void insertion_sort(int arr[], int size, int *comparisons)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void display_file_contents(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Unable to open the file.\n");
        return;
    }

    int value;
    printf("Contents of %s:\n", filename);
    while (fscanf(file, "%d", &value) != EOF)
    {
        printf("%d ", value);
    }
    printf("\n");

    fclose(file);
}

int main()
{
    int choice;
    int comparisons = 0;
    const char *input_files[] = {"inAsce.dat", "inDesc.dat", "inRand.dat"};
    const char *output_files[] = {"outInsAsce.dat", "outInsDesc.dat", "outInsRand.dat"};

    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3)
    {
        printf("Exiting the program.\n");
        return 0;
    }

    FILE *input_file = fopen(input_files[choice - 1], "r");
    if (input_file == NULL)
    {
        printf("Unable to open the input file.\n");
        return 1;
    }

    int size;
    fscanf(input_file, "%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        fscanf(input_file, "%d", &arr[i]);
    }

    fclose(input_file);

    insertion_sort(arr, size, &comparisons);

    FILE *output_file = fopen(output_files[choice - 1], "w");
    if (output_file == NULL)
    {
        printf("Unable to open the output file.\n");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(output_file, "%d ", arr[i]);
    }
    fclose(output_file);

    printf("Sorted elements written to %s.\n", output_files[choice - 1]);
    printf("Number of comparisons: %d\n", comparisons);

    // Display the content of the output file
    display_file_contents(output_files[choice - 1]);

    // Determine if it's a best or worst case scenario based on comparisons
    if (comparisons == (size - 1) * size / 2)
    {
        printf("This is a worst case scenario.\n");
    }
    else if (comparisons == size - 1)
    {
        printf("This is a best case scenario.\n");
    }
    else
    {
        printf("This is an average case scenario.\n");
    }

    return 0;
}

