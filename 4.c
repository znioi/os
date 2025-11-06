Exp 4 Priority Scheduling (Non-Preemptive)
#include <stdio.h>

struct Process {
    int id;
    int at;          // arrival time
    int bt;          // burst time
    int pr;          // priority
    int wt;          // waiting time
    int tat;         // turnaround time
    int completed;   // completion flag
};

int main() {

    int n, time = 0, completed = 0;
    float avgTAT = 0, avgWT = 0;

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;

        printf("\nProcess %d\n", i + 1);

        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].at);

        printf("Enter Burst Time: ");
        scanf("%d", &p[i].bt);

        printf("Enter Priority: ");
        scanf("%d", &p[i].pr);

        p[i].completed = 0;
    }

    printf("\nGantt Chart Order:\n");

    while (completed < n) {

        int idx = -1;
        int minP = 9999;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].completed == 0) {

                if (p[i].pr < minP) {
                    minP = p[i].pr;
                    idx = i;
                }
                else if (p[i].pr == minP) {
                    // break tie using arrival time
                    if (p[i].at < p[idx].at) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {

            time += p[idx].bt;

            p[idx].tat = time - p[idx].at;
            p[idx].wt  = p[idx].tat - p[idx].bt;

            p[idx].completed = 1;
            completed++;

            printf("P%d ", p[idx].id);

            avgTAT += p[idx].tat;
            avgWT  += p[idx].wt;
        }
        else {
            time++;
        }
    }

    avgTAT /= n;
    avgWT  /= n;

    printf("\n\nProcess\tAT\tBT\tPriority\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               p[i].id, p[i].at, p[i].bt, p[i].pr, p[i].tat, p[i].wt);
    }

    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);
    printf("Average Waiting Time = %.2f\n", avgWT);

    return 0;
}
