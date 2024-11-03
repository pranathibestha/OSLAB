#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[50], p, i, j, st, len, n, c;

    // Initialize all blocks as unallocated
    for (i = 0; i < 50; i++) 
        f[i] = 0;

    // Input already allocated blocks
    printf("Enter the number of blocks that are already allocated: ");
    scanf("%d", &p);
    printf("Enter the block numbers that are already allocated: ");
    for (i = 0; i < p; i++) {
        int a;
        scanf("%d", &a);
        if (a >= 0 && a < 50) {
            f[a] = 1;
        } else {
            printf("Block number %d is out of range. Skipping it.\n", a);
        }
    }

    do {
        // Input the starting index and length
        printf("Enter the starting index block and length of file: ");
        scanf("%d%d", &st, &len);

        int allocated = 1;
        for (j = st; j < (st + len); j++) {
            if (j >= 50 || f[j] == 1) {
                printf("Block %d is already allocated or out of range.\n", j);
                allocated = 0;
                break;
            }
        }

        // Allocate blocks if all are free
        if (allocated) {
            for (j = st; j < (st + len); j++) {
                f[j] = 1;
                printf("%d -> %d\n", j, f[j]);
            }
            printf("File allocated successfully.\n");
        } else {
            printf("Failed to allocate the file due to conflicts.\n");
        }

        // Ask if the user wants to continue
        printf("Do you want to enter another file? (yes-1 / no-0): ");
        scanf("%d", &c);

    } while (c == 1);

    return 0;
}
