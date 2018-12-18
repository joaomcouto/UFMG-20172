#include <stdio.h>
#include <stdlib.h>

int main (){
    int c = 1 ; // variavel de comando a ser tomado
    int v = 1 ; // variavel do comando a ser tomado
    int pj = 0 , pz = 0 , pp = 0 , pm = 0 ; //pontos de cada jogador
    int *pa ; //ponteiro utilizado para modificar o valor do pontos do jogador atual
    int jogadorinicial ;
    scanf ("%d" , &jogadorinicial);
    if (jogadorinicial == 1) {pa = &pj ;} //modifica o endereco inicial do ponteiro modificador de pontos
    if (jogadorinicial == 2) {pa = &pz ;}
    if (jogadorinicial == 3) {pa = &pp ;}
    if (jogadorinicial == 4) {pa = &pm ;}
    scanf ("%d %d", &c, &v) ;
    while (c>0 || v>0){ //loop principal de rodadas pos escolha de jogador inicial
            if (c == 1){  //loop que modifica
            if (v ==1) {pa = &pj ;}
            if (v == 2) {pa = &pz ;}
            if (v == 3) {pa = &pp ;}
            if (v == 4) {pa = &pm ;}
        }
        if (c == 2){ //altera o valor vinculado aa variavel de pontos apontada pelo ponteiro modificador
            *pa = *pa + v ;
        }
        if (pj < 0) pj = 0 ; //reseta para 0 o numero de pontos dos jogadores caso este torne-se menor que zero
        if (pz < 0) pz = 0 ;
        if (pp < 0) pp = 0 ;
        if (pm < 0) pm = 0 ;
        if (pa == &pj) printf ("Joaozinho ") ; //escreve o nome do jogador atual de acordo com a variavel apontada pelo ponteiro
        if (pa == &pz) printf ("Zezinho ") ;
        if (pa == &pp) printf ("Pedro ") ;
        if (pa == &pm) printf ("Maria ") ;
        printf ("%d x %d x %d x %d \n", pj, pz , pp , pm); //escreve o placa dos jogadores no termino de cada rodada de comando
        scanf ("%d %d", &c, &v) ; //le os valores de c e v para o proximo loop de rodada
    }




return 0 ;
}
