#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int tq;
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int AT[n];  
    int BT[n];  
    int RT[n];  
    int CT[n];  
    int TAT[n]; 
    int WT[n];  
    int i;

    for(i=0; i<n; i++) {
        printf("Enter AT and BT for P%d: ", i+1);
        scanf("%d %d", &AT[i], &BT[i]);
        RT[i] = BT[i];
    }

    int time = 0;      
    int completed = 0; 

    while(completed < n) {
        int done = 1;

        for(i=0; i<n; i++) {
            if(RT[i] > 0 && AT[i] <= time) {
                done = 0;

                if(RT[i] > tq) {
                    time += tq;
                    RT[i] -= tq;
                } else {
                    time += RT[i];
                    RT[i] = 0;
                    CT[i] = time;
                    completed++;
                }
            }
        }

        if(done == 1) {
            time++;
        }
    }

    float totalTAT = 0;
    float totalWT = 0;

    for(i=0; i<n; i++) {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        totalTAT += TAT[i];
        totalWT += WT[i];
    }

    printf("\nAverage Turnaround Time: %.2f\n", totalTAT/n);
    printf("Average Waiting Time: %.2f\n", totalWT/n);

    return 0;
}
