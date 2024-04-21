#include <stdio.h>

void bubbleSort(float arr[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                // Swap the elements
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting in decreasing order\n");
    for (i = 0; i < size; i++)
    {
        printf("%.2f\t", arr[i]);
    }
    printf("\n\n");
}

void rearrangeArrays(double arr1[], double arr2[], double arr3[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr3[i] < arr3[j]) {
                // Swap elements in arr3
                double temp3 = arr3[i];
                arr3[i] = arr3[j];
                arr3[j] = temp3;
                
                // Swap corresponding elements in arr1
                double temp1 = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp1;
                
                // Swap corresponding elements in arr2
                double temp2 = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp2;
            }
        }
    }
}


int main()
{
    int x = 10, size = 5;
    int i, y = 0;

    float p[] = {100, 50, 30, 60, 30};
    float w[] = {5, 2, 10, 7, 2};
    float a[size];
    for (int i = 0; i < size; i++)
    {
        a[i] = p[i] / w[i];
    }

    printf("Result Array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%.1f\n", a[i]);
    }

    bubbleSort(a, size);

    rearrangeArrays(p,w, a, size);
    
    // Print the arranged arrays
    printf("Arranged Arrays:\n");
    for (int i = 0; i < size; i++) {
        printf("array1[%d] = %.2lf, array2[%d] = %.2lf, resultArray[%d] = %.2lf\n",
               i, p[i], i, w[i], i, a[i]);
    }

   

    // for (i = 0; i < size; i++)
    // {
    //     if (w[i] <= x)
    //     {
    //         y = y + p[i];
    //         printf("y= %d\n", y);
    //         x = x - w[i];
    //         printf("x= %d\n", x);
    //     }
    //     else
    //         break;
    // }
    // if( i<size && y!=0)
    // {
    //     y=y+(x/w[i])*p[i];
    // }

    return 0;
}
