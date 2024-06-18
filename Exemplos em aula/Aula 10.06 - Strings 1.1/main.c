#include <stdio.h>

#define N 50

int main ()
{
  char frase[N];
  int i=0;

  printf("Digite uma frase: ");
  gets(frase);
  fflush(stdin);

  printf("Vc digitou: \n");
  while(frase[i]!= '\0')
    if (frase[i++] != ' ')
      putchar(frase[i-1]);
    else
      putchar('\n');
  printf("\n");
  
  return 0;
}