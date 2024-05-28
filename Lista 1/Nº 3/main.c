#include <stdio.h>

int main( ) {

  int a, b, c = 0;
  float x = 0;

  printf ("Digite dois valores numéricos inteiros:\n");
  printf ("\n1º valor: ");
  scanf ("%d", &a);
  
  printf ("2º valor: ");
  scanf ("%d", &b);

  c = a + b;
  printf ("\nA soma dos valores em hexadecimal é: %X\n", c);
  c = a * b;
  printf ("O produto dos valores em octal é: %o\n", c);
  c = (a > b) ? a - b : b - a;
  printf ("O modulo da diferença entre os valores é: %d\n", c);

  if (b != 0) {
    x = (float)a / b;
    printf("O quociente entre os valores é: %g\n", x);
    
    if (a % b == 0) {
      printf("Sendo %d divisivel de forma exata por %d", a, b);
    }
    else {
      printf("Sendo %d divisivel de forma não exata por %d", a, b);
    }
  
  }
  else {
    printf("O quociente entre os valores é: Indeterminado (Divisão por zero)");
  }
  
  
  return 0;
}