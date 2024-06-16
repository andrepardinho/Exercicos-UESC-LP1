#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define TAMANHO 10000
#define VALOR_MAXIMO 1000.0

void preencherArray (float *array, int tamanho);
void encontrarMinMax (float *array, int tamanho, float *min, float *max, int n);
void ordenarArray (float *array, int tamanho);
double calcularMedia (float *array, int tamanho);
double calcularMediana (float *array, int tamanho);
double calcularDesvioPadrao (float *array, int tamanho, double media);
void contarRepeticoes (float *array, int tamanho);
int removerRepetidos (float *array, int tamanho, float *novoArray);

int main () {
  float array[TAMANHO];
  float min[3], max[3];
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
  printf("Três menores valores: %.2f, %.2f, %.2f\n", min[0], min[1], min[2]);
  printf("Três maiores valores: %.2f, %.2f, %.2f\n", max[0], max[1], max[2]);
  printf("Média: %.2lf\n", media);
  printf("Mediana: %.2lf\n", mediana);
  printf("Desvio padrão: %.2lf\n\n", desvioPadrao);

  contarRepeticoes(array, TAMANHO);

  //criar novo array sem repetidos
  float novoArray[TAMANHO];
  float tamanhoNovoArray = removerRepetidos(array, TAMANHO, novoArray);

  media = calcularMedia(novoArray, tamanhoNovoArray);
  mediana = calcularMediana(novoArray, tamanhoNovoArray);
  desvioPadrao = calcularDesvioPadrao(novoArray, tamanhoNovoArray, media);

  //resultados novo array
  printf("\nArray sem repetidos:\n");
  printf("Média: %.2lf\n", media);
  printf("Mediana: %.2lf\n", mediana);
  printf("Desvio padrão: %.2lf\n\n", desvioPadrao);

  return 0;
}

void preencherArray (float *array, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    array[i] = ((float)rand() / RAND_MAX) * VALOR_MAXIMO;
  }
}

void encontrarMinMax(float *array, int tamanho, float *min, float *max, int n) {
    ordenarArray(array, tamanho);
    // Encontrar n menores valores únicos
    int i = 0, j = 0;
    while (i < tamanho && j < n) {
        if (j == 0 || array[i] != min[j - 1]) {
            min[j] = array[i];
            j++;
        }
        i++;
    }
    // Encontrar n maiores valores únicos
    i = tamanho - 1;
    j = 0;
    while (i >= 0 && j < n) {
        if (j == 0 || array[i] != max[j - 1]) {
            max[j] = array[i];
            j++;
        }
        i--;
    }
}

void ordenarArray (float *array, int tamanho) {
  for (int i = 0; i < tamanho - 1; i++) {
    for (int j = 0; j < tamanho - 1 - i; j++) {
        if (array[j] > array[j + 1]) {
            float temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
        }
    }
  }
}

double calcularMedia (float *array, int tamanho) {
  double soma = 0;
  for (int i = 0; i < tamanho; i++) {
    soma += array[i];
  }
  return soma / tamanho;
}

double calcularMediana(float *array, int tamanho) {
  if (tamanho % 2 == 0) {
    return (array[tamanho /2 - 1] + array[tamanho / 2]) / 2.0;
  } else {
    return array[tamanho / 2];
  }
}

double calcularDesvioPadrao(float *array, int tamanho, double media) {
  double soma = 0;
  for (int i = 0; i < tamanho; i++) {
    soma += pow(array[i] - media, 2);
  }
  return sqrt(soma / tamanho);
}

void contarRepeticoes(float *array, int tamanho) {
  float atual = array[0];
  int contador = 1;
  for (int i = 1; i < tamanho; i++) {
    if (array[i] == atual) {
      contador++;
    } else {
      if (contador > 1) {
        printf("O valor %.2f ocorre %d vezes\n", atual, contador);
      }
      atual = array[i];
      contador = 1;
    }
  }
  if (contador > 1) {
    printf("O valor %.2f ocorre %d vezes\n", atual, contador);
  }
}

int removerRepetidos(float *array, int tamanho, float *novoArray) {
  int tamanhoNovoArray = 0;
  novoArray[tamanhoNovoArray++] = array[0];
  for (int i = 1; i < tamanho; i++) {
    if (array[i] != array[i - 1]) {
      novoArray[tamanhoNovoArray++] = array[i];
    }
  }
  return tamanhoNovoArray;
}