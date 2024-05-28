#include <stdio.h>

int main() {

  char ch1, ch2, ch3;
  int resp = 0;

  printf("Digite um caractere: ");
  scanf("%c", &ch1);

  resp = (ch1 >= 65 && ch1 <= 90) ? 1 : resp;
  resp = (ch1 >= 97 && ch1 <= 122) ? 2 : resp;
  resp = (ch1 >= 48 && ch1 <= 57) ? 3 : resp;
  if (resp == 0) {
    resp = 4;
  }

  if (resp == 1) {
    printf("\nO caractere é uma letra maiúscula\n");
  } else if (resp == 2) {
    printf("\nO caractere é uma letra minúscula\n");
  } else if (resp == 3) {
    printf("\nO caractere é um número\n");
  } else if (resp == 4) {
    printf("\nO caractere é um símbolo\n");
  }

  ch2 = 81;
  printf("\nO caractere %c tem os seguintes valores em ASCII:\n\n", ch2);
  printf("Decimal: %d\n", ch2);
  printf("Octal: %o\n", ch2);
  printf("Hexadecimal: %x\n", ch2);
  printf("Caratere: %c\n", ch2);

  ch3 = ch2 + 32;
  printf("\nch3 em diferentes formatos:\n");
  printf("Decimal: %d\n", ch3);
  printf("Octal: %o\n", ch3);
  printf("Hexadecimal: %x\n", ch3);
  printf("Caractere: %c\n", ch3);

  return 0;
}