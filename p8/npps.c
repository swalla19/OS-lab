#include <stdio.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int priority;
    int waiting;
    int turnaround;
    int completed;
};

int main() {
    int n, completed = 0, time = 0;
    float total_waiting = 0, total_turnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        p[i].pid = i + 1;
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst);
        printf("Priority (Lower number = Higher priority): ");
        scanf("%d", &p[i].priority);
        p[i].completed = 0;
    }

    int gantt_pid[n];
    int gantt_time[n + 1];
    int gantt_index = 0;

    gantt_time[0] = 0;

    while(completed < n) {
        int idx = -1;
        int highest_priority = 9999;

        for(int i = 0; i < n; i++) {
            if(p[i].arrival <= time && p[i].completed == 0) {
                if(p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            gantt_pid[gantt_index] = p[idx].pid;

            time += p[idx].burst;

            gantt_index++;
            gantt_time[gantt_index] = time;

            p[idx].turnaround = time - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;

            total_waiting += p[idx].waiting;
            total_turnaround += p[idx].turnaround;

            p[idx].completed = 1;
            completed++;
        } else {
            time++;  // CPU idle
        }
    }

    // Print Gantt Chart
    printf("\n\nGantt Chart:\n");

    printf(" ");
    for(int i = 0; i < gantt_index; i++)
        printf("--------");
    printf("\n|");

    for(int i = 0; i < gantt_index; i++)
        printf("  P%d   |", gantt_pid[i]);

    printf("\n ");
    for(int i = 0; i < gantt_index; i++)
        printf("--------");
    printf("\n");

    for(int i = 0; i <= gantt_index; i++)
        printf("%-8d", gantt_time[i]);

    printf("\n");

    // Print table
    printf("\nPID\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].priority,
               p[i].waiting,
               p[i].turnaround);
    }

    printf("\nAverage Waiting Time = %.2f", total_waiting / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_turnaround / n);

    return 0;
}

