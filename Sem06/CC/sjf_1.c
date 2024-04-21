#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int arrival;
    int burst;
    int turnaround;
    int waiting;
    int finish;
} process;

void input(process *p, int n)
{
    printf("Enter process data: \n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process: %d\n", i);
        printf("Arrival time: ");
        scanf("%d", &p[i].arrival);
        printf("Burst time: ");
        scanf("%d", &p[i].burst);
        p[i].finish = 0;
        printf("\n");
    }
}

void execute(process *p, int n)
{
    int time = 0;
    int p_count = 0;
    int min_bt, min, index;

    while (p_count < n)
    {
        min = INT_MAX;
        index = -1;
        for (int i = 0; i < n; i++)
        {
            if (p_count == 0)
            {
                if (p[i].arrival < min && p[i].finish == 0)
                {
                    min = p[i].arrival;
                    index = i;
                }
            }
            else
            {
                if (p[i].arrival <= time && p[i].burst < min && p[i].finish == 0)
                {
                    min = p[i].burst;
                    index = i;
                }
            }
        }
        // printf("Selected index: %d\n", index);

        if (index == -1)
        {
            min = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                if (p[i].arrival < min && p[i].finish == 0)
                {
                    min = p[i].arrival;
                    index = i;
                }
            }
            // printf("Selected index: %d\n", index);
        }

        if (p[index].arrival > time)
        {
            time = p[index].arrival;
        }

        time += p[index].burst;
        p[index].turnaround = time - p[index].arrival;
        p[index].waiting = p[index].turnaround - p[index].burst;
        p[index].finish = 1;
        p_count++;
    }
}

void display(process *p, int n)
{
    float avg_tat = 0.0, avg_wt = 0.0;
    printf("Displaying final output: \n");
    printf("Process_no.\tArrival_time\tCPU_burst_time\tTurn_around_time   Waiting_time\n");

    for (int i = 0; i < n; i++)
    {
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, p[i].arrival, p[i].burst, p[i].turnaround, p[i].waiting);
        avg_tat += p[i].turnaround;
        avg_wt += p[i].waiting;
    }

    printf("\nAverage Waiting Time : %.2f", avg_wt / n);
    printf("\nAverage Turn_Around Time : %.2f", avg_tat / n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process *p = (process *)malloc(n * sizeof(process));
    input(p, n);
    printf("Execution order: ");
    execute(p, n);
    printf("\n");
    display(p, n);
    return 0;
}
