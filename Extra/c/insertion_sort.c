#include <stdio.h>

int insertion(int arr[])
{
    int i = 1, j, temp;
    while (i < 6)
    {
        j = i;
        while (j >= 1)
        {
            if (arr[j - 1] > arr[j])    //here a[j-1] represent the array position intially it will be 0 as i=1 and the element is compared after that
            {
                //swap
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
            j = j - 1;
        }
        i = i + 1;
    }

    printf("Sorted array is: ");
    for (i = 0; i < 6; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    // int n;
    int arr[6] = {20, 60, 30, 90, 10, 50};

    insertion(arr);

    return 0;
}



// int insertion(int arr[])
// {
//     int i, key, j;
//     for (i = 1; i < 6; i++)
//     {
//         key = arr[i];
//         j = i - 1;

//         while (j >= 0 && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }

//     printf("Sorted array is: ");
//     for (i=0;i<6;i++)
//     {
//         printf("%d\t",arr[i]);
//     }
//     printf("\n");

// }
