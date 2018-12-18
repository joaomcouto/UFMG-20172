
    #include <stdlib.h>
    #include <math.h>
     
     int main (){
        int N ; //numero de partidas jogadas
        int cartaJ , cartaZ ; //valores das cartas dos meninos
        int somaJ , somaZ ; //valores das somas das cartas de cada menino em cada partida
        int difJ , difZ ; //diferencas das somas do meninos em relacao a 21
        int distJ , distZ ; //distancia da soma dos meninos em relacao a 21
        int pontosJ = 0 , pontosZ = 0 ; //valores dos pontos dos meninos
    
        scanf ("%i", &N) ; //Le o numero de partidas que serao jogadas
        for ( ; N>0 ; N--){ //Ciclo de joga que rodara de acordo com o numero de partidas lidas
            somaJ = 0 ;
            somaZ = 0 ;
            do { //Le os valores das cartas de Joaozinho
                scanf ("%i", &cartaJ) ;
                somaJ += cartaJ ;
            } while (cartaJ > 0 );
            do { //Le os valores das cartas de Zezinho
                scanf ("%i", &cartaZ) ;
                somaZ += cartaZ ;
            } while (cartaZ > 0 );
            difJ = 21 - somaJ ; //Calcula a diferenca em relacao a 21 da soma de Joaozinho
            difZ = 21 - somaZ ;//Calcula a diferenca em relacao a 21 da soma de Zezinho
            distJ = abs(difJ); //Calcula a distancia em relacao a 21 da soma de Joaozinho
            distZ = abs(difZ);//Calcula a distancia em relacao a 21 da soma de Zezinho
            if (distJ < distZ){ //Atribui as pontuacoes no caso de Joaozinho ganhar a partida
                pontosJ += 2 ;
                pontosZ -= 1 ;
            } else if(distJ > distZ){ //Atribui as pontuacoes no caso de Zezinho ganhar a partida
                        pontosZ += 2;
                        pontosJ -= 1 ;
                } else { //Atribui as pontuacoes no caso de ocorrer empate
                        pontosZ += 1 ;
                        pontosJ += 1 ;
                    }
            printf ("Placar: %i x %i\n", pontosJ , pontosZ); //Escreve o placar final de cada partida
            }
            if (pontosZ>pontosJ){ //Declara Joaozinho como perdedor caso seus pontos sejam menores que de Zezinho
                    printf ("Joaozinho\n");
            } else if (pontosJ>pontosZ){ //Declara Zezinho com perdedor caso seus pontos sejam menores que de Joaozinho
                        printf("Zezinho\n");
                } else { //Declara empate casos as pontuacoes dos meninos sejam iguais
                        printf ("Ambos\n");
                    }
    
   
         return 0 ;
      }
