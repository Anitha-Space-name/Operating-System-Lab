#include <stdio.h>
#include <string.h>

#define MAX 50

struct process {
    char pid[5];
    int at, bt, ct, tat, wt;
    int type;
};

int main() {
    struct process sys[MAX], user[MAX];
    int n, i, j;
    int sysCount = 0, userCount = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);


    for(i = 0; i < n; i++) {
        struct process temp;
        char t[10];

        printf("\nProcess %d\n", i + 1);
        printf("PID: ");
        scanf("%s", temp.pid);
        printf("AT: ");
        scanf("%d", &temp.at);
        printf("BT: ");
        scanf("%d", &temp.bt);
        printf("Type (System/User): ");
        scanf("%s", t);

        if(strcmp(t, "System") == 0) {
            temp.type = 1;
            sys[sysCount++] = temp;
        } else {
            temp.type = 0;
            user[userCount++] = temp;
        }
    }

    for(i = 0; i < sysCount - 1; i++) {
        for(j = i + 1; j < sysCount; j++) {
            if(sys[i].at > sys[j].at) {
                struct process temp = sys[i];
                sys[i] = sys[j];
                sys[j] = temp;
            }
        }
    }

    for(i = 0; i < userCount - 1; i++) {
        for(j = i + 1; j < userCount; j++) {
            if(user[i].at > user[j].at) {
                struct process temp = user[i];
                user[i] = user[j];
                user[j] = temp;
            }
        }
    }

    int time = 0;

    for(i = 0; i < sysCount; i++) {
        if(time < sys[i].at)
            time = sys[i].at;

        time += sys[i].bt;
        sys[i].ct = time;

        sys[i].tat = sys[i].ct - sys[i].at;
        sys[i].wt = sys[i].tat - sys[i].bt;
    }


    for(i = 0; i < userCount; i++) {
        if(time < user[i].at)
            time = user[i].at;

        time += user[i].bt;
        user[i].ct = time;

        user[i].tat = user[i].ct - user[i].at;
        user[i].wt = user[i].tat - user[i].bt;
    }

    float totalWT = 0, totalTAT = 0;


    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < sysCount; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",
               sys[i].pid, sys[i].at, sys[i].bt,
               sys[i].ct, sys[i].tat, sys[i].wt);

        totalWT += sys[i].wt;
        totalTAT += sys[i].tat;
    }

    for(i = 0; i < userCount; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",
               user[i].pid, user[i].at, user[i].bt,
               user[i].ct, user[i].tat, user[i].wt);

        totalWT += user[i].wt;
        totalTAT += user[i].tat;
    }

    printf("\nAverage Turnaround Time = %.2f", totalTAT / n);
    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);

    return 0;
}
