#include <stdio.h>
#include <math.h>

// RETA
double comprimento_reta(double A, double B) {
  return B - A;
}

// CIRCULO
double area_circulo(double raio) {
  return M_PI * pow(raio, 2);
}
double perimetro_circulo(double raio) {
  return 2 * M_PI * raio;
}
double diametro_circulo(double raio) {
  return 2 * raio;
}

// QUADRADO
double area_quadrado(double lado) {
return lado * lado;
}
double perimetro_quadrado(double lado) {
return 4 * lado;
}
double diagonal_quadrado(double lado) {
return lado * sqrt(2);
}

// RETÂNGULO
double area_retangulo(double baseret, double alturaret) {
  return baseret * alturaret;
}
double perimetro_retangulo(double baseret, double alturaret) {
  return 2 * (baseret + alturaret);
}
double diagonal_retangulo(double baseret, double alturaret) {
  return sqrt(pow(baseret, 2) + pow(alturaret, 2));
}

// TRIÂNGULO
double perimetro_triangulo(double lado1, double lado2, double lado3) {
    return lado1 + lado2 + lado3;
}
double area_triangulo(double lado1, double lado2, double lado3) {
    double semi_perimetro = perimetro_triangulo(lado1, lado2, lado3) / 2;
    return sqrt(semi_perimetro * (semi_perimetro - lado1) * (semi_perimetro - lado2) * (semi_perimetro - lado3));
}

// Trapézio
double area_trapezio(double basemaior, double basemenor, double alturatrap){
  return ((basemaior + basemenor) * alturatrap) / 2;
}
double basemedia_trapezio(double basemaior, double basemenor) {
  return (basemaior + basemenor) / 2;
}
double mediana_trapezio(double basemaior, double basemenor) {
  return (basemaior - basemenor) / 2;
}
double perimetro_trapezio(double basemaior, double basemenor, double lado1trap, double lado2trap) {
  return basemaior + basemenor + lado1trap + lado2trap;
}

//LOSANGO
double area_losango(double diagonalmaior, double diagonalmenor) {
  return (diagonalmaior * diagonalmenor) / 2;
}
double lados_losango(double diagonalmaior, double diagonalmenor) {
  return sqrt(pow((diagonalmaior/2), 2) + pow((diagonalmenor/2), 2));
}


int main() {
  int opcao;
  printf("Escolha uma figura geométrica:\n");
  printf("\n1. Segmento de reta\n");
  printf("2. Círculo\n");
  printf("3. Quadrado\n");
  printf("4. Retângulo\n");
  printf("5. Triângulo\n");
  printf("6. Trapézio\n");
  printf("7. Losango\n");

  
  printf("Opção: ");
  scanf("%d", &opcao);

  if (opcao == 1) {
      double A, B;
      printf("\nDigite o ponto A: ");
      scanf("%lf", &A);
      printf("Digite o ponto B: ");
      scanf("%lf", &B);
      printf("\nComprimento do segmento de reta: %.2lf u.m\n", comprimento_reta(A, B));
  }
  if (opcao == 2) {
      double raio;
      printf("\nDigite o valor do raio do círculo: ");
      scanf("%lf", &raio);
      printf("\nÁrea: %.2lf u.m²\n", area_circulo(raio));
      printf("Perímetro: %.2lf u.m\n", perimetro_circulo(raio));
      printf("Diâmetro: %.2lf u.m\n", diametro_circulo(raio));
  }
  if (opcao == 3) {
     double lado;
     printf("\nDigite o valor do lado do quadrado: ");
     scanf("%lf", &lado);
     printf("\nÁrea: %2.lf u.m²\n", area_quadrado(lado));
     printf("Perimetro: %2.lf u.m\n", perimetro_quadrado(lado));
     printf("Diagonal: %.2lf u.m\n", diametro_circulo(lado));
  }
  if (opcao == 4) {
    double baseret, alturaret;
    printf("\nDigite o valor da base do retângulo: ");
    scanf("%lf", &baseret);
    printf("Valor da altura do retângulo: ");
    scanf("%lf", &alturaret);
    printf("\nÁrea: %2.lf u.m²\n", area_retangulo(baseret, alturaret));
    printf("Perímetro: %2.lf u.m\n", perimetro_retangulo(baseret, alturaret));
    printf("Diagonal: %2.lf u.m\n", diagonal_retangulo(baseret, alturaret));
  }
  if (opcao == 5) {
      double lado1, lado2, lado3;
        printf("\nDigite o comprimento do lado 1 (base) do triângulo: ");
        scanf("%lf", &lado1);
        printf("Comprimento do lado 2: ");
        scanf("%lf", &lado2);
        printf("Comprimento do lado 3: ");
        scanf("%lf", &lado3);
    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
        if (lado1 == lado2 && lado2 == lado3) {
            printf("\nSeu triângulo é equilátero.\n");
        } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            printf("\nSeu triângulo é isósceles.\n");
        } else {
            printf("\nSeu triângulo é escaleno.\n");
        }

        printf("Área: %.2lf u.m²\n", area_triangulo(lado1, lado2, lado3));
        printf("Perímetro: %.2lf u.m\n", perimetro_triangulo(lado1, lado2, lado3));
      }
    else {
      printf("\nOs valores inseridos não formam um triângulo válido.\n");
    }
  }
  if (opcao == 6) {
    double basemaior, basemenor, alturatrap, lado1trap, lado2trap;
    printf("\nDigite o valor da base maior do trapézio: ");
    scanf("%lf", &basemaior);
    printf("Valor da base menor: ");
    scanf("%lf", &basemenor);
    printf("Valor da altura: ");
    scanf("%lf", &alturatrap);
    printf("Valor do 1º lado do trapézio: ");
    scanf("%lf", &lado1trap);
    printf("Valor do 2º lado do trapézio: ");
    scanf("%lf", &lado2trap);
    printf("\nÁrea: %.2lf u.m²\n", area_trapezio(basemaior, basemenor, alturatrap));
    printf("Base média: %.2lf u.m\n", basemedia_trapezio(basemaior, basemenor));
    printf("Mediana: %.2lf u.m\n", mediana_trapezio(basemaior, basemenor));
    printf("Perímetro: %.2lf u.m\n", perimetro_trapezio(basemaior, basemenor, lado1trap, lado2trap));
  }
  if (opcao == 7) {
    double diagonalmaior, diagonalmenor;
    printf("\nDigite o valor da diagonal maior do losango: ");
    scanf("%lf", &diagonalmaior);
    printf("Valor da diagonal menor: ");
    scanf("%lf", &diagonalmenor);

    double lado = lados_losango(diagonalmaior, diagonalmenor);
    double perimetro = 4 * lado;

  printf("\nÁrea: %.2lf u.m²\n", area_losango(diagonalmaior, diagonalmenor));
  printf("Lado: %.2lf u.m\n", lado);
  printf("Perímetro: %.2lf u.m\n", perimetro);
}

  return 0;
}
