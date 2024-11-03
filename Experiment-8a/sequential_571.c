#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[50], i, st, j, len, c;

    // Initialize the file blocks as unallocated (0)
    for (i = 0; i < 50; i++) 
        f[i] = 0;

    do {
        printf("\nEnter the starting block and length of the file: ");
        scanf("%d%d", &st, &len);

        // Check if the blocks are free
        int allocated = 1;
        for (j = st; j < (st + len); j++) {
            if (f[j] == 1) {
                printf("Block %d already allocated.\n", j);
                allocated = 0;
                break;
            }
        }

        // Allocate if all blocks are free
        if (allocated) {
            for (j = st; j < (st + len); j++) {
                f[j] = 1;
                printf("%d -> %d\n", j, f[j]);
            }
            printf("The file is allocated to disk.\n");
        }

        printf("Do you want to enter more files? (y-1/n-0): ");
        scanf("%d", &c);

    } while (c == 1);

    return 0;
}
