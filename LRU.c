#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f, i, j, k;
    int pageFaults = 0;
    int found, lruIndex;
    int recent[10];

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
        recent[i] = -1;
    }

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                recent[j] = i;
                break;
            }
        }

        if(found == 0)
        {
            lruIndex = 0;

            for(j = 1; j < f; j++)
            {
                if(recent[j] < recent[lruIndex])
                    lruIndex = j;
            }

            frames[lruIndex] = pages[i];
            recent[lruIndex] = i;
            pageFaults++;
        }
    }

    printf("Total Page Faults = %d\n", pageFaults);

    return 0;
}
