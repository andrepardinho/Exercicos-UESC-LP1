#include <stdio.h>

int main () {
  
int n=5;

int matriz[n][n];
float soma = 0;

for (int i = 0; i<n; i++) {
  for (int j = 0; j<n; j++) {
    
    matriz[i][j] = i*j;
    printf("%d\t", matriz[i][j]);

    soma = soma + matriz[i][j];
  }
  printf("\n");
}
  printf("\nSoma: %.3f", soma);
  printf("\nMédia: %.3f", soma/(n*n));
  
  return 0;
}