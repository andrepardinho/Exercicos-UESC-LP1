#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAMANHO 10000
#define VALOR_MAXIMO 1000

void preencherArray (int *array, int tamanho);
void encontrarMinMax (int *array, int tamanho, int *min, int *max, int n);
void ordenarArray (int *array, int tamanho);
double calcularMedia (int *array, int tamanho);
double calcularMediana (int *array, int tamanho);
double calcularDesvioPadrao (int *array, int tamanho, double media);

int main () {
  int array[TAMANHO];
  int min[3], max[3];
  double media, mediana, desvioPadrao;

  //Seed p/ gerar números aleatórios
  srand(time(NULL));

  //passagem de parâmetros
  preencherArray(array, TAMANHO);
  encontrarMinMax(array, TAMANHO, min, max, 3);
  ordenarArray(array, TAMANHO);

  //Calcular media, mediana e desvio padrão
  media = calcularMedia(array, TAMANHO);
  mediana = calcularMediana(array, TAMANHO);
  desvioPadrao = calcularDesvioPadrao(array, TAMANHO, media);

  //Imprimir resultados
  printf("Três menores valores: %d, %d, %d\n", min[0], min[1], min[2]);
  printf("Três maiores valores: %d, %d, %d\n", max[0], max[1], max[2]);
  printf("Média: %.2lf\n", media);
  printf("Mediana: %.2lf\n", mediana);
  printf("Desvio padrão: %.2lf\n", desvioPadrao);

  return 0;
}

void preencherArray (int *array, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    array[i] = rand() % (VALOR_MAXIMO + 1);
  }
}

void encontrarMinMax(int *array, int tamanho, int *min, int *max, int n) {
  ordenarArray (array, tamanho);
  for (int i = 0; i < n; i++) {
    min[i] = array[i];
    max[i] = array[tamanho - 1 - i];
  }
}

void ordenarArray (int *array, int tamanho) {
  for (int i = 0; i < tamanho - 1; i++) {
    for (int j = 0; j < tamanho - 1 - i; j++) {
        if (array[j] > array[j + 1]) {
            int temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
        }
    }
  }
}

double calcularMedia (int *array, int tamanho) {
  double soma = 0;
  for (int i = 0; i < tamanho; i++) {
    soma += array[i];
  }
  return soma / tamanho;
}

double calcularMediana(int *array, int tamanho) {
  if (tamanho % 2 == 0) {
    return (array[tamanho /2 - 1] + array[tamanho / 2]) / 2.0;
  } else {
    return array[tamanho / 2];
  }
}

double calcularDesvioPadrao(int *array, int tamanho, double media) {
  double soma = 0;
  for (int i = 0; i < tamanho; i++) {
    soma += pow(array[i] - media, 2);
  }
  return sqrt(soma / tamanho);
}