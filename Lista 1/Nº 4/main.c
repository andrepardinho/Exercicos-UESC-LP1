#include <stdio.h>

int main() {
    int cha;
    
    // Pedir ao usuário para digitar um número inteiro positivo
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &cha);
    
    // Converter para valor positivo se for negativo
    cha = cha < 0 ? -cha : cha;
    
    // Verificar se o valor está dentro do intervalo ASCII
    if (cha > 127) {
        cha = cha % 128;
    }

    // Verificar se o valor é de caractere não imprimível e converter se necessário
    cha = (cha < 32) ? 32 : cha;

    // Imprimir o caractere e seus formatos
    printf("Caractere: '%c'\n", cha);
    printf("Decimal: %d\n", cha);
    printf("Octal: %o\n", cha);
    printf("Hexadecimal: %x\n", cha);
    
    return 0;
}
