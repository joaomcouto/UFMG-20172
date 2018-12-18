#include <stdio.h>
#include <stdlib.h>

int main (){
    int n ; //variavel numero de abacaxis por viagem
    int i ; //variavel auxiliar de loop
    int max ; //vairavel que guarda o indice do abacaxi com maior ag em cada viagem
    struct abacaxi { //guarda os valores de cada abacaxi
        int ad ; //variavel de docura de cada abacaxi
        float ap; // variavel preco de cada abacaxi
        float vc ; //variavel confianca do vendedor de cada abacaxi
        float ag ; //variavel ganho real de cada abacaxi
    };

    while (scanf ("%d", &n) && n > 0){ //loop principal do algoritmo que le n e eh executado enquanto n for maior que 0
        struct abacaxi ab[n]; //declaracao de arranjo de structs abacaxi de acordo com a entrada n do usuario
        for (i = 0 ; i < n ; i++){ //le o valor de docura para cada abacaxi
            scanf ("%d", &ab[i].ad) ;
        }
        for (i = 0 ; i < n ; i ++){ //le o valor do preco de cada abacaxi
            scanf ("%f" , &ab[i].ap) ;
        }
        for (i = 0 ; i < n ; i ++){ //le o valor de confianca do vendedor de cada abacaxi
            scanf ("%f" , &ab[i].vc) ;
        }
        for (i = 0 ; i < n ; i++ ){//calcula o valor de ganho real de cada abacaxi
            ab[i].ag = (ab[i].ad*ab[i].vc)/ab[i].ap ;
        }
        max = 0 ;
        for (i = 0 ; i < n ; i++){ //compara os valores de ganho real de cada abacaxi e atribui a max o indice do maior deles
            if (ab[i].ag > ab[max].ag){
                max = i ;

            }
        }
        printf ("%d %.2f %.5f %.5f/n", ab[max].ad , ab[max].ap , ab[max].vc , ab[max].ag) ; //imprime os valores ad, ap, vc e ag do abacaxi com maior ag

    }

return 0 ;
}
