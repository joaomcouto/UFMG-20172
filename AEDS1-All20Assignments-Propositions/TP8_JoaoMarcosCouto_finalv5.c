#include <stdio.h>
#include <stdlib.h>

int main(){
    int N ; //numero de escolas
    int Q ; //numero de quesitos
    int i , j , k ; //auxiliares de loop
    int notas[5] ; //recebe as notas das escola de samba
    int notatemp ; //variavel auxiliar de swap de dados
    int ganhadora ; // recebe o indice da escola com maior soma de pontos
    scanf ("%d %d" , &N, &Q) ;
    struct escolas { //struct que armazena o nome das escolas e suas notas finais
        char nome[100] ; //armazena o nome de cada escola
        int notafinal ; //armazena a notafinal de cada escola
    };
    struct escolas escola[N] ; //declara structs de acordo com o numero de escolas de samba indicas pelo usuario

    for ( i = 0 ; i < N ; i++ ){ //loop principal que realiza operacoes sobre uma escola de cada vez
        scanf ("%s", &escola[i].nome) ; //le o nome de cada escola
        escola[i].notafinal=0;
            for (j = 0; j < Q ; j++){

                for (k = 0 ; k < 5 ; k++){ //le as notas da escola cujas notas estao sendo digitadas pelo usuario
                    scanf ("%d" , &notas[k]);
                }
                for (k = 1 ; k < 4 ; k++){ //organiza o array nota de forma que a maior nota fique em [4] e a menor em [0]
                    if (notas[k] < notas[0]){ //transfere o elemento corrente para a posicao [4] caso ele seja maior
                        notatemp = notas[0] ;
                        notas[0] = notas[k] ;
                        notas[k] = notatemp ;
                    }
                    if (notas[k] > notas[4]){ //transfere o elemento corrente para a posicao [0] caso ele seja menor
                        notatemp = notas[4] ;
                        notas[4] = notas[k] ;
                        notas[k] = notatemp ;
                         if (notas[k] < notas[0]){ //transfere o elemento corrente para a posicao [4] caso ele seja maior
                            notatemp = notas[0] ;
                            notas[0] = notas[k] ;
                            notas[k] = notatemp ;
                        }
                    }
               }
                for (k = 1 ; k < 4 ; k++){
                    escola[i].notafinal +=  notas[k] ;
                }
                printf ("A nota acumulada da escola %s eh %d \n" , escola[i].nome, escola[i].notafinal) ;
            }
    }

    ganhadora = 0 ;
    for (i = 0 ; i < N ; i++){ //avalia qual e o indice do array escola que contem a maior notafinal
        if (escola[ganhadora].notafinal < escola[i].notafinal){
            ganhadora = i ;
        }
    }
    printf ("%s", escola[ganhadora].nome) ; //escreve o nome da escola com a maior notafinal, ou seja, a ganhadora
return 0 ;
}
