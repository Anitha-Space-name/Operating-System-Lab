#include <stdio.h>

struct Block
{
    int size;
    int allocated;
};

struct Process
{
    int size;
};

int main()
{
    int nb, np, i, j, choice;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    struct Block block[20];

    printf("Enter sizes of memory blocks:\n");
    for(i = 0; i < nb; i++)
    {
        scanf("%d", &block[i].size);
        block[i].allocated = 0;
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    struct Process process[20];

    printf("Enter sizes of processes:\n");
    for(i = 0; i < np; i++)
    {
        scanf("%d", &process[i].size);
    }

    printf("\n1. First Fit");
    printf("\n2. Best Fit");
    printf("\n3. Worst Fit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("\nProcess No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < np; i++)
    {
        int allocatedBlock = -1;

        if(choice == 1)
        {
            for(j = 0; j < nb; j++)
            {
                if(block[j].allocated == 0 &&
                   block[j].size >= process[i].size)
                {
                    allocatedBlock = j + 1;
                    block[j].allocated = 1;
                    break;
                }
            }
        }
        else if(choice == 2)
        {
            int best = -1;

            for(j = 0; j < nb; j++)
            {
                if(block[j].allocated == 0 &&
                   block[j].size >= process[i].size)
                {
                    if(best == -1 ||
                       block[j].size < block[best].size)
                    {
                        best = j;
                    }
                }
            }

            if(best != -1)
            {
                allocatedBlock = best + 1;
                block[best].allocated = 1;
            }
        }
        else if(choice == 3)
        {
            int worst = -1;

            for(j = 0; j < nb; j++)
            {
                if(block[j].allocated == 0 &&
                   block[j].size >= process[i].size)
                {
                    if(worst == -1 ||
                       block[j].size > block[worst].size)
                    {
                        worst = j;
                    }
                }
            }

            if(worst != -1)
            {
                allocatedBlock = worst + 1;
                block[worst].allocated = 1;
            }
        }

        if(allocatedBlock != -1)
            printf("%d\t\t%d\t\t%d\n",
                   i + 1,
                   process[i].size,
                   allocatedBlock);
        else
            printf("%d\t\t%d\t\tNot Allocated\n",
                   i + 1,
                   process[i].size);
    }

    return 0;
}
