#include "./pgmlib/include/pgm.h"

int main(int argc, char *argv[]) {
  Pgm pgm;
  Pgm pgmOut;

  loadPgm(&pgm,"./feep.pgm");
  invertColors(&pgm, &pgmOut);

  savePgm(&pgmOut, "./feep_out.pgm");

  freePgm(&pgm);
  freePgm(&pgmOut);

  return 0;
}
