#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int AT[n];
    int BT[n];
    int CT[n];
    int TAT[n];
    int WT[n];

    int i;

    for(i = 0; i < n; i++)
    {
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &AT[i], &BT[i]);
    }

    CT[0] = AT[0] + BT[0];

    for(i = 1; i < n; i++)
    {
        if(CT[i-1] < AT[i])
        {
            CT[i] = AT[i] + BT[i];
        }
        else
        {
            CT[i] = CT[i-1] + BT[i];
        }
    }

    float totalTAT = 0;
    float totalWT = 0;

    for(i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];

        totalTAT += TAT[i];
        totalWT += WT[i];
    }

    printf("\nAverage Turnaround Time: %.2f\n", totalTAT/n);
    printf("Average Waiting Time: %.2f\n", totalWT/n);

    return 0;
}
