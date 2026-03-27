#include <stdio.h>

struct process {
    int pid,at,bt,ct,tat,wt;
    int priority;
    int completed;
};

int main() {
    int n,i,time=0,done=0;
    int index;
    float avg_tat=0,avg_wt=0;

    struct process p[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);


    for(i=0;i<n;i++){
        printf("\nProcess %d\n",i+1);
        p[i].pid=i+1;

        printf("Arrival Time: ");
        scanf("%d",&p[i].at);

        printf("Burst Time: ");
        scanf("%d",&p[i].bt);

        printf("Priority: ");
        scanf("%d",&p[i].priority);

        p[i].completed = 0;
    }

    while(done<n) {
        index=-1;
        int min=9999;

        for(i=0;i<n;i++) {
            if(p[i].at<=time&&p[i].completed == 0) {
                if(p[i].priority<min) {
                    min=p[i].priority;
                    index=i;
                }
            }
        }

        if(index==-1) {
            time++;
        } else {
            time+=p[index].bt;

            p[index].ct=time;
            p[index].tat=p[index].ct-p[index].at;
            p[index].wt=p[index].tat-p[index].bt;

            avg_tat+=p[index].tat;
            avg_wt+=p[index].wt;

            p[index].completed = 1;
            done++;
        }
    }


    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].priority,
               p[i].ct,
               p[i].tat,
               p[i].wt);
    }
    printf("\nAverage Waiting Time=%.2f",avg_wt / n);
    printf("\nAverage Turnaround Time=%.2f\n",avg_tat / n);

    return 0;
}
