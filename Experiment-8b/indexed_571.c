#include <stdio.h>
#include <stdlib.h>

int f[50], inde[50];

int main() {
    int i, k, j, n, c, p;

    // Initialize all blocks to 0 (unallocated)
    for (i = 0; i < 50; i++) 
        f[i] = 0;

    do {
        printf("Enter index block: ");
        scanf("%d", &p);

        // Check if index block is already allocated
        if (f[p] == 0) {
            f[p] = 1;  // Allocate the index block
            printf("Enter number of files on index: ");
            scanf("%d", &n);

            printf("Enter the blocks to allocate: ");
            for (i = 0; i < n; i++) 
                scanf("%d", &inde[i]);

            // Check if blocks are already allocated
            int allocation_possible = 1;
            for (i = 0; i < n; i++) {
                if (f[inde[i]] == 1) {
                    printf("Block %d already allocated\n", inde[i]);
                    allocation_possible = 0;
                    break;
                }
            }

            // Allocate the blocks if possible
            if (allocation_possible) {
                for (j = 0; j < n; j++) 
                    f[inde[j]] = 1;

                printf("\nAllocation successful.\n");
                printf("File indexed with the following blocks:\n");
                for (k = 0; k < n; k++)
                    printf("%d -> %d\n", p, inde[k]);
            }
        } else {
            printf("Index block %d is already allocated.\n", p);
        }

        printf("Enter 1 to enter more files or 0 to exit: ");
        scanf("%d", &c);

    } while (c == 1);

    return 0;
}
