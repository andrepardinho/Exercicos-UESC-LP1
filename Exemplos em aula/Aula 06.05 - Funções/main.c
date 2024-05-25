/* #include <stdio.h>

int soma (int a, int b);

int main () {
  printf("Teste 1\n");

  int res = soma(1,2);
  
  printf("Soma %d\n", res);

  return 0;
}

int soma (int a, int b) {
  int soma = a + b;

  printf("Função soma: %d %d %d\n", a, b, soma);

  return soma;
} */

#include <stdio.h>
#include <time.h>

int loop (int nOfLoop);

int main () {
  printf("Teste 1\n");

  int res = loop(100);

  printf("Soma %d\n", res);

  return 0;
}

int loop (int nOfLoop) {
  unsigned int soma = 0;
  
  
  for (int i = 0; i < nOfLoop; i++) {
    soma += i;
  }
   
  return soma;
}
