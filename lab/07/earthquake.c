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
    float copy[10][20];
    int intensity[10][20] = {0};
    
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 20; j++) {
            innerSurface[i][j] = ((float)rand() / RAND_MAX) * 4;
            copy[i][j] = innerSurface[i][j];
        }
    }

    int stop = 0;
    while (!stop) {
        for (i=0; i<10; i++){
            for (j=0; j<20; j++){
               innerSurface[i][j] += Fout; 
            }
        }
        timestep++;
        for (i=0; i<10; i++){
            for (j=0; j<20; j++){
                if (innerSurface[i][j] >= Fcrit && intensity[i][j] == 0){
                    intensity[j][j] = 1;
                    printf("Timestep: %d \t Innersurface[%d][%d]: %f \t intensity: %d\n", timestep, i, j, innerSurface[i][j], intensityValue);
                    stop = 1;
                    break;
                }
            }
            if (stop) break;
        }
    }
    return 0;
}