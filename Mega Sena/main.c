//ANDRÉ PARDINHO - 202410507
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese_Brazil");

    int dezenas[6];
    int i, j, numeroSorteado, acertos;
    long int tentativas = 0;
    int numerosSorteados[60] = {0}; // Array para verificar se um número já foi sorteado

    // Semente aleatória baseada no tempo atual
    srand(time(NULL));

    // Entrada das 6 dezenas
    printf("Digite as 6 dezenas (entre 1 e 60):\n");
    for (i = 0; i < 6; i++) {
        printf("Dezena %d: ", i+1);
        scanf("%d", &dezenas[i]);
        // Verifica se a dezena está dentro do intervalo de 1 a 60
        if (dezenas[i] < 1 || dezenas[i] > 60) {
            printf("Número inválido. As dezenas devem estar entre 1 e 60.\n");
            return 1;
        }
    }

    // Sorteio dos números até que todas as dezenas escolhidas pelo usuário sejam sorteadas
    while (1) {
        // Reinicia os números sorteados para cada tentativa
        for (i = 0; i < 60; i++) {
            numerosSorteados[i] = 0;
        }

        // Sorteio dos números
        acertos = 0;
        tentativas++;
        printf("\nTentativa %ld:\n", tentativas);
        for (i = 0; i < 6; i++) {
            // Gera número aleatório único e dentro do intervalo
            do {
                numeroSorteado = rand() % 60 + 1;
            } while (numerosSorteados[numeroSorteado - 1] == 1); // Repete até encontrar um número não sorteado
            numerosSorteados[numeroSorteado - 1] = 1; // Marca o número sorteado como utilizado
            printf("%d ", numeroSorteado); // Exibe o número sorteado
            for (j = 0; j < 6; j++) {
                if (numeroSorteado == dezenas[j]) {
                    acertos++;
                    break;
                }
            }
        }

        // Verifica se todas as dezenas foram acertadas
        if (acertos == 6) {
            printf("\nParabéns! Você acertou as 6 dezenas!\n");
            break;
        }
    }

  printf("Número de tentativas até acertar todas as dezenas: %ld\n", tentativas);

    return 0;
}
