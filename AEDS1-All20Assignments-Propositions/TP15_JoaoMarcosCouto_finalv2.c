#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    int N ; //numero de usuarios na lista
    int i , j ; //auxiliar de loop
    int metodo ; //recebe qual sera o criterio de organizacao
    int menor ; //recebe o indice do atual menor nome/sobrenome/email em analise
    typedef struct { //struct que armazena as informacoes de cada usuario
        char nome[21] ;
        char sobrenome[21];
        char email[101];
        } usuarios ;
    scanf ("%d", &N) ; //Le o numero de usuarios
    usuarios usuario[N] ; //Declara um array de N structs, uma para cada um dos N usuarios
    usuarios temp ; //Struct temporaria para realizar o swap na ordenacao dos usuarios
    for (i = 0 ; i < N ; i++) scanf ("%s %s %s" , usuario[i].nome, usuario[i].sobrenome, usuario[i].email) ; //Le o nome,sobrenome e email dos N usuarios
    scanf ("%d", &metodo) ; //Le qual dos tres campos sera utilizado para a ordenacao
    for (i = 0 ; i < N-1 ; i++){ //navega aapartir de todos os usuarios
        menor = i ; //assume o primeiro indice como o inicialmente
        for (j = i+1 ; j < N ; j++ ) //navega por todos os outros usuarios a fim de realizar as comparacoes
            if (((metodo==0) && (strcmp(usuario[menor].nome     , usuario[j].nome       ) > 0)) || //compara os usuarios aapartir do: nome
                ((metodo==1) && (strcmp(usuario[menor].sobrenome, usuario[j].sobrenome  ) > 0)) || //sobrenome
                ((metodo==2) && (strcmp(usuario[menor].email    , usuario[j].email      ) > 0))    //email
               ){
                temp = usuario[menor] ;  //realiza o swap da ordem dos usuarios caso um dos casos seja atendido
                usuario[menor] = usuario[j] ;
                usuario[j] = temp ;
                }
    }
    for (i = 0 ; i < N ; i++){ //imprime a ordenacao final dos usuarios
        printf ("%s %s %s\n", usuario[i].nome, usuario[i].sobrenome, usuario[i].email) ;
    }
return 0 ;
}
