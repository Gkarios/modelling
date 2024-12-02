#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define Fout 0.001
#define Fcrit 4

int main(){
    srand(time(NULL));

    int timestep = 0;
    int intensityValue = 0;
    int i, j;
    float innerSurface[10][20];
    int copy[10][20];
    int intensity[10][20];
    
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 20; j++) {
            innerSurface[i][j] = ((float)rand() / RAND_MAX) * 4;
            copy[i][j] = innerSurface[i][j];
        }
    }
    
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 20; j++) {
            while (innerSurface[i][j] < Fcrit) {
                innerSurface[i][j] += Fout;
                timestep++;
                if (innerSurface[i][j] >= Fcrit && intensity[i][j] == 0) {
                    intensity[i][j] = 1;
                    intensityValue+=1;

                    printf("Timestep: %d \t Inner surface[%d][%d]: %f \t intensity: %d\n", timestep, i, j, innerSurface[i][j], intensityValue);
                    return 0;
                }
            }
        }
    }

    return 0;
}