/*Q7.WAP to remove a specific element from the array*/
#include <stdio.h>
int main()
{
    int array[100], position, i, size;

    printf("Enter number of elements in array\n");
    scanf("%d", &size);

    printf("Enter %d elements\n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &array[i]);

    printf("Enter the location where you wish to delete element\n");
    scanf("%d", &position);

    if (position >= size + 1)
        printf("Deletion not possible.\n");
    else
    {
        for (i = position - 1; i < size - 1; i++)
            array[i] = array[i + 1];

        printf("Final array after deletion :\n");

        for (i = 0; i < size - 1; i++)
            printf("%d\n", array[i]);
    }
    return 0;
}