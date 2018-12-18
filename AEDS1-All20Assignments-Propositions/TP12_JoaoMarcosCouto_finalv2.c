#include <stdio.h>
#include <stdlib.h>

int main (){
    int n ; //numero de testes a serem realizados
    int i = 0 ; //auxiliar de loop
    double x, y ; //coordenadas dos moradores
    double divx, divy ; //coordenadas do ponto divisor
    scanf ("%d %lf %lf", &n, &divx , &divy) ; //le o numero de consultas que serao feitas
    while (scanf ("%lf %lf", &x, &y) && i<n){ //loop principal que le as coordenadas de cada consulta
        i++ ;
        if (x == divx){ //caso a coordenada x da consulta seja igual a Px do ponto divisor, avalia dois casos possiveis
            if (y > divy) printf ("SO\n"); else printf ("NO\n") ; //Avalia se o valor do y e maior ou menor que Py, imprimindo a cidade correspondente
        }
        if (y == divy){ //caso a coordenada y da consulta seja igual a Py do pinto divisor, avalia dois casos possiveis
            if (x > divx) printf ("NO\n") ; else printf ("NE\n") ;//Avalia se o valor de x e maior ou menor que Px, imprimindo a cidade correspondente
        }
        if (x > divx){ //avalia se a coodenada x sendo consultada e maior que Px
            if (y >divy) printf ("SE\n") ; else printf ("NE\n") ;//caso sim, avalia os dois casos possiveis para y e imprime o nome da cidade correspondente
        } else if (y > divy) printf ("SO\n") ; else printf ("NO\n") ; //caso nao, avalia os dois casos possiveis para y e imprime o nome da cidade correspondente
    }
return 0;
}
