/* Write a program to find out the second smallest and second largest element stored in an array of n integers.
Input: Size of the array is ‘n’ and read ‘n’ number of elements from a disc file.
Output: Second smallest, Second largest */

#include <stdio.h>
int main()
{
    FILE *ptr;
    char ch;

    ptr = fopen("L1q1.txt", "r");
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        fscanf(ptr, "%d", &a[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        int temp;
        for (int j = i + 1; j < 5; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("The second smallest element: %d\n", a[3]);
    printf("The second largest element: %d\n", a[1]);
    return 0;
}

//     int n_986;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n_986);
//     printf("Enter the array elements:\n");
//     int a[n_986];
//     for (int i = 0; i < n_986; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//     for (int i = 0; i < n_986; i++)
//     {
//         int temp;
//         for (int j = i + 1; j < n_986; j++)
//         {
//             if (a[i] < a[j])
//             {
//                 temp = a[i];
//                 a[i] = a[j];
//                 a[j] = temp;
//             }
//         }
//     }
//     printf("The second smallest element: %d\n", a[n_986 - 2]);
//     printf("The second largest element: %d", a[1]);
//     return 0;
// }
