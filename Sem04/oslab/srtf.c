// SRTF

#include <stdio.h>

int main()
{

    int n, arr[10], b[10], total = 0, i, j, small, temp, procs[100], k, waiting[10], finish[10];
    float tavg = 0.0, wavg = 0.0;

    printf("ENTER THE NUMBER OF PROCESSES:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("ENTER THE ARRIVAL TIME OF PROCESS %d:\t", i);
        scanf("%d", &arr[i]);
        printf("ENTER THE BURST TIME OF PROCESS %d:\t", i);
        scanf("%d", &b[i]);
        waiting[i] = 0;
        total += b[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    for (i = 0; i < total; i++)
    {
        small = 10000;
        for (j = 0; j < n; j++)
        {
            if ((b[j] != 0) && (arr[j] <= i) && (b[j] < small))
            {
                small = b[j];
                k = j;
            }
        }
        b[k]--;
        procs[i] = k;
    }
    k = 0;
    for (i = 0; i < total; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (procs[i] == j)
            {
                finish[j] = i;
                waiting[j]++;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("\n PROCESS %d:-COMPLETION TIME==> %d TURNAROUND TIME==>%d WAITING TIME==>%d\n", i + 1, finish[i] + 1, (finish[i] - arr[i]) + 1, (((finish[i] + 1) - waiting[i]) - arr[i]));
        wavg = wavg + (((finish[i] + 1) - waiting[i]) - arr[i]);
        tavg = tavg + ((finish[i] - arr[i]) + 1);
    }
    printf("\n Avg WT==>\t%f\n Avg TAT==>\t%f\n", (wavg / n), (tavg / n));
    return 0;
}