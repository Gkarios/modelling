#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#define INFECTED 1
#define HEALTHY 0
#define N 1000

int main() {
  
  srand(time(NULL));
  
  FILE * fp;
  fp = fopen("results.csv", "w");
  
    
  int nodes[N] = {HEALTHY};
  
  nodes[rand() % N] = INFECTED;
  
  int totalinfected = 1;
  int currentinfected = 1;
  int timestep = 0;
  int infected = 0;
  
  
  while (totalinfected < N) {
    timestep++;
    currentinfected = totalinfected;
    for ( infected = 1;infected <= currentinfected; infected++) {
      int node = rand() % N;
        if (nodes[node] == HEALTHY) {
          nodes[node] = INFECTED;
          totalinfected++;
      }
    }
  
   fprintf(fp, "%d; %d \n", timestep, totalinfected);
  }
  fclose(fp);
  printf("Done\n");
  return 0;
}
