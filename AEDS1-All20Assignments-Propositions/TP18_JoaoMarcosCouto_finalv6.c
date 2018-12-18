#include <stdlib.h>
#include <stdio.h>

int N ; //numero de bairros
int A ; //numero de avenidas
int i, j ; //auxiliares de loop
int o, d ; //auxiares de loop

int * avenida ;

int AvenidaConsulta( int a , int b){ //funcao para obtencao de valor dads coordenadas em [N]x[N]
    return avenida[ ( a * N ) + b ] ;
}



int AvenidaAtribui( int a , int b , int HaAvenida ){ //funcao que atribui valor a uma posicao do vetor dadas coordenadas equiavalente em [N][N]
    avenida[ ( a * N ) + b ] = HaAvenida ;
}


int NovoCaminho=1;

int caminho(int a , int b) { // retorna 1 se ha caminho, retorna 2 se nao ha caminho
    int m, n ;
    if (AvenidaConsulta(a,b)==0){
        AvenidaAtribui(a,b,3) ;
         for (m = 0 ; m < N ; m++){
            if ( ( m != a ) && ( m != b ) && ( caminho( a, m ) == 1 ) && ( caminho( m, b ) == 1 ) ){
                    AvenidaAtribui(a,b,1) ;
                    NovoCaminho=1;
            }
        }

     }
    return AvenidaConsulta(a,b) ;
}


int main(){

    scanf ("%d %d", &N , &A) ;//Le o numero de bairros e avenidas respectivamente

    int Avenida[N*N];
    avenida=Avenida ;

    for (i = 0 ; i < N*N; i++){ //Inicializacao dos valores de avenida
        Avenida[i] = 0 ;
    }


    for (i = 0 ; i < A ; i++){ //Le quais sao as A avenidas (onde começam e terminam
        scanf("%d %d", &o, &d) ;
        AvenidaAtribui(o-1,d-1,1);

    }


    while ( NovoCaminho == 1 ){ //Marca com zero enquanto houveram nossos caminhos a serem processdaos
        for (i = 0 ; i < N*N; i++){
            if ( Avenida[i] == 3 ){
                Avenida[i] = 0 ;
            }
        }
        NovoCaminho=0;
        for (i = 0 ; i < N ; i++){ // Busca cminhos possieveis entre cada par de bairros
            for (j =0 ; j < N ; j++){
                if (i != j){
                    caminho(i,j);
                }

            }
        }
    }

    for (i = 0 ; i < N ; i++){ // imprime tods os pares possiveis de origem e destino, avaliando se existem ou nao
        for (j =0 ; j < N ; j++){
            if (i != j){
                printf ("%d -> %d: ", i+1 , j+1) ;
                if (caminho(i,j)==1) printf ("S\n");
                    else printf ("N\n") ;
            }

        }
    }
return 0;
}
