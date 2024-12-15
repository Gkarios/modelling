#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Fout 0.001
#define Fcrit 4.0

int main() {
    srand(time(NULL));

    int i, j;
    float current[10][20], next[10][20] = {0.0};
    int magnitude[10][20] = {0};
    int t = 0;
    FILE *fp = fopen("results.csv", "w");
    if (fp == NULL ){
        printf("Error opening file\n");
        return 1;
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 20; j++) {
            current[i][j] = ((float)rand()/RAND_MAX) * Fcrit;
        }
    }
    int allLessThanFcrit;
    while (t < 100000) {
        printf("\n %d", t);
        allLessThanFcrit = 1;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 20; j++) {
                if (current[i][j] >= Fcrit) {  
                    allLessThanFcrit = 0;
                    if (i == 0)
                        next[i + 1][j] += 0.25 * current[i][j];
                    else if (i == 9)
                        next[i - 1][j] += 0.25 * current[i][j];
                    else {
                        next[i + 1][j] += 0.25 * current[i][j];
                        next[i - 1][j] += 0.25 * current[i][j];
                    }
                    if (j == 0)
                        next[i][j + 1] += 0.25 * current[i][j];
                    else if (j == 19)  
                        next[i][j - 1] += 0.25 * current[i][j];
                    else {
                        next[i][j + 1] += 0.25 * current[i][j];
                        next[i][j - 1] += 0.25 * current[i][j];
                    }
                    next[i][j] = 0;  
                    magnitude[i][j] = 1;
                    printf("next[%d][%d] \t %d \t", i,j, current[i][j]);
                }
            }
        }
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 20; j++) {
                current[i][j] += next[i][j];
                next[i][j] = 0;  
            }
        }
        if (allLessThanFcrit) {
            t++;
            for (i = 0; i < 10; i++) {
                for (j = 0; j < 20; j++) {
                    current[i][j] += Fout;
                }
            }
        }
    }
    fclose(fp);
    return 0;
}