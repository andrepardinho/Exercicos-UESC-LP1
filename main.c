//André Pardinho - 202410507
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main () {

  srand(time(NULL));
  float X, Y, dist_centro, aprox_pi;

  int num_p, i, pont_circ = 0;

  printf("Número de pontos a ser sorteado: ");
  scanf("%d", &num_p);

  for(i=0; i<num_p ; i++) {
    X = (float) rand() / RAND_MAX;
    Y = (float) rand() / RAND_MAX;

    dist_centro = X*X + Y*Y;

    if (dist_centro <= 1) {
      pont_circ++;
    }
  }

  aprox_pi = 4.0 * pont_circ / num_p;
  
  printf("\n\nNúmero de pontos dentro do círculo: %d\n", pont_circ);
  printf("Número de pontos fora: %d\n", num_p - pont_circ);
  printf("\nValor simulado de pi é: %f\n", aprox_pi);
  printf("Valor de pi: %f\n", M_PI);
  printf("Erro de: %f\n", fabs(M_PI - aprox_pi));
  printf("Precisão: %f%%\n" ,  (1-(fabs(M_PI - aprox_pi) / M_PI)) * 100);
  
  return 0;
}