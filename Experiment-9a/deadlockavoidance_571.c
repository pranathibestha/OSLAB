#include <stdio.h>
#include <string.h>

int main() {
    int alloc[10][10], max[10][10], avail[10], work[10], total[10];
    int need[10][10];
    int n, m;
    int count = 0;
    char finish[10];

    printf("Enter the number of processes and resources: ");
    scanf("%d%d", &n, &m);

    // Initialize finish array
    for (int i = 0; i < n; i++) 
        finish[i] = 'n';

    // Input maximum claim matrix
    printf("Enter the maximum claim matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    // Input allocation matrix
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    // Input total resources
    printf("Enter the total resources vector: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &total[i]);

    // Calculate available resources
    for (int i = 0; i < m; i++) {
        avail[i] = total[i];
        for (int j = 0; j < n; j++) {
            avail[i] -= alloc[j][i];
        }
    }

    // Initialize work vector as available vector
    for (int i = 0; i < m; i++)
        work[i] = avail[i];

    // Calculate need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Banker's algorithm to find the safe sequence
    int safe = 0;
    while (count < n) {
        safe = 0;
        for (int i = 0; i < n; i++) {
            if (finish[i] == 'n') {
                int can_allocate = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        can_allocate = 0;
                        break;
                    }
                }

                // If resources can be allocated
                if (can_allocate) {
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    finish[i] = 'y';
                    count++;
                    safe = 1;

                    printf("Resources allocated to process %d\n", i + 1);
                    printf("Available resources after allocation: ");
                    for (int k = 0; k < m; k++)
                        printf("%4d", work[k]);
                    printf("\n");
                }
            }
        }
        if (!safe) {
            printf("The system is in an unsafe state.\n");
            return 0;
        }
    }

    printf("\nThe system is in a safe state.\n");
    return 0;
}
