#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int loop (int nOfLoop);

int main (int argc, char *argv[]) {
  int nLoop = 0;
  double itime = 0;
  double ftime = 0;

  if (argc > 1) {
    nLoop = atoi(argv[1]);
  }
  else {
    nLoop = 1000000;
  }
  itime = clock();
  int res = loop( nLoop );
  ftime = clock();

  double ttime = (ftime / CLOCKS_PER_SEC) - (itime / CLOCKS_PER_SEC);

  printf("Soma = %d | Tempo = %fs\n", res, ttime);

  return 0;
}

int loop (int nOfLoop) {
  unsigned int soma = 0;


  for (int i = 0; i < nOfLoop; i++) {
    soma += i;
  }

  return soma;
}