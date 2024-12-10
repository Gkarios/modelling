#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Fout 0.001
#define Fcrit 4

int main() {
  srand(time(NULL));

  int i, j, intensity = 0;
  float current[10][20]; 
  float next[10][20] = {0};
  int distribution[10][20] = {0}, t = 0, min = 0, max = 4;
  FILE *fp1;

  fp1 = fopen("results.csv", "w");

  for (i = 0; i < 10; i++) {
    for (j = 0; j < 20; j++) {
      double range = (max - min);
      double div = RAND_MAX / range;
      current[i][j] = min + (rand() / div);
    }
  }
while (t < 1000000) {
    int allLessThanFcrit = 1;

    // Check if any element in the current array surpasses or equals Fcrit
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 20; j++) {
            if (current[i][j] >= Fcrit) {
                allLessThanFcrit = 0;
                if (i == 0)
                    next[i + 1][j] = 0.25 * current[i][j];
                else if (i == 9)
                    next[i - 1][j] = 0.25 * current[i][j];
                else {
                    next[i + 1][j] = 0.25 * current[i][j];
                    next[i - 1][j] = 0.25 * current[i][j];
                }
                if (j == 0)
                    next[i][j + 1] = 0.25 * current[i][j];
                else if (j == 19)
                    next[i][j - 1] = 0.25 * current[i][j];
                else {
                    next[i][j + 1] = 0.25 * current[i][j];
                    next[i][j - 1] = 0.25 * current[i][j];
                }
                next[i][j] = 0;
                distribution[i][j] = 1;
                //checkpoint
            }
        }
    }

    int continueLoop = 1;
    while (continueLoop) {
        continueLoop = 0;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 20; j++) {
                if (current[i][j] >= Fcrit) {
                    continueLoop = 1;
                    break;
                }
            }
            if (continueLoop) break;
        }

        if (!continueLoop) {
            // Aggregate and print the distribution array
            int sum = 0;
            for (i = 0; i < 10; i++) {
                for (j = 0; j < 20; j++) {
                    sum += distribution[i][j];
                }
            }
            fprintf(fp1, "Timestamp: %d, Sum: %d\n", t, sum);

            // Initialize the distribution array to 0
            for (i = 0; i < 10; i++) {
                for (j = 0; j < 20; j++) {
                    distribution[i][j] = 0;
                }
            }
        }

        // Update current array with next array values
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 20; j++) {
                current[i][j] += next[i][j];
                next[i][j] = 0;
            }
        }
    }

    if (allLessThanFcrit) {
        fprintf(fp1, "%d 0\n", t);
        t++;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 20; j++) {
                current[i][j] += Fout;
                next[i][j] += Fout;
            }
        }
    }
}

fclose(fp1);
return 0;
}
