#include <stdio.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int priority;
    int completion;
    int waiting;
    int turnaround;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nProcess %d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst);

        printf("Priority (Lower number = Higher priority): ");
        scanf("%d", &p[i].priority);

        p[i].remaining = p[i].burst;
    }

    int completed = 0, time = 0;
    float total_waiting = 0, total_turnaround = 0;

    int gantt[1000];   // stores PID at each time unit
    int gantt_index = 0;

    while(completed < n) {
        int idx = -1;
        int highest_priority = 9999;

        for(int i = 0; i < n; i++) {
            if(p[i].arrival <= time && p[i].remaining > 0) {
                if(p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            p[idx].remaining--;
            gantt[gantt_index++] = p[idx].pid;
            time++;

            if(p[idx].remaining == 0) {
                p[idx].completion = time;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;

                total_waiting += p[idx].waiting;
                total_turnaround += p[idx].turnaround;

                completed++;
            }
        } else {
            gantt[gantt_index++] = 0; // Idle
            time++;
        }
    }

    // Print Gantt Chart
    printf("\nGantt Chart:\n ");

    for(int i = 0; i < gantt_index; i++)
        printf("----");
    printf("\n|");

    for(int i = 0; i < gantt_index; i++) {
        if(gantt[i] == 0)
            printf(" ID |");
        else
            printf(" P%d |", gantt[i]);
    }

    printf("\n ");
    for(int i = 0; i < gantt_index; i++)
        printf("----");

    printf("\n0");
    for(int i = 1; i <= gantt_index; i++)
        printf("    %d", i);

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

