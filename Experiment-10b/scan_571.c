#include <stdio.h>

int main() {
    int t[20], d[20], h, i, j, n, temp;
    int atr[20], tot, p = 0, sum = 0;

    // Input the number of tracks
    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    // Input the initial head position
    printf("Enter the position of the head: ");
    scanf("%d", &h);

    // Initialize track array with head and initial point
    t[0] = 0;  // Assuming 0 as the start of the disk
    t[1] = h;

    // Input the track positions to be traversed
    printf("Enter the track positions: ");
    for (i = 2; i < n + 2; i++) {
        scanf("%d", &t[i]);
    }

    // Sort the track array
    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find the index of the head in the sorted track array
    for (i = 0; i < n + 2; i++) {
        if (t[i] == h) {
            break;
        }
    }

    // Organize tracks for the head movement sequence (left to 0, then right)
    int k = 0;
    for (j = i; j >= 0; j--) {
        atr[k++] = t[j];
    }
    for (j = i + 1; j < n + 2; j++) {
        atr[k++] = t[j];
    }

    // Calculate the difference between consecutive tracks and sum up
    for (j = 0; j < k - 1; j++) {
        d[j] = atr[j + 1] - atr[j];
        if (d[j] < 0) d[j] = -d[j];
        sum += d[j];
    }

    // Print the average header movement
    printf("\nTotal header movements: %d", sum);
    printf("\nAverage header movements: %.2f\n", (float)sum / n);

    return 0;
}
