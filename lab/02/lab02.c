#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COMPUTERS 1000
#define HEALTHY 0
#define INFECTED 1

typedef struct
{
    int status;
} Computer;

int main()
{
    Computer computers[NUM_COMPUTERS + 1];
    srand(time(NULL));

    FILE *fp = fopen("lab02.txt", "w");
    if (fp == NULL)
    {
        perror("Unable to open file");
        return 1;
    }

    for (int i = 1; i <= NUM_COMPUTERS; i++)
    {
        computers[i].status = HEALTHY;
    }

    int infected = 0;
    int timestep = 0;

    int first = (rand() % NUM_COMPUTERS) + 1;
    computers[first].status = INFECTED;
    infected = 1;
    fprintf(fp, "%d %d\n", timestep, infected); 
    
    while (infected < NUM_COMPUTERS){
        timestep++;
        //infectedNew to maintain the loop check rule
        int infectedNew = 0;
        for (int i = 0; i < infected; i++){
            int random = (rand() % NUM_COMPUTERS) + 1;
            if (computers[random].status == HEALTHY){
                computers[random].status = INFECTED;
                infectedNew++;
            }
        }
        //update infected, write at the end of timestep 
        infected += infectedNew;
        fprintf(fp, "%d %d\n", timestep, infected);
    }
    fclose(fp);
    return 0;
}
