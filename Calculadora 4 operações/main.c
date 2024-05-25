#include <stdio.h>

int main () {
  float v1 = 0; //resultado das operações
  float var1 = 0; //1º valor
  float var2 = 0; //2º valor
  int opt = 0; //opção de operação

  printf("Escolha o primeiro valor:"); 
  scanf("%g", &var1); //recebe e armazena o 1º valor

  printf("\nEscolha o segundo valor: ");
  scanf("%g", &var2); //recebe e armazena o 2º valor

  printf("\nEscolha uma operação:\n");
  printf("\n1: Adição\n2: Subtração\n3: Multiplicação\n4: Divisão\n");
  scanf("%i", &opt); //recebe e armazena a opção de operação

  if (opt == 1) 
    v1 = var1 + var2;
  else if (opt == 2)
    v1 = var1 - var2;
  else if (opt == 3)
    v1 = var1 * var2;
  else if (opt == 4) {
    if (var2 == 0) { //verificação para evitar divisão por zero
      printf("Erro: Divisão por zero.\n");
      return 1; // Retorna 1 para indicar erro
    }
    v1 = var1 / var2; 
  }

  else {
      printf("Opção inválida!\n"); //caso nenhuma das opções seja escolhida
      return 1; // Retorna 1 para indicar um erro
  }


  printf("\nResultado: %g", v1);

  return 0;
}