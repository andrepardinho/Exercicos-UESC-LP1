#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Fun��o para verificar se uma dezena est� dentro do intervalo v�lido
int validarDezena(int numero) {
    return (numero >= 1 && numero <= 60);
}

// Fun��o para realizar o sorteio de um n�mero �nico dentro do intervalo v�lido
int sortearNumero(int numerosSorteados[]) {
    int numeroSorteado;
    do {
        numeroSorteado = rand() % 60 + 1;
    } while (numerosSorteados[numeroSorteado - 1] == 1); // Repete at� encontrar um n�mero n�o sorteado
    numerosSorteados[numeroSorteado - 1] = 1; // Marca o n�mero sorteado como utilizado
    return numeroSorteado;
}

// Fun��o para realizar o sorteio dos n�meros e verificar os acertos
int fazerSorteio(int dezenas[]) {
    int numerosSorteados[60] = {0}; // Array para verificar se um n�mero j� foi sorteado
    int acertos = 0;
    printf("Sorteio: ");
    for (int i = 0; i < 6; i++) {
        int numeroSorteado = sortearNumero(numerosSorteados);
        printf("%d ", numeroSorteado); // Exibe o n�mero sorteado
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

    // Semente aleat�ria baseada no tempo atual
    srand(time(NULL));

    // Entrada das 6 dezenas
    printf("Digite as 6 dezenas (entre 1 e 60):\n");
    for (int i = 0; i < 6; i++) {
        printf("Dezena %d: ", i+1);
        scanf("%d", &dezenas[i]);
        // Verifica se a dezena est� dentro do intervalo de 1 a 60
        if (!validarDezena(dezenas[i])) {
            printf("N�mero inv�lido. As dezenas devem estar entre 1 e 60.\n");
            return 1; // Termina o programa com c�digo de erro
        }
    }

    // Sorteio dos n�meros at� que todas as dezenas escolhidas pelo usu�rio sejam sorteadas
    while (1) {
        tentativas++;
        printf("\nTentativa %ld:\n", tentativas);
        int acertos = fazerSorteio(dezenas);
        // Verifica se todas as dezenas foram acertadas
        if (acertos == 6) {
            printf("\nParab�ns! Voc� acertou as 6 dezenas!\n");
            break;
        }
    }

    printf("N�mero de tentativas at� acertar todas as dezenas: %ld\n", tentativas);

    return 0;
}

