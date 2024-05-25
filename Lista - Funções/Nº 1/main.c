//ANDRÉ PARDINHO - 202410507

//VERIFICAÇÃO NUMÉRICA
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int check_numero (char valor){
    return (valor >= '0' && valor <= '9');
}

int check_alfanumerico (char valor) {
    return (valor >= 'A' && valor <= 'Z') || (valor >= 'a' && valor <= 'z') || check_numero(valor);
}

void imprimir_sequencia (int num) {
  for (int i = 1; i <= num; i++) {
    printf("%d ", i);
   }
}

void imprimir_sequencia_invert (int num) {
  for (int i = num; i >= 1; i--) {
    printf("%d ", i);
  }
}

int num_primo(int num) {
  if (num <= 1) {
    return 0;
  }

  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      return 0;
    }
  }

  return 1;
}

int num_perfeitos (int num) {
  int soma = 0;
  for (int i = 1; i <= num /2; i++) {
    if (num % i == 0) {
      soma += i;
    }
  }
  return soma == num;
}

void imprimir_num_perfeitos (int num) {
  for (int i = 1; i <= num; i++) {
    if (num_perfeitos(i)) {
      printf("%d ", i);
    }
  }
}

int main (int argc, char *argv[] ) {
    if (argc < 2 ) {
        printf("Erro: Entre com um argumento (valor)");
        return 1;      
    }

    char *input = argv[1];
    int num = atoi(input);

    int is_num = 1;
    for (int i = 0; input[i] != '\0'; i++) {
        if (!check_numero(input[i])) {
            is_num = 0;
            break;
        }
    }

    if (is_num) {
        int num = atoi(input);
        printf("\nO valor %d é numérico\n", num);
        printf("\nSequência crescente:\n");
        imprimir_sequencia(num);
        printf("\n\nSequência decrescente:\n");
        imprimir_sequencia_invert(num);

        printf("\n\nNúmeros primos até %d:\n", num);
        for (int i = 2; i <= num; i++) {
            if (num_primo(i)) {
            printf("%d ", i);
            }
        }
        
        printf("\n\nNúmeros perfeitos até %d:\n", num);
        imprimir_num_perfeitos(num);

    }
    else {
        int is_alfanumerico = 1;
        for (int i = 0; input[i] != '\0'; i++) {
            if (!check_alfanumerico(input[1])) {
                is_alfanumerico = 0;
                break;
            }
        }

    if (is_alfanumerico) {
        printf("O valor %s é alfanumérico", input);
    }
    else {
        printf("O valor %s não é numérico nem alfanumérico", input);
    }
    }

    return 0;
}