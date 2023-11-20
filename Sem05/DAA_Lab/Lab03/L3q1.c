/* Write a program to implement Binary Search to give the position of leftmost appearance of the element in the array being searched. Display the number of comparisons made while searching. */

#include <stdio.h>

int bin_search(int arr[], int size, int key, int *comparisons)
{
    int left = 0;
    int right = size - 1;
    int position = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        (*comparisons)++;

        if (arr[mid] == key)
        {
            position = mid;
            right = mid - 1;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return position;
}

int main()
{
    int size;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    int sorted_array[size];

    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &sorted_array[i]);
    }

    int key_element;
    printf("Enter the key element to search: ");
    scanf("%d", &key_element);

    int comparisons = 0;
    int position = bin_search(sorted_array, size, key_element, &comparisons);

    if (position != -1)
    {
        printf("Element %d found at index %d \n", key_element, position);
        printf("No of comparisons: %d \n", comparisons);
    }
    else
    {
        printf("Element %d not found with %d comparisons.\n", key_element, comparisons);
    }
    
    return 0;
}
