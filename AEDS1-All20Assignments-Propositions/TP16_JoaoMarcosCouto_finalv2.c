#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int T ; // armazena o tamanho da string inicial
    int j ; //variavel auxiliar de loop
    char current[10000] ; //armazena a fileira "current" (atual) em analise
    scanf ("%s", current); //le a primeira fileira current
    T=strlen(current); //atribui a T o tamanho da string inicial
    char fileira[T] ; //armazena os valores das strings geradas afim de utliza-las como current posteriormente
    printf("%s", current); //imprime a linha inicial
    while(T>=2){ //loop principal do programa
        printf ("\n") ;
        for (j = 0 ; j <(T-1); j++){ //loop de atribuicoes e escrita de uma nova fileira gerada
            if(current[j]==current[j+1]){ //caso um elemento seja igual o proximo, atribui x a fileira[j]
                fileira[j]='x';
            } else { //do contrario, atribui o
                fileira[j]='o';
                }
            printf("%c", fileira[j]); //imprime o elemento da fileira
              }
        strcpy(current,fileira) ; //copia a fileira gerada para o current
        T = T - 1 ; //reduz em um o numero de elementos na fileira analisada para uso em loops
        }
    return 0 ;
    }
