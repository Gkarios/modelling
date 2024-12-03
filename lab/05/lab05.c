#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define UNSEEN 0
#define SEEN 1

typedef struct
{
    int status;
} Computer;

int main()
{
    int NUM_COMPUTERS = N * N;
    Computer computers[NUM_COMPUTERS + 1];
    srand(time(NULL));

    FILE *fp = fopen("lab04n=5.txt", "w");
    if (fp == NULL)
    {
        perror("Unable to open file");
        return 1;
    }

    for (int i = 1; i <= NUM_COMPUTERS; i++)
    {
        computers[i].status = UNSEEN;
    }

    int timestep = 0;
    int first = (rand() % NUM_COMPUTERS) + 1;
    computers[first].status = SEEN;
    int informed = 1;
    float α = (float)informed / NUM_COMPUTERS;
    fprintf(fp, "%d %.4f\n", timestep, α);

    if (informed < NUM_COMPUTERS)
    {
        while (informed < NUM_COMPUTERS)
        {
                int random = (rand() % NUM_COMPUTERS) + 1;
                if (computers[random].status == UNSEEN)
                {
                    computers[random].status = SEEN;
                    informed++;
                }
            timestep++;
            α = (float)informed / NUM_COMPUTERS;
            fprintf(fp, "%d %.4f\n", timestep, α);
        }
    }
    fclose(fp);
    return 0;
}