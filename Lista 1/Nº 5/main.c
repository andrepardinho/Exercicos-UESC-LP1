#include <stdio.h>
#include <limits.h>

int valor = 0;

int main(void) {
  
  printf("Forneça um valor: ");
  scanf("%d", &valor);
  
  (valor >= SHRT_MIN && valor <= SHRT_MAX) ? 
    printf("\nO valor %d está dentro do intervalo de um short int", valor) : 
    printf("\nO valor %d é maior que um short int", valor);
  
  return 0;
}