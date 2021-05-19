#include "../include/pgm.h"

void loadPgm(Pgm* pgm, char* filename) {
  size_t magicNumberSize = MAGIC_NUMBER_SIZE;
  FILE* file;

  file = fopen(filename, "r");

  if(file == NULL) {
    perror("Error while opening file\n");
    exit(EXIT_FAILURE);
  }


  getline(&pgm->magicNumber, &magicNumberSize, file);
  fscanf(file, "%d", &pgm->width);
  fscanf(file, "%d", &pgm->height);
  fscanf(file, "%d", &pgm->maxVal);

  pgm->image = malloc(sizeof(int*) * pgm->height);

  for(int i = 0; i < pgm->height; i++) {
    pgm->image[i] = malloc(sizeof(int) * pgm->width);
  }

  for(int i = 0; i < pgm->height; i++) {
    for(int j = 0; j < pgm->width; j++) {
      fscanf(file, "%d", &pgm->image[i][j]);
    }
  }

  fclose(file);
}


void savePgm(Pgm* pgm, char* filename) {
  FILE* file;

  file = fopen(filename, "w+");

  if(file == NULL) {
    perror("Error while opening file\n");
    exit(EXIT_FAILURE);
  }

  fprintf(file, "%s", pgm->magicNumber);
  fprintf(file, "%d ", pgm->width);
  fprintf(file, "%d\n", pgm->height);
  fprintf(file, "%d\n", pgm->maxVal);

  for(int i = 0; i < pgm->height; i++) {
    for(int j = 0; j < pgm->width; j++) {
      fprintf(file, "%d ", pgm->image[i][j]);
    }
    fprintf(file, "\n");
  }

  fclose(file);
}

void freePgm(Pgm* pgm) {
  free(pgm->magicNumber);

  for(int i = 0; i < pgm->height; i++) {
    free(pgm->image[i]);
  }

  free(pgm->image);
}

void invertColors(Pgm* pgmIn, Pgm* pgmOut) {
  pgmOut->magicNumber = malloc(sizeof(char) * MAGIC_NUMBER_SIZE);
  strcpy(pgmOut->magicNumber, pgmIn->magicNumber);
  pgmOut->width = pgmIn->width;
  pgmOut->height = pgmIn->height;
  pgmOut->maxVal = pgmIn->maxVal;

  pgmOut->image = malloc(sizeof(int*) * pgmOut->height);

  for(int i = 0; i < pgmOut->height; i++) {
    pgmOut->image[i] = malloc(sizeof(int) * pgmOut->width);
  }

  for(int i = 0; i < pgmOut->height; i++) {
    for(int j = 0; j < pgmOut->width; j++) {
      pgmOut->image[i][j] = pgmIn->maxVal - pgmIn->image[i][j];
    }
  }
}
