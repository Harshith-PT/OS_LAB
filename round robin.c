#include <stdio.h>

int main() {
    int n, tq, i;
    int at[20], bt[20], rt[20], ct[20], tat[20], wt[20], start[20];
    int completed = 0, time = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("Enter arrival times:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        start[i] = -1;
    }

    while(completed < n) {
        int done = 1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                done = 0;

                if(start[i] == -1)
                    start[i] = time;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    completed++;
                }
            }
        }

        if(done)
            time++;
    }

    printf("\nRRS scheduling:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++) {
        avg_tat += tat[i];
        avg_wt += wt[i];

        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i], start[i]-at[i]);
    }

    printf("\nAverage turnaround time: %.6fms\n", avg_tat/n);
    printf("\nAverage waiting time: %.6fms\n", avg_wt/n);

    return 0;
}
