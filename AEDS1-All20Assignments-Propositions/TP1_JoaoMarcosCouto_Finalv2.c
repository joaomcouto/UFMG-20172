#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, k = 0 ;// N=Numero de depositos em um teste ; K=Numero do teste
    int J, Z ; //J = Depositos para Joaozinho ; Z= Depositos para Zezinho
    int Dif ; //Dif = Saldo de diferença entre os valores depositados
   while ((scanf ("%i", &N)) && N>0) { //Ciclo while que le o num de depositos e avalia se ele e maior que zero
        Dif = 0 ;
        k += 1 ; // Aumenta em 1 o numero de teste antes de cada ciclo
        printf ("Teste %i\n", k); //Escreve o numero do teste a cada ciclo

        for ( ; N>0 ; N--){ //Mantem o ciclo de leituras rodando de acordo com o numero de depositos que serao feitos
            scanf ("%i %i", &J, &Z); //Le os valores dos deposito em cada ciclo
            if (J<0 || Z<0 ){ //Condicional que avalia se um dos depositos tem valor negativo
              printf ("Vovo Vitoria nao tira dinheiro dos cofrinhos.\n") ; //No caso de um dos valores ser negativo, escreve a resposta padrao para este caso
            } else { //Caso nenum dos dois depositos seja negativo, executa os statements abaixo
                Dif += (J - Z) ; //Modifica o saldo de diferenca
                printf ("%i\n", Dif ); //Escreve a diferenca entre os depositos para os meninos
              }
        }
    }
    return 0;
};

