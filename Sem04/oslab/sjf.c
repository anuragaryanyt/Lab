#include <stdio.h>
void line(int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("-");
    }
    printf("\n");
}
int main()
{
    int n, burst_time[20], waiting_time[20], turnaround_time[20], i, j, temp, pos;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter total number of processes(maximum 20):");
    scanf("%d", &n);

    printf("\nEnter Process Burst Time:\n");
    for (i = 0; i < n; i++)
    {
        printf("P[%d]:", i + 1);
        scanf("%d", &burst_time[i]);
    }

    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (burst_time[j] < burst_time[pos])
                pos = j;
        }

        temp = burst_time[i];
        burst_time[i] = burst_time[pos];
        burst_time[pos] = temp;
    }

    waiting_time[0] = 0;
    for (i = 1; i < n; i++)
    {
        waiting_time[i] = 0;
        for (j = 0; j < i; j++)
            waiting_time[i] += burst_time[j];
    }
    printf("\n");
    line(65);
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    line(65);
    for (i = 0; i < n; i++)
    {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        avg_wt += waiting_time[i];
        avg_tat += turnaround_time[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\n");
    line(65);
    avg_wt /= i;
    avg_tat /= i;
    printf("\n\nAverage Waiting Time:%.2f", avg_wt);
    printf("\nAverage Turnaround Time:%.2f", avg_tat);

    return 0;
}

