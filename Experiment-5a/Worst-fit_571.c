#include <stdio.h>

#define MAX 25

int main() {
    int frag[MAX], b[MAX], f[MAX];
    int i, j, nb, nf, temp;
    static int bf[MAX], ff[MAX]; // bf[] keeps track of allocated blocks

    printf("\n\tMemory Management Scheme - Worst Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    // First Fit Allocation
    for (i = 1; i <= nf; i++) {
        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1) { // If block is free
                temp = b[j] - f[i];
                if (temp >= 0) { // If block can accommodate the file
                    ff[i] = j; // Allocate block j to file i
                    frag[i] = temp; // Calculate fragmentation
                    bf[j] = 1; // Mark block as allocated
                    break; // Break the inner loop since allocation is done
                }
            }
        }
        if (j > nb) { // If no block is found for file
            ff[i] = -1; // Indicate no block allocated
            frag[i] = -1; // Indicate no fragmentation
        }
    }

    // Print the results
    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment");
    for (i = 1; i <= nf; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",
               i, f[i], ff[i] != -1 ? ff[i] : 0, ff[i] != -1 ? b[ff[i]] : 0, frag[i]);
    }

    return 0; // Standard way to return from main
}
