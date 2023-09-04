#include <stdio.h>
struct fcfs
{
    int pid, arrival, burst, turnaround, wt;
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
    float avg = 0.0;
    int sum = 0.0;
    struct fcfs f[10], temp;
    printf("Enter the total number of processes: ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &f[i].arrival);
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &f[i].burst);
        f[i].pid = i + 1;
    }
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (f[j].arrival > f[j + 1].arrival)
            {
                temp = f[j];
                f[j] = f[j + 1];
                f[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        sum = sum + f[i].burst;
        f[i].turnaround = sum;
    }
    sum = 0;
    line(40);
    printf("PID\tArrival\tBurst\tTurnaround\n");
    line(40);
    for (int i = 0; i < num; i++)
    {
        printf("%d\t%d\t%d\t%d\n", f[i].pid, f[i].arrival, f[i].burst, f[i].turnaround);
        sum += f[i].turnaround;
    }
    line(40);
    avg = sum / (float)num;
    printf("\nTotal Turnaround time: %f.", sum);
    printf("\nAverage Turnaround time: %.3f.", avg);
}
