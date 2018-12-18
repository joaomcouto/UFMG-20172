#include<stdio.h>
#include<stdlib.h>

int main(){
    int N ; //numero de testes a serem feitos
    int B ; //numero de bits utilizado pela memoria
    char C ; //operador a ser utilizado em determinado teste
    int num1, num2 ; //recebem os numeros a serem utilizados nos testes
    int resultado ; //armazena o resultado de cada teste para avaliacao
    int max ; //recebe o numero maximo do computador
    int maximo(int a) ; //prototipo de funcao recursiva de calculo no numero maximo

    scanf ("%d %d%" , &N, &B) ; //le o numero de testes e o numero de bits do usuario
    max = maximo (B) - 1; //atribui a max o retorno da funcao que calculo o numero maximo, menos 1
    for ( ; 0 < N ; N--){ //loop que le os numeros e operador dos testes, faz o calculo de cada teste e imprime a saida requisitada
        scanf ("%d %c %d", &num1 , &C, &num2 ); //le os numeros do teste e o operador
        if (C == '*' ) {resultado = num1*num2 ; } //caso o operador seja '*' faz a multiplicacao dos numeros
        if (C == '+' ) {resultado = num1+num2 ; } //caso o operador seja '+' faz a soma dos numeros
        if (resultado > max ) printf ("OVERFLOW\n") ; //avalia se o resultado da operacao e maior que o numero maximo e imprime "overflow" se sim
        else printf ("OK\n") ; //Caso nao, imprime "ok"
    }


}

int maximo(int a) { //funcao recursiva que calcula 2 elevado ao numero de bits da memoria
    if (a != 0){ //enquanto o parametro da chamada for diferente de 0, chama a funcao com o parametro original menos 1 ;
        return (2*maximo(a-1)) ;
    }
    else //retorna 1 quando a recursao atinge sua interacao tal que o parametro a sera 0
        return 1 ;

}
