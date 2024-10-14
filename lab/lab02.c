#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NUM_COMPUTERS 1000
#define HEALTHY 0
#define INFECTED 1

typedef struct{
    int status;
} Computer;

int main(){
    Computer computers[NUM_COMPUTERS + 1];
    srand(time(NULL));
    
    int first = (rand() % NUM_COMPUTERS) + 1;
    printf("first: %d\n", first);

    int infected = 1;
    
    while (infected > 999){
        int random = (rand() % NUM_COMPUTERS) + 1;
        if (computers[random].status == HEALTHY){
            computers[random].status = INFECTED;
            infected++;
        }
    }
    
    printf("infected: %d\n", infected);
    // for (int i=1; i<=NUM_COMPUTERS; i++){
    //     computers[i].status = HEALTHY;
    //     printf("computer %d status: %d\n", i, computers[i].status);
    // }
    return 0;
}