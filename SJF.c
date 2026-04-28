#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int AT[n];      
    int BT[n];      
    int CT[n];      
    int TAT[n];     
    int WT[n];      
    int visited[n]; 
    int i;

    for(i=0; i<n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &AT[i], &BT[i]);
        visited[i] = 0; 
    }

    int time = 0;      
    int completed = 0; 
    int min;           

    while(completed < n) {
        min = -1;
        for(i=0; i<n; i++) {
            if(AT[i] <= time && visited[i] == 0) {
                if(min == -1 || BT[i] < BT[min]) {
                    min = i;
                }
            }
        }

        if(min == -1) {
            time++; 
        } else {
            time += BT[min];
            CT[min] = time;
            visited[min] = 1;
            completed++;
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

    printf("\nAverage Turnaround Time = %.2f\n", totalTAT/n);
    printf("Average Waiting Time = %.2f\n", totalWT/n);

    return 0;
}
