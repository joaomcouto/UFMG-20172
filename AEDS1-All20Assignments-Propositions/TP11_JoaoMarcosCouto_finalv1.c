#include <stdio.h>
#include <stdlib.h>

int main (){
    int h1, m1, s1, h2, m2, s2 ; //horas, minutos, segundos iniciais e finais
    int tt1 , tt2, ttdif; //totais em segundos do horario inicial, final e a diferenca entre eles
    int hf = 0,mf = 0,sf = 0 ; //deltas das horas, minutos e segundos entre o horario inicial e final
    while (scanf ("%d %d %d %d %d %d", &h1, &m1, &s1, &h2 , &m2, &s2) && (h1+m1+s1+h2+m2+s2) != -6){ //loop central
        tt1 = 3600*h1 + 60*m1 + s1 ; //calculo o total em segundos do primeiro horario
        tt2 = 3600*h2 + 60*m2 + s2 ; //cacula o total em segundos do segundo horario
        ttdif = tt2 - tt1 ; //calcula a diferenca em segundos entre os dois horarios
        if (tt2 >= tt1){ //avalia se o segundo horario e maior que o primeiro:
            hf = (ttdif/3600) ; //atribui aas horas finais a divisao dos segundos de diferenca totais por 3600
            mf = (ttdif%3600)/60 ;//atribui aos minutos finais a divisao por 60 do resto da divisao da diferenca de segundos totais por 3600
            sf = (ttdif%3600)%60 ;//atribui aos segundos finais a quantidade de segundos que restaram apos atribuicao de horas e minutos
            printf ("%02d:%02d:%02d\n" , hf, mf, sf) ; //imprime a diferenca temporal entre os dois horarios
        } else { //caso nao seja:
            ttdif += 86400 ; //adiciona aa diferenca total de segundos o equivalente a 24 horas (86400 segundos)
            hf = (ttdif/3600) ;
            mf = (ttdif%3600)/60 ;
            sf = (ttdif%3600)%60 ;
            printf ("%02d:%02d:%02d\n" , hf, mf, sf) ;
            }
    }
return 0 ;
}
