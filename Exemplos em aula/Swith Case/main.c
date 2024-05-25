#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] ) {
  int diaSemana = 0;
  if( argc == 2) {
    diaSemana = atoi(argv[1]);
  }
  else if (argc > 2 ) {
    printf("Muitos argumentos.\n");
    
    return 1;
  }
  else {
    printf("Entre com o dia da semana (número): ");
    //scanf("%d", &diaSemana);

  }

  switch (diaSemana) {
    case 1:
      printf("Domingo\n");
      break;

    case 2:
      printf("Segunda-feira\n");
      break;


    case 3:
      printf("Terça-feira\n");
      break;

    case 4:
      printf("Quarta-feira\n");
      break;

    case 5:
      printf("Quinta-feira\n");
      break;

    case 6:
      printf("\x1b[36mSEXTOU!\x1b[37m\n");
      break;

    case 7:
      printf("Sábado\n");
      break;

    default:
      printf("Semana de %d dias?\n", diaSemana);
      break;
  }

  return 0;
}
