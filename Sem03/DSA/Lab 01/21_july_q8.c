//Q8.WAP to insert a new element in a specified position in the array.
#include <stdio.h>
int main()
{
    int array[50], position, i, size, value;

    printf("Enter number of elements in the array--");
    scanf("%d", &size);

    printf("Enter %d elements\n", size);

    for (i = 0; i < size; i++)
        scanf("%d", &array[i]);

    printf("\n Please enter the location where you want to insert an new element --");
    scanf("%d", &position);

    if (position > size + 1)
        printf("Addition of array not possible.\n");
    else
    {
        printf("Please enter the value\n");
        scanf("%d", &value);

        for (i = size - 1; i >= position - 1; i--)
            array[i + 1] = array[i];

        array[position - 1] = value;

        printf("Resultant array is\n");

        for (i = 0; i <= size; i++)
            printf("%d\n", array[i]);
    }
    return 0;
}