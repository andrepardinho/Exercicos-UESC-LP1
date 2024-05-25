//CALCULO IMC
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculo_imc (float altura, float peso){
    return peso / (pow(altura, 2));
}

int main (int argc, char *argv[] ) {
    if (argc != 3) {
        printf("Digite uma altura em metros e peso em kilograma.\n");
        return 1;
    }
    float altura = atof(argv[1]);
    float peso = atof(argv[2]);
    float imc = calculo_imc(altura, peso);

    printf("\nSeu Índice de Massa Corpórea é %.2f\n", imc);

    printf("-----------------------------------------------------\n");
    printf(" \x1b[1mIMC                CLASSIFICAÇÃO    OBESIDADE(grau)\x1b[0m\n");
    printf("-----------------------------------------------------\n");
    if (imc < 18.5) {
      printf(" \x1b[34mMenor que 18,5     Magreza            0\x1b[37m\n");
      printf("-----------------------------------------------------\n");
    } 
    else {
      printf(" Menor que 18,5     Magreza            0\n");
      printf("-----------------------------------------------------\n");
    }
    if (imc >= 18.5 && imc < 24.9) {
      printf(" \x1b[34mEntre 18,5 e 24,9  Normal             0\x1b[37m\n");
      printf("-----------------------------------------------------\n");
    }
    else {
      printf(" Entre 18,5 e 24,9  Normal             0\n");
      printf("-----------------------------------------------------\n");
    }
    if (imc >= 25.0 && imc < 29.9) {
      printf(" \x1b[34mEntre 25,0 e 29,9  Sobrepeso          I\x1b[37m\n");
      printf("-----------------------------------------------------\n");
    }
    else {
      printf(" Entre 25,0 e 29,9  Sobrepeso          I\n");
      printf("-----------------------------------------------------\n");
    }
    if (imc >=30.0 && imc <39.9) {
      printf(" \x1b[34mEntre 30,0 e 39,9  Obesidade          II\x1b[37m\n");
      printf("-----------------------------------------------------\n");
    }
    else {
      printf(" Entre 30,0 e 39,9  Obesidade          II\n");
      printf("-----------------------------------------------------\n");
    }
    if (imc >= 40.00) {
      printf(" \x1b[34mMaior que 40,0     Obesidade grave    III\x1b[37m\n");
      printf("-----------------------------------------------------\n");
    }
    else {
      printf(" Maior que 40,0     Obesidade grave    III\n");
      printf("-----------------------------------------------------\n");
    }

  
    return 0;
}