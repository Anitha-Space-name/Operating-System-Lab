#include <stdio.h>

struct Process
{
    int pid;
    int burstTime;
    int period;
};

int main()
{
    int n, i, j;
    int simulationTime;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n], temp;


    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("\nEnter Burst Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].burstTime);

        printf("Enter Period for P%d: ", p[i].pid);
        scanf("%d", &p[i].period);
    }

    printf("\nEnter Simulation Time: ");
    scanf("%d", &simulationTime);

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(p[i].period > p[j].period)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("\nRMS Scheduling Simulation\n");
    printf("\nTime\tRunning Process\n");


    for(i = 0; i < simulationTime; i++)
    {
        int current = i % n;

        printf("%d\tP%d\n", i, p[current].pid);
    }

    return 0;
}
