#include <stdio.h>

#define MAX 25

int main() {
    int frag[MAX], b[MAX], f[MAX];
    int i, j, nb, nf, temp, highest;
    static int bf[MAX], ff[MAX]; // bf[] keeps track of allocated blocks

    printf("\n\tMemory Management Scheme - First Fit");
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

    // Worst Fit Allocation
    for (i = 1; i <= nf; i++) {
        highest = -1; // Reset highest for each file
        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1) { // If block is free
                temp = b[j] - f[i];
                if (temp >= 0 && (highest == -1 || temp > highest)
