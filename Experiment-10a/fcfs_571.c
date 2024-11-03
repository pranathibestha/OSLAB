#include <stdio.h>

int main() {
    int t[20], n, i;
    int tohm[20], tot = 0;
    float avhm;

    // Input the number of tracks
    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    // Input the tracks to be traversed
    printf("Enter the tracks to be traversed: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    // Calculate the absolute difference between consecutive tracks
    for (i = 0; i < n - 1; i++) {
        tohm[i] = t[i + 1] - t[i];
        if (tohm[i] < 0) {
            tohm[i] = -tohm[i];
        }
        tot += tohm[i];
    }

    // Calculate average header movements
    avhm = (float) tot / (n - 1);

    // Display results
    printf("\nTracks traversed\tDifference between tracks\n");
    for (i = 0; i < n - 1; i++) {
        printf("%d -> %d\t\t\t%d\n", t[i], t[i + 1], tohm[i]);
    }
    printf("\nTotal header movements: %d", tot);
    printf("\nAverage header movements: %.2f\n", avhm);

    return 0;
}
