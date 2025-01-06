#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Fout 0.01
#define Fcrit 4.0
#define N 10
#define M 20

int check_Fcrit(float current[N][M]);
void reset_array_int(int array[N][M]);
void redistribute(float current[N][M], float next[N][M], int magnitude[N][M]);
int count_magnitude(int magnitude[N][M]);
void reset_array(float array[N][M]);
void add_arrays(float current[N][M], float next[N][M]);


int main() {
    srand(time(NULL));

    int i, j;
    float current[N][M], next[N][M] = {0.0};
    int magnitude[N][M] = {0};
    int t = 0;
    FILE *fp = fopen("results0.001.csv", "w");

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            current[i][j] = ((float)rand()/RAND_MAX) * Fcrit;
        }
    }

    while (t < 100000) {
        if (!check_Fcrit(current)){
            fprintf(fp, "%d, 0\n", t);    //record no earthquake
            t++;
            //increment everything
            for (int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    current[i][j] += Fout;
                }
            }
        }else{
            do{
                redistribute(current, next, magnitude);
                add_arrays(current, next);
                reset_array(next);
            }while(check_Fcrit(current));

            int earthquakeMagnitude = count_magnitude(magnitude);
            fprintf(fp, "%d, %d\n", t, earthquakeMagnitude);

            reset_array_int(magnitude);
        }
    }
    fclose(fp);
    printf("fin\n");
    return 0;
}

int check_Fcrit(float array[N][M]){
    for (int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if (array[i][j] >= Fcrit){
                return 1; //exceeds Fcrit
            }
        }
    }
    return 0;
}

void redistribute(float current[N][M], float next[N][M], int magnitude[N][M]){
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
           if (current[i][j] >= Fcrit){
            float redistributedForce = 0.25*current[i][j];
            current[i][j] = 0.0;
            magnitude [i][j] = 1;

            if (i>0) next[i-1][j] += redistributedForce;
            if (i<9) next[i+1][j] += redistributedForce;
            if (j>0) next[i][j-1] += redistributedForce;
            if (j<19) next[i][j+1] += redistributedForce;
           }
        }
    }
}

void add_arrays(float array1[N][M], float array2[N][M]){
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            array1[i][j] += array2[i][j];
        }
    }
}

int count_magnitude(int magnitude[N][M]){
    int count = 0;
    for (int i = 0; i<N; i++){
        for (int j = 0; j<M; j++){
            if (magnitude[i][j] == 1){
                count++;
            }
        }
    }
    return count;
}

void reset_array(float array[N][M]){
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            array[i][j] = 0.0;
        }
    }
}

void reset_array_int(int array[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            array[i][j] = 0;
        }
    }
}
