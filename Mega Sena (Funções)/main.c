#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Função para verificar se uma dezena está dentro do intervalo válido
int validarDezena(int numero) {
    return (numero >= 1 && numero <= 60);
}

// Função para realizar o sorteio de um número único dentro do intervalo válido
int sortearNumero(int numerosSorteados[]) {
    int numeroSorteado;
    do {
        numeroSorteado = rand() % 60 + 1;
    } while (numerosSorteados[numeroSorteado - 1] == 1); // Repete até encontrar um número não sorteado
    numerosSorteados[numeroSorteado - 1] = 1; // Marca o número sorteado como utilizado
    return numeroSorteado;
}

// Função para realizar o sorteio dos números e verificar os acertos
int fazerSorteio(int dezenas[]) {
    int numerosSorteados[60] = {0}; // Array para verificar se um número já foi sorteado
    int acertos = 0;
    printf("Sorteio: ");
    for (int i = 0; i < 6; i++) {
        int numeroSorteado = sortearNumero(numerosSorteados);
        printf("%d ", numeroSorteado); // Exibe o número sorteado
        for (int j = 0; j < 6; j++) {
            if (numeroSorteado == dezenas[j]) {
                acertos++;
                break;
            }
        }
    }
    return acertos;
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int dezenas[6];
    long int tentativas = 0;

    // Semente aleatória baseada no tempo atual
    srand(time(NULL));

    // Entrada das 6 dezenas
    printf("Digite as 6 dezenas (entre 1 e 60):\n");
    for (int i = 0; i < 6; i++) {
        printf("Dezena %d: ", i+1);
        scanf("%d", &dezenas[i]);
        // Verifica se a dezena está dentro do intervalo de 1 a 60
        if (!validarDezena(dezenas[i])) {
            printf("Número inválido. As dezenas devem estar entre 1 e 60.\n");
            return 1; // Termina o programa com código de erro
        }
    }

    // Sorteio dos números até que todas as dezenas escolhidas pelo usuário sejam sorteadas
    while (1) {
        tentativas++;
        printf("\nTentativa %ld:\n", tentativas);
        int acertos = fazerSorteio(dezenas);
        // Verifica se todas as dezenas foram acertadas
        if (acertos == 6) {
            printf("\nParabéns! Você acertou as 6 dezenas!\n");
            break;
        }
    }

    printf("Número de tentativas até acertar todas as dezenas: %ld\n", tentativas);

    return 0;
}

