#include <stdio.h>

#define MAX 25

int main() {
    int frag[MAX], b[MAX], f[MAX];
    int i, j, nb, nf, temp, lowest;
    static int bf[MAX], ff[MAX]; // bf[] keeps track of allocated blocks

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

    // Best Fit Allocation
    for (i = 1; i <= nf; i++) {
        lowest = 10000; // Reset lowest fragmentation for each file
        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1) { // If block is free
                temp = b[j] - f[i];
                if (temp >= 0 && temp < lowest) { // Check for best fit
                    ff[i] = j; // Allocate block j to file i
                    lowest = temp; // Update lowest fragmentation
                }
            }
        }
        frag[i] = lowest; // Set fragmentation for the file
        if (lowest != 10000) { // If a block was allocated
            bf[ff[i]] = 1; // Mark block as allocated
        } else {
            ff[i] = -1; // No block allocated
            frag[i] = -1; // No fragmentation
        }
    }

    // Print the results
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for (i = 1; i <= nf; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",
               i, f[i], ff[i] != -1 ? ff[i] : 0, 
               ff[i] != -1 ? b[ff[i]] : 0, frag[i]);
    }

    return 0; // Standard way to return from main
}
