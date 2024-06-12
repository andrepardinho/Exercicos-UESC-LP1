#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_SIZE 20
#define MIN_SIZE 10
#define NAME_LENGTH 20

void printArray(char arr[][NAME_LENGTH], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\t", arr[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
  
    int size;
    char names[MAX_SIZE][NAME_LENGTH];
    char temp[NAME_LENGTH];

  
    do {
        printf("Quantos nomes você deseja digitar? (Entre %d e %d): ", MIN_SIZE, MAX_SIZE);
        scanf("%d", &size);
        getchar();
    } while (size < MIN_SIZE || size > MAX_SIZE);

    // Lê os nomes digitados pelo usuário
    printf("\x1b[1mDigite %d nomes:\x1b[0m\n", size);
    for (int i = 0; i < size; i++) {
        printf("Nome %d: ", i + 1);
        scanf("%19s", names[i]);  // Lê até 19 caracteres
        getchar();
    }

    
    printf("\n\x1b[1mOrdem atual dos nomes:\x1b[0m\n");
    printArray(names, size);

    // Ordenação por inserção
    for (int i = 1; i < size; i++) {
        for (int j = i; j >= 1; j--) {
            if (strcmp(names[j], names[j - 1]) < 0) {
                strcpy(temp, names[j - 1]);
                strcpy(names[j - 1], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("\n\x1b[1mNomes ordenados:\x1b[0m\n");
    printArray(names, size);

    printf("\n\x1b[1mPrimeiro nome:\x1b[0m %s\n", names[0]);
    printf("\x1b[1mÚltimo nome:\x1b[0m %s\n", names[size - 1]);
    printf("\x1b[1mNome mediano:\x1b[0m %s\n", names[size / 2]);

    printf("\n\x1b[1mNomes inversamente ordenados:\n\x1b[0m");
    for (int i = size - 1; i >= 0; i--) {
        printf("%s\t", names[i]);
    }
    printf("\n");

    return 0;
}
