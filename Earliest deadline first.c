 #include <stdio.h>

struct Process
{
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int deadline;
};

int main()
{
    int n, i, time, simulationTime;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("\nEnter Arrival Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].arrivalTime);

        printf("Enter Burst Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].burstTime);

        printf("Enter Deadline for P%d: ", p[i].pid);
        scanf("%d", &p[i].deadline);

        p[i].remainingTime = p[i].burstTime;
    }

    printf("\nEnter Simulation Time: ");
    scanf("%d", &simulationTime);

    printf("\nEDF Scheduling (Preemptive with Simulation Time)\n");
    printf("Time\tProcess\n");

    for(time = 0; time < simulationTime; time++)
    {
        int idx = -1;
        int minDeadline = 99999;

        // Find ready process with earliest deadline
        for(i = 0; i < n; i++)
        {
            if(p[i].arrivalTime <= time && p[i].remainingTime > 0)
            {
                if(p[i].deadline < minDeadline)
                {
                    minDeadline = p[i].deadline;
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            printf("%d\tP%d\n", time, p[idx].pid);
            p[idx].remainingTime--;
        }
        else
        {
            printf("%d\tIdle\n", time);
        }
    }

    return 0;
}
