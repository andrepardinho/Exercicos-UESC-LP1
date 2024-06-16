#include <stdio.h>

#define DIM1 10
#define DIM2 20
#define DIM3 5

void preencherArray(int array[DIM1][DIM2][DIM3]) {
  int valor = 1;
  for (int i = 0; i < DIM1; i++) {
    for (int j = 0; j < DIM2; j++) {
      for (int k = 0; k < DIM3; k++) {
        array[i][j][k] = valor++;
      }
    }
  }
}

void imprimirArray(int array[DIM1][DIM2][DIM3]) {
  for (int i = 0; i < DIM1; i++) {
    for (int j = 0; j < DIM2; j++) {
      for (int k = 0; k < DIM3; k++) {
        printf("array[%d][%d][%d] = %d\n", i, j, k, array[i][j][k]);
      }
    }
  }
}

int main ( ) {
  int array[DIM1][DIM2][DIM3];

  preencherArray(array);

  imprimirArray(array);

  return 0;
}