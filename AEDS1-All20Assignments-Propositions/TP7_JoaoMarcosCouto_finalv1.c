#include <stdio.h>
#include <stdlib.h>

int main(){
    int n ; //variavel que recebe o numero de matrizes do usuario
    int lin ; //variavel que recebe o numero de linhas de cada matriz do usuario
    int col ;// recebe o numero de colunas de cada matriz do usuario
    int i , j , k ; //variaveis auxiliares de loop
    scanf ("%d", &n); //le o numero de matrizes do usuario
    scanf ("%d %d", &lin , &col ); //le o numero de linha e colunas de cada matriz do usuario
    int M[n][lin][col]  ; //variavel que guarda as matrizes do usuario
    float F[lin][col]  ; //matriz que guarda as medias aritmeticas das posicoes
    for (k = 0 ; k < n ; k++){ //inicializacao das matrizes
        for (i = 0 ; i < lin ; i++){
            for (j = 0; j < col; j++){
                F[i][j] = 0 ;
                M[k][i][j] = 0 ;
            }
        }
    }
    for (k = 0 ; k < n ; k++){ //le o valor das posicoes do usuario e incrementa soma em F para calculo de media
        for (i = 0 ; i < lin ; i++){
            for (j = 0; j < col; j++){
                scanf("%d", &M[k][i][j]) ;
                F[i][j] += M[k][i][j] ;
            }
        }
    }
        for (i = 0 ; i < lin ; i++){ //divide a soma das posicoes pelo numero n de matrizes, obtendo a media de cada
            for (j = 0; j < col; j++){
                F[i][j] /= n ;
            }
        }
        for (i = 0 ; i < lin ; i++){ // imprime as medias de cada posicao
            for (j = 0; j < col; j++){
                printf ("%.2f " , F[i][j]) ;
            }
            printf ("\n") ;
        }




return 0;
}
