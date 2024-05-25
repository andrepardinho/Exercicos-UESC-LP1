#include <stdio.h>
#include <limits.h>

int main () {
  printf("Number of bytes: %zu\n", sizeof(char) );
  printf( "CHAR_MAX:       : %d\n", CHAR_MAX);
  printf( "CHAR_MIN:       : %d\n", CHAR_MIN);
  return 0;
}