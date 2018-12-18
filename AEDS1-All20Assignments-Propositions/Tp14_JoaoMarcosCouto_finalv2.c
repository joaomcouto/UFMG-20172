#include <stdio.h>
#include <stdlib.h>

int main (){
    int T ; //tempo de jogo que o peronsagem deve evitar os portais
    int P ; //numero de portais que aparecerao
    int i , j ; //auxiliar de loop
    int Xj = 0, Yj = 0 ; //posicao do jogador
    char move ; //movimentacao do jogador
    int ganhando = 1 ; //
    scanf ("%d %d" , &T, &P) ;
    struct portais {
        int Xp[P] ; //Posicao X de um portal
        int Yp[P] ; //Posicao Y de um portal
        int Ti[P] ; //Tempo de inicio de um portal
        int Tf[P] ; //Tempo de fim de um portal
        } portal ;
    for (i = 0 ; i<P ; i++){ //Recebe as infomacoes de cada portal que aparecera na partida
        scanf ("%d %d %d %d", &portal.Ti[i], &portal.Tf[i], &portal.Xp[i], &portal.Yp[i]) ;
    }
    for (i = 0 ; i<T ; i++){ //Loop principal do jogo apos recebimento de meta informacoes
        printf ("Tempo %d (%d, %d): ",i, Xj, Yj ) ;
        for (j = 0 ; j<P ; j++){
                if ((portal.Ti[j] <= i) && (portal.Tf[j] >=i) && (portal.Xp[j]==Xj) && (portal.Yp[j]==Yj)){ //Avalia se existe um portal aberto na posicao atual do jogar
                    printf ("N\n") ; //Caso sim: Imprime N
                    ganhando = 0 ; //Altera o status de ganhando do jogador a fim de nao imprimir S posteriormente
                    break ; //Quebra o loop de avaliacao de portais
                }
        }
        if (ganhando == 1) { printf ("S\n"); } else break; //Caso apos avalicao dos portais o jogador ainda esteja gananhando, imprime S, do contrario, acaba o programa
        scanf (" %c", &move) ; //Le movimento do jogador
        if (move == 'C') Yj++; //Alteram a posicao do jogador de acordo com o movimento feito
        if (move == 'B') Yj--;
        if (move == 'E') Xj--;
        if (move == 'D') Xj++;
    }
return 0 ;
}

