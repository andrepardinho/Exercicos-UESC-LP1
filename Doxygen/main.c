/**
 * @file main.c
 * @brief Programa para calcular a média de notas e determinar a situação do aluno.
 * 
 * Este programa lê as notas e pesos de uma disciplina, calcula a média ponderada,
 * verifica a quantidade de faltas e determina a situação do aluno (aprovado, reprovado, 
 * ou necessidade de prova final).
 */

#include <stdio.h>
#include <math.h>

/**
 * @brief Arredonda um valor para uma casa decimal.
 * 
 * @param valor Valor a ser arredondado.
 * @return Valor arredondado para uma casa decimal.
 */

double arredonda(double valor) {
    double fator = 10.0;
    return ceil(valor * fator) / fator;
}

/**
 * @brief Calcula a média ponderada das notas.
 * 
 * @param numNotas Número de notas.
 * @param notas Array com as notas.
 * @param pesos Array com os pesos das notas.
 * @return Média ponderada das notas.
 */

double calcularMedia(int numNotas, double notas[], double pesos[]) {
    double acumulado = 0.0, totalPesos = 0.0;
    for (int i = 0; i < numNotas; i++) {
        acumulado += notas[i] * pesos[i];
        totalPesos += pesos[i];
    }
  return acumulado / totalPesos;
}

/**
 * @brief Calcula a nota final necessária para alcançar a média 5.0.
 * 
 * @param media Média atual do aluno.
 * @return Nota necessária na prova final.
 */
double calcularNotaFinalNecessaria (double media) {
  double necessario = (5.0 - media * 0.6) / 0.4;
  return necessario;
}

int main( ) {
  int numCreditos, numNotas, totalFaltas = 0;
  double notas[10], pesos[10], media, notaFinalNecessaria, notaProvaFinal;
  
  printf("Insira o número de creditos da disciplina (2 a 10): ");
  scanf("%d", &numCreditos);
  // Valida o número de créditos
  while (numCreditos < 2 || numCreditos > 10) {
    printf("Número de creditos invalido. Insira novamente: ");
    scanf("%d", &numCreditos);
  }

  printf("Insira o número de notas: ");
  scanf("%d", &numNotas);
  // Coleta as notas e os pesos associados
  for (int i = 0; i < numNotas; i++) {
    printf("Insira a nota do %dº crédito: ", i + 1);
    scanf("%lf", &notas[i]);
    printf("Insira o peso do %dº crédito: ", i + 1);
    scanf(" %lf", &pesos[i]);
  }

  printf("Insira o número total de faltas: ");
  scanf(" %d", &totalFaltas);

  // Calcula a carga horária e o limite de faltas permitido
  int cargaHoraria = numCreditos * 15;
  int limiteFaltas = cargaHoraria * 0.25;

  media = calcularMedia(numNotas, notas, pesos);
  media = arredonda(media);

  
  printf("\n----------------------------------------\n");
  printf("           \x1b[1mFICHA DE AVALIAÇÃO\x1b[0m\n");
  printf("----------------------------------------\n");
  
   // Exibe as notas e pesos
  for (int i = 0; i < numNotas; i++) {
    printf(" Nota %d:  %.2f    |  (Peso %.2f)\n", i + 1, notas[i], pesos[i]);
    printf("----------------------------------------\n");
  }
  printf("\x1b[1m MÉDIA:   %.2f\x1b[0m\n", media);
  printf("----------------------------------------\n");

  printf(" Faltas:    %d     |  Máximo: %d\n", totalFaltas, limiteFaltas);
  printf("----------------------------------------\n");

// Verifica a situação do aluno baseada nas faltas e na média
  if (totalFaltas > limiteFaltas) {
      printf("\x1b[1mSituação: Reprovado por faltas.\x1b[1m\n");
  } else {
      if (media >= 7.0) {
          printf("\x1b[1mSituação: Aprovado\x1b[0m\n");
      } else if (media >= 1.7) {
          notaFinalNecessaria = calcularNotaFinalNecessaria(media);
          printf("\x1b[1mSituação: Prova Final\x1b[0m\n");
          printf("Nota necessária na Prova Final: %.2f\n", notaFinalNecessaria);

        //PÓS PROVA FINAL 
        printf("\nInsira a nota obtida na Prova Final: ");
        scanf("%lf", &notaProvaFinal);

        media = arredonda(media * 0.6 + notaProvaFinal * 0.4);
        printf("\nNova Média: %.2f\n", media);

        if (media >= 5.0) {
            printf("\x1b[1mSituação: Aprovado\x1b[0m\n");
        } else {
            printf("\x1b[1mSituação: Reprovado\x1b[0m\n");
        }
        
      } else {
          printf("\x1b[1mSituação: Reprovado.\x1b[0m\nSem direito a prova final (média menor que 1.7)\n");
      }
  }
  
  return 0;
}