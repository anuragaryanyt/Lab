/*Q3. WAP to find largest and smallest element stored in an array.*/

#include <stdio.h>
int main()
{
    int arr[100], i, size, large, small;

    printf("\nEnter the number of elements in array-- ");   //size of the array
    scanf("%d", &size);
    
    printf("\nEnter the elements of array-- ");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);                 //taking input 

    large = small = arr[0];                  

    for (i = 1; i < size; i++)
    {
        if (arr[i] > large)                   //checking for large no.
            large = arr[i];

        if (arr[i] < small)                  //checking for small no.
            small = arr[i];
    }

    printf("\nThe smallest element is-- %d", small);
    printf("\nThe largest element is-- %d", large);

    return 0;
}