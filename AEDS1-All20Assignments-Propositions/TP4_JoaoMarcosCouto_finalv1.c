#include <stdio.h>
#include <stdlib.h>

int main (){
    int N = 1; //numero de resultados encontrados
    int P = 1; //numero de resultados por pagina
    int i ; //variavel auxiliar de loop
    scanf ("%d %d", &N , &P); //scan inicial de N e P
    while (P > 0 || N > 0){ //escreve o logotipo de acordo com o numero de paginas do resultado
        printf ("P");
        for (i = 1 ; i <= N/P ; i++){  //escreve "o" N/P vezes
            printf ("o") ;
        }
        if (N%P > 0) { //escreve mais um "o" caso a divisao N/P nao seja exata
            printf ("o") ;
        }
        printf ("dle") ; // escreve a parte final do logotipo
        printf ("\n") ;
        scanf ("%d %d", &N , &P); //le N e P para a proxima execusao do loop
    }

return 0 ;
}
