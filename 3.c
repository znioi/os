Exp3 Round robin 
#include <stdio.h>

int main() {
    int np;
    printf("Enter the number of processes: ");
    scanf("%d", &np);

    int time_slice;
    printf("Enter the time slice: ");
    scanf("%d", &time_slice);

    int arrival[np], burst_process[np], rem_bt[np];
    int wt[np], tat[np];

    for (int i = 0; i < np; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_process[i]);

        arrival[i] = 0;               // assuming arrival = 0
        rem_bt[i] = burst_process[i]; // remaining time
        wt[i] = 0;
        tat[i] = 0;
    }

    int time = 0;

    while (1) {

        int done = 1;

        for (int i = 0; i < np; i++) {

            if (rem_bt[i] > 0) {
                done = 0;

                if (rem_bt[i] > time_slice) {
                    time += time_slice;
                    rem_bt[i] -= time_slice;
                }
                else {
                    time += rem_bt[i];
                    wt[i] = time - burst_process[i];   // waiting time
                    rem_bt[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }

    for (int i = 0; i < np; i++) {
        tat[i] = burst_process[i] + wt[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < np; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n",
