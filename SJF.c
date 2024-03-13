#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0;
    float avg_wt, avg_tat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("p%d:", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1; // Contains process number
    }

    // Sort processes by burst time in ascending order (Selection Sort)
    for (i = 0; i < n - 1; i++) {
        int pos = i;
        for (j = i + 1; j < n; j++) {
            if (bt[j] < bt[pos]) {
                pos = j;
            }
        }
        if (pos != i) {
            swap(&bt[i], &bt[pos]);
            swap(&p[i], &p[pos]);
        }
    }

    wt[0] = 0; // Waiting time for first process will be zero
    // Calculate waiting time for all processes (SJF logic)
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        total += wt[i];
    }

    avg_wt = (float) total / n; // Average waiting time

    printf("\nProcess\t  Burst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Calculate turnaround time
        printf("\np%d\t\t  %d\t\t\t %d\t\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    avg_tat = (float) (total + bt[n - 1]) / n; // Average turnaround time (includes last process completion)

    printf("\n\nAverage Waiting Time = %f", avg_wt);
    printf("\nAverage Turnaround Time = %f\n", avg_tat);

    return 0;
}

