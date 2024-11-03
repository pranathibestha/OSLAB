#include <stdio.h>
#include <string.h>

int main() {
    char job[10][10];
    int time[10], avail, temp[10], tem[10];
    int safe[10];
    int ind = 0, n, t;

    // Input the number of jobs
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    // Input job names and time required for each
    for (int i = 0; i < n; i++) {
        printf("Enter job name and time required: ");
        scanf("%s%d", job[i], &time[i]);
    }

    // Input available resources
    printf("Enter the available resources: ");
    scanf("%d", &avail);

    // Initialize temporary arrays for sorting
    for (int i = 0; i < n; i++) {
        temp[i] = time[i];
        tem[i] = i;
    }

    // Sort jobs based on their time in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                // Swap time
                t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;

                // Swap index
                t = tem[i];
                tem[i] = tem[j];
                tem[j] = t;
            }
        }
    }

    // Find safe sequence
    for (int i = 0; i < n; i++) {
        int q = tem[i]; // job index after sorting by time

        // Check if the job can be safely executed
        if (time[q] <= avail) {
            safe[ind] = q;
            avail -= time[q];
            ind++;
        } else {
            printf("No safe sequence found.\n");
            return 0;
        }
    }

    // Print safe sequence if found
    printf("Safe sequence is:\n");
    for (int i = 0; i < ind; i++) {
        printf("Job: %s, Time Required: %d\n", job[safe[i]], time[safe[i]]);
    }

    return 0;
}
