#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COMPUTERS 1000
#define HEALTHY 0
#define INFECTED 1
#define IMMUNE 2

typedef struct {
    int status;
    int infectionTime;
} Computer;

int main() {
    Computer computers[NUM_COMPUTERS + 1];
    srand(time(NULL));

    FILE *fp = fopen("lab03b.txt", "w");
    if (fp == NULL) {
        perror("Unable to open file");
        return 1;
    }

    for (int i = 1; i <= NUM_COMPUTERS; i++) {
        computers[i].status = HEALTHY;
        computers[i].infectionTime = -1;
    }

    int currentTimestep;

    int timestep = 0;
    int immune = 0;

    int first = (rand() % NUM_COMPUTERS) + 1;
    computers[first].status = INFECTED;
    int infected = 1;
    fprintf(fp, "%d %d\n", timestep, infected);

    while (immune < NUM_COMPUTERS && timestep < 1000) {
        timestep++;
        int infectedNew = 0;
        double beta = 1.0 - (0.02 * timestep);  // decreases linearly over time
        for (int i = 0; i < infected; i++) {
            if ((double)rand() / RAND_MAX < beta) {
                int random = (rand() % NUM_COMPUTERS) + 1;
                if (computers[random].status == HEALTHY) {
                    computers[random].status = INFECTED;
                    infectedNew++;
                }
            }
        }
        infected += infectedNew;  // Move this line outside the loop

        for (int i = 1; i <= NUM_COMPUTERS; i++) {
            if (computers[i].status == INFECTED) {
                if (computers[i].infectionTime == -1) {
                    computers[i].infectionTime = timestep;
                }
                if (timestep - computers[i].infectionTime >= 10) {
                    computers[i].status = IMMUNE;
                    immune++;
                    infected--;
                }
            }
        }
        fprintf(fp, "%d %d\n", timestep, infected);
    }
    fclose(fp);
    return 0;
}
