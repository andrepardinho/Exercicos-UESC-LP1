#include <stdio.h>

int valor = 0;

int main(void) {
  printf("Forneça um valor inteiro positivo: ");
  scanf("%u", &valor);

  if (valor < 0) {
    valor = valor * -1;
  }
  
  unsigned int soma = 0;
  for(unsigned int i = 0; i <= valor; i++) {
    soma += i;
  }
  printf("Soma dos valores entre 0 e %d: %u", valor, soma);
  
  return 0;
