#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int finished;
};

int main() {
    int n, i, completed = 0, current_time = 0, min_index;
    float total_tat = 0, total_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        p[i].pid = i + 1;
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].finished = 0;
    }

    while(completed < n) {
        int min_bt = 9999;
        min_index = -1;

        for(i = 0; i < n; i++) {
            if(p[i].at <= current_time && p[i].finished == 0) {
                if(p[i].bt < min_bt) {
                    min_bt = p[i].bt;
                    min_index = i;
                }
            }
        }

        if(min_index == -1) {
            current_time++;
        }
        else {
            current_time += p[min_index].bt;
            p[min_index].ct = current_time;

            p[min_index].tat = p[min_index].ct - p[min_index].at;
            p[min_index].wt = p[min_index].tat - p[min_index].bt;

            total_tat += p[min_index].tat;
            total_wt += p[min_index].wt;

            p[min_index].finished = 1;
            completed++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].ct,
               p[i].tat,
               p[i].wt);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt/n);

    return 0;
}
