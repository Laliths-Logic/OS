#include <stdio.h>

int main() {
    int p, r;
    int i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter number of resource types: ");
    scanf("%d", &r);

    int alloc[p][r];
    int max[p][r];
    int need[p][r];
    int avail[r];
    int work[r];
    int finish[p];
    int safeSeq[p];

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for(i = 0; i < r; i++) {
        scanf("%d", &avail[i]);
        work[i] = avail[i];
    }

    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for(i = 0; i < p; i++)
        finish[i] = 0;

    int count = 0;
    while(count < p) {
        int found = 0;
        for(i = 0; i < p; i++) {
            if(finish[i] == 0) {
                int possible = 1;
                for(j = 0; j < r; j++) {
                    if(need[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }

                if(possible) {
                    for(k = 0; k < r; k++)
                        work[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(!found) break;
    }

    if(count == p) {
        printf("System is in a SAFE STATE.\n");
        printf("Safe Sequence: ");
        for(i = 0; i < p; i++)
            printf("P%d ", safeSeq[i]);
    } else {
        printf("System is NOT in a safe state (Deadlock may occur).\n");
    }

    return 0;
}
