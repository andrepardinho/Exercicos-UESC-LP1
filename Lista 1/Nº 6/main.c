#include <stdio.h>
#include <limits.h>

unsigned long int valor = 0;

int main(void) {

  printf("Forneça um valor inteiro longo sem sinal (0 a %lu): ", ULONG_MAX);
  scanf("%lu", &valor);

  (valor <= INT_MAX) ? 
    printf("\nO valor %lu está dentro do intervalo de um int", valor) : 
    printf("\nO valor %lu é maior que um int", valor);

  return 0;
}