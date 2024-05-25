/* #include <stdio.h>

int main( ) {

    
  int resp = 0;
  int i = 0;  
  for ( i =0; i < 10; i++ ) {
    resp += i;
    
    printf("Mensagem: %d\n", i);
  }

  printf("Total: %d %d\n", resp, i);
    
  return 0;
} */



/* int main( ) {

#include <stdio.h>

  unsigned int resp = 0;
  int limite = 10;
  
  for ( int i = 0; i < limite; i++ ) {
    for (int j = 0; j < limite; j++ ) {
      
      resp += i;

    printf("Mensagem: %d %d\n", i, j);
    }
  }

  printf("Total: %d\n", resp);

  return 0;
} */

/* DE TRÁS PARA FRENTE

#include <stdio.h>

int main( ) {

  unsigned int resp = 0, resp2 = 0, resp3 = 0;
  int limite = 0;

  for ( int i = 9; i >= limite; i-- ) {
    resp +=i;
    for (int j = 9; j >= limite; j-- ) {
    resp2 += j;
    for (int z = 9; z >= limite; z--) {
    resp3 += z;
        
    printf("Mensagem: %d %d %d\n", i, j, z);
      }
    }
  }

  printf("Total: %d %d %d\n", resp, resp2, resp3);

  return 0;
} */

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[]) {

  unsigned int resp = 0, resp2 = 0, resp3 = 0;

  

  
  int limite1 = atol(argv[1]);
  int limite2= atol(argv[2]);
  int limite3 = atol(argv[3]);

  for ( int i = limite1; i > 0; i-- ) {
    resp +=i;
    for (int j = limite2; j > 0; j-- ) {
    resp2 += j;
    for (int z = limite3; z > 0; z--) {
    resp3 += z;

    printf("Mensagem: %d %d %d\n", i, j, z);
      }
    }
  }

  printf("Total: %d %d %d\n", resp, resp2, resp3);

  return 0;
}
