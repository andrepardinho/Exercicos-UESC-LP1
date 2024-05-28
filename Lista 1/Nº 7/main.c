#include <stdio.h>

int valor = 0;

int main(void) {
  printf("Digite um valor inteiro: ");
  scanf("%d", &valor);

  int resultado = (valor % 6) + 1;

  printf("\nO valor entre 1 e 6 correspondente ao número %d é: %d", valor, resultado);
  
  return 0;
}