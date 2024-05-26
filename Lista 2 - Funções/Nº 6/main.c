//SORTEIO DADO
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int jogarDado() {
    return rand() % 6 + 1;
}


int contarSorteiosParaTodosNumeros() {
    int numeros[6] = {0, 0, 0, 0, 0, 0};
    int totalSorteios = 0;
    int count = 0;

    while (count < 6) {
        int numero = jogarDado();
        totalSorteios++;
        if (numeros[numero - 1] == 0) {
            numeros[numero - 1] = 1;
            count++;
        }
    }

    return totalSorteios;
}

void contarValoresSorteados(int n) {
    int contagens[6] = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < n; i++) {
        int numero = jogarDado();
        contagens[numero - 1]++;
    }

    for (int i = 0; i < 6; i++) {
        printf("Número %d foi sorteado %d vezes\n", i + 1, contagens[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <número de repetições>\n", argv[0]);
        return 1;
    }

    int repeticoes = atoi(argv[1]);

    srand(time(NULL));

    int sorteiosParaTodos = contarSorteiosParaTodosNumeros();
    printf("Número de sorteios para sair todos os números: %d\n\n", sorteiosParaTodos);

    printf("Em %d tentativas:\n", repeticoes);
    contarValoresSorteados(repeticoes);

    return 0;
}
