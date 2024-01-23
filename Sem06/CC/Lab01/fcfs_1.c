#include <stdio.h>
struct fcfs
{
    int pid;
    int arrival;
    int burst;
    int waiting;
    int turnaround;
    int start;
    int end;
};
void line(int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("-");
    }
    printf("\n");
}

void main()
{
    int num;
    float turnavg = 0.0, turnsum = 0.0, waitsum = 0.0;
    printf("Enter the total number of processes: ");
    scanf("%d", &num);

    struct fcfs f[20], temp;

    for (int i = 0; i < num; i++)
    {
        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &f[i].arrival);
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &f[i].burst);
        f[i].pid = i + 1;
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (f[j].arrival < f[i].arrival)
            {
                temp = f[j];
                f[j] = f[i];
                f[i] = temp;
            }
        }
    }

    for (int i = 0; i < num; i++)
    {
        f[i].start = turnsum > f[i].arrival ? turnsum : f[i].arrival;
        turnsum = f[i].start + f[i].burst;
        f[i].end = turnsum;
        f[i].turnaround = f[i].end - f[i].arrival;
        f[i].waiting = f[i].turnaround - f[i].burst;
    }

    turnsum = 0;
    line(50);
    printf("PID\tArrival\tBurst\tStart\tEnd\tWaiting\tTurnaround\n");
    line(50);
    for (int i = 0; i < num; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", f[i].pid, f[i].arrival, f[i].burst, f[i].start, f[i].end, f[i].waiting, f[i].turnaround);
        turnsum += f[i].turnaround;
        waitsum += f[i].waiting;
    }
    line(50);
    turnavg = turnsum / (float)num;
    printf("\nAverage Turnaround time: %.3f.", turnavg);
    printf("\nAverage Waiting time: %.3f.", waitsum / 5.0);
}
