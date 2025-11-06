Exp1 
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst[n], arrival[n];
    printf("Assuming arrival time = 0 for all processes.\n");

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst[i]);
        arrival[i] = 0; // all arrival times = 0
    }

    // matrix[i][0] = burst
    // matrix[i][1] = waiting time
    // matrix[i][2] = turnaround time
    int matrix[n][3];
    int global_time = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            
            if (j == 0) {  
                matrix[i][0] = burst[i];
            }

            if (j == 1) {  
                matrix[i][1] = global_time - arrival[i];   // waiting time
            }

            if (j == 2) {  
                matrix[i][2] = matrix[i][0] + matrix[i][1]; // turnaround
                global_time += burst[i]; // update global CPU time
            }
        }
    }

    printf("\nP\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, matrix[i][0], matrix[i][1], matrix[i][2]);
    }

    // find averages
    int total_wt = 0, total_tt = 0;
    for (int i = 0; i < n; i++) {
        total_wt += matrix[i][1];
        total_tt += matrix[i][2];
    }

    float avg_wt = (float) total_wt / n;
    float avg_tt = (float) total_tt / n;

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tt);

    return 0;
}
