#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, L ; //numero de vendedores e ligacoes
    int i, j ; //auxiliares de loop
    int total = 0, menor = 0 ; //armazenam  os indices do vendedor com maior tempo total e menor tempo corrente
    scanf ("%d %d", &N, &L) ; //le o numero de vendedores e ligacoes
    int ligacoes[L] ; //array que armazena os tempos da ligacoes
    int vendedores[N] ; //array que armazena a soma do tempo de cada vendedor
    for (i = 0 ; i < L ; i++){ // le a duracao de cada ligacao
        scanf ("%d", &ligacoes[i]);
    }
    for (i = 0 ; i < N ; i++){ //atribuicao inicial da primeira ligacao de cada vendedor
        vendedores[i] = ligacoes[i] ;
    }
    for (i = N ; i < L ; i++){ //decide qual dos vendores tem o menor tempo corrido e atribui a ele a proxima ligacao
        for (j = 1 ; j < N ; j++){
            if (vendedores[j] < vendedores[menor]){
                menor = j ;
            }
        }
        vendedores[menor] +=ligacoes[i] ;
        menor = 0 ;
    }
    for (j = 1 ; j < N ; j ++){ //avalia qual o maior tempo corrido entre os vendedores
        if (vendedores[j] > vendedores[total]){
            total = j ;
        }
    }
    printf("%d\n" , vendedores[total]) ; //imprime o maior tempo entre os vendedores

return 0 ;
}
