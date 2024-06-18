#include <stdio.h>

int main(void) {
    int dec;

    printf("Bem-vindo(a) ao jogo: Torre de Hanói! O bastão 1 começa com três peças.\n");
    printf("Por favor, selecione para qual bastão (2 ou 3) deseja mover a primeira peça: ");
    scanf("%i", &dec);

    while (dec != 2 && dec != 3) {
        printf("Escolha inválida. Por favor, selecione o bastão 2 ou 3: ");
        scanf("%i", &dec);
    }

    printf("Você escolheu colocar a primeira peça no bastão %d.\n", dec);

    printf("A solução mais eficiente é:\n");
    if (dec == 2) {
        printf("1 - Mova a peça 1 do bastão 1 para o bastão 2.\n");
        printf("2 - Mova a peça 2 do bastão 1 para o bastão 3.\n");
        printf("3 - Mova a peça 1 do bastão 2 para o bastão 3.\n");
        printf("4 - Mova a peça 3 do bastão 1 para o bastão 2.\n");
        printf("5 - Mova a peça 1 do bastão 3 para o bastão 1.\n");
        printf("6 - Mova a peça 2 do bastão 3 para o bastão 2.\n");
        printf("7 - Mova a peça 1 do bastão 1 para o bastão 2.\n");
    } else if (dec == 3) {
        printf("1 - Mova a peça 1 do bastão 1 para o bastão 3.\n");
        printf("2 - Mova a peça 2 do bastão 1 para o bastão 2.\n");
        printf("3 - Mova a peça 1 do bastão 3 para o bastão 2.\n");
        printf("4 - Mova a peça 3 do bastão 1 para o bastão 3.\n");
        printf("5 - Mova a peça 1 do bastão 2 para o bastão 1.\n");
        printf("6 - Mova a peça 2 do bastão 2 para o bastão 3.\n");
        printf("7 - Mova a peça 1 do bastão 1 para o bastão 3.\n");
    }

    return 0;
}
