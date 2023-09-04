#include <stdio.h>

typedef struct {
    int pid;
    int burst_time;   
    int arrival_time;  
    int waiting_time;  
    int turnaround_time;  
    int completed;  
} process;

int main() {
    int n, i, j, time = 0, shortest, completed = 0;
    float avg_wt = 0, avg_tat = 0;

    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    
    process processes[n];
    process temp;

    printf("Enter the burst time and arrival time for each process:\n");
    for (i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Process %d: ", processes[i].pid);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
        processes[i].completed = 0;
    }
   
    while (completed < n) {
        shortest = -1;
        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].completed == 0) {
                if (shortest == -1 || processes[i].burst_time < processes[shortest].burst_time) {
                    shortest = i;
                }
            }
        }
        if (shortest == -1) {
            time++;
        } else {
            processes[shortest].waiting_time = time - processes[shortest].arrival_time;
            processes[shortest].turnaround_time = processes[shortest].waiting_time + processes[shortest].burst_time;
            avg_wt += processes[shortest].waiting_time;
            avg_tat += processes[shortest].turnaround_time;
            processes[shortest].completed = 1;
            completed++;
            time += processes[shortest].burst_time;
        }
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average waiting time: %.2f\n", avg_wt);
    printf("Average turnaround time: %.2f\n", avg_tat);

    return 0;
}

