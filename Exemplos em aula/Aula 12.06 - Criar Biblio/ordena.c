#include<stdio.h>

int main( int argc, char *argv[] ){
    int ord[5] = { 3, 5, 2, 1, 4 };
    int tmp = 0;

    for ( int i = 0; i < 5; i++ )
        printf("%i \t", ord[i]);
    printf("\n");

    for ( int i = 1; i < 5; i++ ) {
        for ( int j = i; j >= 1; j-- ) {
                if ( ord[j] < ord[j-1] ){
                    tmp = ord[j - 1];
                    ord[j - 1] = ord[j];
                    ord[j] = tmp;
                }
        }
    }
    for ( int i = 0; i < 5; i++ )
        printf("%i \t", ord[i]);
    printf("\n");

    for ( int i = 5-1; i >= 0; i-- )
        printf("%i \t", ord[i]);
    printf("\n");

    return 0;
}
