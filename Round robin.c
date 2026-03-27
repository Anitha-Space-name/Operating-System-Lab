#include <stdio.h>

struct process {
    int pid, at, bt, ct, tat, wt;
    int remaining_bt;
    int completed;
};

int main() {
    int n, i, time = 0, done = 0, tq;
    float avg_tat = 0, avg_wt = 0;

    struct process p[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        p[i].pid = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &p[i].at);

        printf("Burst Time: ");
        scanf("%d", &p[i].bt);

        p[i].remaining_bt = p[i].bt;
        p[i].completed = 0;
    }

    while(done < n) {
        int executed = 0;

        for(i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].remaining_bt > 0) {

                executed = 1;

                if(p[i].remaining_bt > tq) {
                    time += tq;
                    p[i].remaining_bt -= tq;
                } else {
                    time += p[i].remaining_bt;
                    p[i].remaining_bt = 0;

                    p[i].ct = time;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;

                    avg_tat += p[i].tat;
                    avg_wt += p[i].wt;

                    p[i].completed = 1;
                    done++;
                }
            }
        }

        if(executed == 0) {
            time++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].ct,
               p[i].tat,
               p[i].wt);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
