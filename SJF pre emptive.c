#include<stdio.h>
struct process
{
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
};

int main()
{
    int n,i,time=0,completed=0,choice;
    int min,index=-1;
    float avg_wt=0,avg_tat=0;
    struct process p[20];
    printf("1.Enter Processes\n");
    printf("2.Run Preemptive SJF (SRTF)\n");
    printf("Enter choice:");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        printf("Enter the number of processes:");
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            printf("\n Process %d\n",i+1);
            p[i].pid=i+1;
            printf("Arrival Time:");
            scanf("%d",&p[i].at);
            printf("Burst Time:");
            scanf("%d",&p[i].bt);
            p[i].rt=p[i].bt;
        }
    case 2:
        while(completed<n)
        {
            min=9999;
            index=-1;

            for(i=0;i<n;i++)
            {
                if(p[i].at<=time && p[i].rt>0 && p[i].rt<min)
                {
                    min=p[i].rt;
                    index=i;
                }
            }
            if(index==-1)
            {
                time++;
            }
            else
            {
                p[index].rt--;
                if(p[index].rt==0)
                {
                    completed++;
                    p[index].ct=time+1;
                    p[index].tat=p[index].ct-p[index].at;
                    p[index].wt=p[index].tat-p[index].bt;
                    avg_wt+=p[index].wt;
                    avg_tat+=p[index].tat;
                }
                time++;
            }
        }
        printf("\n PID\tAT\tBT\tCT\tTAT\tWT\n");
        for(i=0;i<n;i++)
        {
            printf("%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid,
            p[i].at,
            p[i].bt,
            p[i].ct,
            p[i].rt,
            p[i].tat,
            p[i].wt
            );

        }
        printf("\nAverage Waiting Time= %.2f",avg_wt/n);
        printf("\nAverage Turnaround Time= %.2f",avg_tat/n);
        break;
    default:
        printf("Invalid choice");

    }
    return 0;
}

