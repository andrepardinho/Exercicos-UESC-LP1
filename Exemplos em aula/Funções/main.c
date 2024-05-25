#include <stdio.h>

int soma (int nOfCycles, int step) {
  int soma = 0;
  for (int i = 0; i < nOfCycles; i += step) {
      soma += i;
      printf ("%i %d\n", i, soma);
        
  }
  return soma;
}

int main() {
  int valor = 0;

  valor = soma (100, 10);
  printf ("Valor %d\n", valor);

  return 0;
}
