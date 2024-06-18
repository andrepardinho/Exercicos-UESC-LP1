// gcc ex1.c -o ex1 soma.o

#include<stdio.h>

#include"soma.h"

int main( int argc, char *argv[] ){
    int va = 10, vb = 20, res = 0;

    res = soma(va, vb);

    printf("Soma a + b = %i\n", res );

    res = menos( va, vb );

    printf("menos + b = %i\n", res );

    return 0;
}


