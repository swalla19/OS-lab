#include <stdio.h>

// Structure to hold process details
struct Process {
    int pid;      // Process ID
    int bt;       // Burst Time
    int wt;       // Waiting Time
    int tat;      // Turnaround Time
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Input burst times
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter burst time for process P%d: ", proc[i].pid);
        scanf("%d", &proc[i].bt);
    }

    // Sort processes by burst time using selection sort
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (proc[j].bt < proc[min_idx].bt) {
                min_idx = j;
            }
        }
        // Swap processes
        struct Process temp = proc[min_idx];
        proc[min_idx] = proc[i];
        proc[i] = temp;
    }

    // Calculate waiting time and turnaround time
    proc[0].wt = 0;
    proc[0].tat = proc[0].bt;
    int total_wt = 0;
    int total_tat = proc[0].tat;

    for (int i = 1; i < n; i++) {
        proc[i].wt = proc[i-1].wt + proc[i-1].bt;
        proc[i].tat = proc[i].wt + proc[i].bt;
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
    }

    // Display results
    printf("\nProcesses Order of Execution: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", proc[i].pid);
    }
    printf("\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, proc[i].wt, proc[i].tat);
    }

    printf("\nAverage waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);

    return 0;
}

