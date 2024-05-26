#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    printf("Sem argumentos. \n");
    
    return 1;
  }

  int n = atoi(argv[1]);

  int vect[n];

  printf("\nElementos do vetor:\n");
  for (int i = 0; i < n; i++) {
      vect[i] = i;
      printf("%d ", vect[i]);
  }

  int soma = 0;
  for (int i = 0; i < n; i++)
    soma += vect[i];

  printf("\nTamanho = %d, Soma = %d, Média = %f \n", n, soma, (float)soma/n);

  return 0;
  
}