#include<stdio.h>

int main ( ) {
    int n, i=0, vr[ 1 ], resposta;
    vr[0] = 1;
    vr[1] = 2;
    vr[2] = 3;

    printf("Digite o numero de degraus da escada: ");
    scanf ( "%d", &n );

    if( n!= 1 || n != 2 || n!=3 ) {
        for (i=3;i<n;i++) {
            vr[ 0 ] = vr[ 1 ];
            vr[ 1 ] = resposta;
           resposta  = vr[ 0 ] + vr[ 1 ];
        }
    } else {
        resposta = n;
    }

    printf("\n%d maneiras.", resposta);
    
}