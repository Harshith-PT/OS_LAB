#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], pr[20], rt[20];
    int ct[20], tat[20], wt[20], start[20];
    int pid[20];
    float avg_tat = 0, avg_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter priorities:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pr[i]);
    }

    printf("Enter arrival times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        pid[i] = i + 1;
        start[i] = -1;
    }

    while(completed < n) {
        int highest = 9999;
        int pos = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(pr[i] < highest) {
                    highest = pr[i];
                    pos = i;
                }
            }
        }

        if(pos == -1) {
            time++;
        } else {
            if(start[pos] == -1)
                start[pos] = time;

            rt[pos]--;
            time++;

            if(rt[pos] == 0) {
                ct[pos] = time;
                tat[pos] = ct[pos] - at[pos];
                wt[pos] = tat[pos] - bt[pos];

                avg_tat += tat[pos];
                avg_wt += wt[pos];

                completed++;
            }
        }
    }

    printf("\nPriority scheduling (Pre-Emptive):\n");
    printf("PID\tPrior\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], pr[i], at[i], bt[i], ct[i], tat[i], wt[i], start[i] - at[i]);
    }

    printf("\nAverage turnaround time: %.2f\n", avg_tat/n);
    printf("Average waiting time: %.2f\n", avg_wt/n);

    return 0;
}
