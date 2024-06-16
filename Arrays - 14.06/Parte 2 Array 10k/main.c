#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define TAMANHO 10000
#define VALOR_MAXIMO 1000

void preencherArray (int *array, int tamanho);
void encontrarMinMax (int *array, int tamanho, int *min, int *max, int n);
void ordenarArray (int *array, int tamanho);
double calcularMedia (int *array, int tamanho);
double calcularMediana (int *array, int tamanho);
double calcularDesvioPadrao (int *array, int tamanho, double media);
void contarRepeticoes (int *array, int tamanho);
int removerRepetidos (int *array, int tamanho, int *novoArray);

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
  printf("Desvio padrão: %.2lf\n\n", desvioPadrao);

  contarRepeticoes(array, TAMANHO);

  //criar novo array sem repetidos
  int novoArray[TAMANHO];
  int tamanhoNovoArray = removerRepetidos(array, TAMANHO, novoArray);

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

void preencherArray (int *array, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    array[i] = rand() % (VALOR_MAXIMO + 1);
  }
}

void encontrarMinMax(int *array, int tamanho, int *min, int *max, int n) {
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

void contarRepeticoes(int *array, int tamanho) {
  int atual = array[0];
  int contador = 1;
  for (int i = 1; i < tamanho; i++) {
    if (array[i] == atual) {
      contador++;
    } else {
      if (contador > 1) {
        printf("O valor %d ocorre %d vezes\n", atual, contador);
      }
      atual = array[i];
      contador = 1;
    }
  }
  if (contador > 1) {
    printf("O valor %d ocorre %d vezes\n", atual, contador);
  }
}

int removerRepetidos(int *array, int tamanho, int *novoArray) {
  int tamanhoNovoArray = 0;
  novoArray[tamanhoNovoArray++] = array[0];
  for (int i = 1; i < tamanho; i++) {
    if (array[i] != array[i - 1]) {
      novoArray[tamanhoNovoArray++] = array[i];
    }
  }
  return tamanhoNovoArray;
}