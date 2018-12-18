#include <stdio.h>
#include <stdlib.h>

int main(){
    char charcara[49]; //recebe o primeiro char de cada carta
    int valorcarta[48]; //recebe o valor de pontos de cada carta
    char naipecarta; //recebe o naipe na leitura das cartas
    int i ; //variavel auxiliar de loop
    int resposta ; // recebe a resposta do jogadores em suas respectivas rodadas
    int pj = 0, pz = 0 ;


    for (i = 0 ; i < 48 ; i++){ //atribui ao array valorcarta os valores em pontos das cartas lidas
        scanf("%c%c ", &charcara[i] , &naipecarta) ;
        if (charcara[i] == 65){ //avalia se a carta em avaliacao e um As
            valorcarta[i] = 1 ;
        } else if (charcara[i] == 75 || charcara[i] == 74 || charcara[i] == 81 ){ //avalia se a carta em avaliacao e K,J ou Q
            valorcarta[i] = 10 ;
            } else {valorcarta[i] = charcara[i] - 48 ;}
    }
    i = 0 ;
    while (scanf ("%d", &resposta) && resposta == 1){ //loop de jogada de joaozinho
        pj +=  valorcarta[i] ;
        i++ ;
        printf("%d\n", pj) ;
        if (pj>21){ //declara que a pontuacao de joaozinho superou os 21 pontos "estourou"
            printf ("Estourou\n") ;
            break ; //sai do ciclo de jogada caso a pontuacao tenha passado de 21
        }
    }

    if (resposta == 0){
        printf ("Parou\n") ;
    }
    while (scanf ("%d", &resposta) && resposta == 1){ //loop de jogada de zezinho
        pz +=  valorcarta[i] ;
        i++ ;
        printf("%d\n", pz) ;
        if (pz>21){ //declara que a pontuacao de zezinho superou os 21 pontos "estourou"
            printf ("Estourou\n") ;
            break ; //sai do ciclo de jogada caso a pontuacao tenha passado de 21
         }
    }
    if (resposta == 0){
        printf ("Parou\n") ;
    }


    if (pj <= 21 && pz <= 21)   { //avalia quem e o ganhador da rodada caso ambos os pontos dos meninos forem menor de 21
        if ( pj > pz ){ //declara joaoziho vencedor caso sua pontuacao seja maior que de zezinho
            printf ("Joaozinho\n") ;
        } else if (pj == pz) { //declara empate caso a pontuacao dos meninos seja igual
                printf ("Empate\n") ;
                } else {
                        printf ("Zezinho\n") ; //declara zezinho ganhador caso nenhum dos ultimos dois casos forem atendidos
                        }
    }   else { //avalia o ganhador caso pelo menos um dos meninos tenham mais de 21 pontos
            if(pz <= 21) { //declara zezinho ganhador caso sua pontuacao seja menor ou igual a 21
                printf("Zezinho\n");
            }   else {
                    if(pj <= 21){ //declara joaozinho ganhador caso sua pontuacao seja menor ou igual a 21
                        printf("Joaozinho\n");
                    }   else { //declara empate caso nenhuma das condicoes anteriores forem atendidas
                            printf ("Empate\n") ;
                        }
                }
        }


    return 0 ;
    }




