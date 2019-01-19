#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAGIC_NUMBER_SIZE 2

typedef struct Pgm {
  char* magicNumber;
  int width;
  int height;
  int maxVal;
  int** image;
} Pgm;

void loadPgm(Pgm* pgm, char* filename);
void savePgm(Pgm* pgm, char* filename);
void freePgm(Pgm* pgm);

void invertColors(Pgm* pgmIn, Pgm* pgmOut);
