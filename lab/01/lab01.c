#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLLS_100 100
#define ROLLS_1000 1000
#define DIE_SIDES 6

void simulate_rolls(int rolls, const char *filename){
  int counts[DIE_SIDES] = {0};
  srand(time(NULL));

  for (int i=0; i<rolls;i++){
    int roll = (rand() % DIE_SIDES) + 1;
    counts[roll - 1]++;
  }

  FILE *fp = fopen(filename, "w");
  if (fp == NULL){
    perror("unable to open file");
    exit(1);
  }
  for (int i=0; i<DIE_SIDES; i++){
    fprintf(fp, "%d %d\n", i+1, counts[i]);
  }
  fclose(fp);
}


int main(){
  simulate_rolls(ROLLS_100, "lab01_100.txt");
  simulate_rolls(ROLLS_1000, "lab01_1000.txt");
  return 0;
}
