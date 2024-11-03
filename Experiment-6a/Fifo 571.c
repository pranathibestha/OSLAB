#include <stdio.h>

#define FRAMES 3
#define PAGES 12

void display(int fr[]);

int main() {
    int fr[FRAMES]; // Frame array
    int page[PAGES] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int flag1, flag2, pf = 0, frsize = FRAMES, top = 0;

    // Initialize frame array
    for (int i = 0; i < frsize; i++) {
        fr[i] = -1;
    }

    // Page replacement simulation
    for (int j = 0; j < PAGES; j++) {
        flag1 = 0; // Flag for page hit
        flag2 = 0; // Flag for empty frame

        // Check if page is already in frames
        for (int i = 0; i < frsize; i++) {
            if (fr[i] == page[j]) {
                flag1 = 1; // Page hit
                flag2 = 1; // Page found
                break;
            }
        }

        // If page not found in frames
        if (flag1 == 0) {
            // Check for empty frame
            for (int i = 0; i < frsize; i++) {
                if (fr[i] == -1) {
                    fr[i] = page[j]; // Place page in empty frame
                    flag2 = 1; // Page added
                    break;
                }
            }
        }

        // If no empty frames, replace a page
        if (flag2 == 0) {
            fr[top] = page[j]; // Replace page
            top++; // Move to next position
            pf++; // Increment page fault count
            if (top >= frsize) {
                top = 0; // Wrap around if needed
            }
        }

        display(fr); // Display current frames
    }

    printf("Number of page faults: %d\n", pf);
    return 0; // Standard way to return from main
}

// Function to display the frames
void display(int fr[]) {
    printf("\n");
    for (int i = 0; i < FRAMES; i++) {
        printf("%d\t", fr[i]);
    }
}
