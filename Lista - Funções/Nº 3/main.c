//CALCULO MDC
#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b){
    if (b == 0){
        return a;
    } 
    else {
        return mdc(b, a % b);
    }
}

int main (int argc, char *argv[] ) {
    if (argc != 3) {
        printf("Digite dois valores inteiros.\n");
        return 1;
    }

    int valor1 = atoi(argv[1]);
    int valor2 = atoi(argv[2]);


    int calculo_mdc = mdc(valor1, valor2);
    printf("O MDC entre %d e %d é %d", valor1, valor2, calculo_mdc);

    return 0;
}