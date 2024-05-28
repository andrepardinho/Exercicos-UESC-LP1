#include <stdio.h>
#include <math.h>

float lado = 0;

int main(void) {
  printf("Digite o valor do lado de um quadrado: ");
  scanf("%f", &lado);

  printf("Diagonal = %.2f u.m", lado * sqrt(2));
  printf("\nAréa = %.2f u.m²", lado * lado);
  printf("\nPerímetro = %.2f u.m", 4*lado);
  
  return 0;
}