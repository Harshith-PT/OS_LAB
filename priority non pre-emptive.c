#include <stdio.h>

int main() {
    int n, i, j, pos;
    int pid[20], at[20], bt[20], pr[20];
    int ct[20], tat[20], wt[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Process ID, Arrival Time, Burst Time, Priority: ");
        scanf("%d %d %d %d", &pid[i], &at[i], &bt[i], &pr[i]);
    }


    for(i = 0; i < n; i++) {
        pos = i;
        for(j = i + 1; j < n; j++) {
            if(pr[j] < pr[pos]) {
                pos = j;
            }
        }

        int temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;


        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;


        temp = pid[i];
        pid[i] = pid[pos];
        pid[pos] = temp;


        temp = at[i];
        at[i] = at[pos];
        at[pos] = temp;
    }

    ct[0] = at[0] + bt[0];

    for(i = 1; i < n; i++) {
        ct[i] = ct[i-1] + bt[i];
    }

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
