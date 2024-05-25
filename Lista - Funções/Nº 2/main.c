//CONVERSÃO DE TEMPERATURAS

#include <stdio.h>
#include <stdlib.h>


float celsius_para_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

float fahrenheit_para_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <valor> <unidade>\n", argv[0]);
        printf("Unidades disponíveis: C para Celsius, F para Fahrenheit.\n");
        return 1;
    }

    float valor = atof(argv[1]);
    char unidade = argv[2][0];

    if (unidade == 'C' || unidade == 'c' ) {
        printf("%.2f° Celsius = %.2f° Fahrenheit\n", valor, celsius_para_fahrenheit(valor));
    }
    else if (unidade == 'F' || unidade == 'f' ) {
        printf("%.2f° Fahrenheit = %.2f° Celsius\n", valor, fahrenheit_para_celsius(valor));
    }
    else {
        printf("Unidade inválida. Use 'C' para Celsius ou 'F' para Fahrenheit.\n");
        return 1;
    }

    return 0;
}
