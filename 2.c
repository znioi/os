Exp 2 Shortest Job First) — Non-Preemptive
#include <stdio.h>

void sorting(int Arr[][3], int n) {
    int i, j;
    int temp[3];

    for (j = 1; j < n; j++) {
        temp[0] = Arr[j][0];   // job id
        temp[1] = Arr[j][1];   // burst time
        temp[2] = Arr[j][2];   // arrival (0)

        i = j - 1;

        while (i >= 0 && Arr[i][1] > temp[1]) {   // sort by burst time
            Arr[i + 1][0] = Arr[i][0];
            Arr[i + 1][1] = Arr[i][1];
            Arr[i + 1][2] = Arr[i][2];
            i--;
        }

        Arr[i + 1][0] = temp[0];
        Arr[i + 1][1] = temp[1];
        Arr[i + 1][2] = temp[2];
    }
}

int main() {
    int nj;
    printf("Enter the number of jobs: ");
    scanf("%d", &nj);

    int jobs[nj][3]; 
    // jobs[i][0] = job id
    // jobs[i][1] = burst time
    // jobs[i][2] = arrival = 0

    for (int i = 0; i < nj; i++) {
        printf("\nEnter burst time for Job %d: ", i + 1);
        scanf("%d", &jobs[i][1]);
        jobs[i][2] = 0;        // arrival time
        jobs[i][0] = i + 1;    // job number
    }

    // sort jobs by burst time (SJF)
    sorting(jobs, nj);

    int matrix[nj][3];
    int global_time = 0;

    // matrix[i][0] = burst
    // matrix[i][1] = waiting
    // matrix[i][2] = turnaround
    for (int i = 0; i < nj; i++) {

        matrix[i][0] = jobs[i][1];                 // burst
        matrix[i][1] = global_time - jobs[i][2];   // waiting
        matrix[i][2] = matrix[i][0] + matrix[i][1]; // turnaround

        global_time += jobs[i][1];
    }

    printf("\nJob\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < nj; i++) {
        printf("J%d\t%d\t%d\t%d\n",
               jobs[i][0],
               matrix[i][0],
               matrix[i][1],
               matrix[i][2]);
    }

    float tt = 0, wt = 0;
    for (int i = 0; i < nj; i++) {
        tt += matrix[i][2];
        wt += matrix[i][1];
    }

    float avg_tt = tt / nj;
    float avg_wt = wt / nj;

    printf("\nAverage Turnaround Time: %.2f\n", avg_tt);
    printf("Average Waiting Time: %.2f\n", avg_wt);

    return 0;
}
