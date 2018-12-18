#include <stdio.h>
#include <stdlib.h>

int banco[1000] ; //armazena quem comanda cada banco

int root(int b){ //Funcao root que retorna qual o banco "pai" de qualquer banco enviado como parametro
    if ( b < 0 ) { //Caso o banco nao existe, retorna o proprio indice do banco que o domina (ele mesmo)
        return b ;
    }
    if (banco[b] == b ) return b ; //Caso o banco seja dono de si mesmo, retorna seu proprio indice
        else return root(banco[b]) ; //Do contrario, rechama a funcao com o banco efetivamente dono dele, ate que se encontre o node(banco) "pai de todos"
    }

int main (){
    char op ; //char que armazena a operacao a ser feita
    int par1, par2, par3; //armazenam os parametros das operacoes
    int i, j ; //variaveis de loop
    int pertencem = 0 ;


    for (i = 0 ; i < 1000 ; i++){ //inicializacao do vetor banco, onde -5 significa que um banco ainda nao foi declarado/criado
            banco[i] = -5 ;
    }

    while ((scanf (" %c" , &op)) && (op!='T')){ //loop principal do programa que termina em caso de operador 'T'
        if (op == 'C'){
            for (i = 0 ; i < 1000 ; i++){ //Loop executado no caso de operador de criacao de um banco
                if (banco[i]==-5) { banco[i] = i ; break ; } //Procura no array banco qual a primeira posicao cujo banco ainda nao foi declara, e o declara com dono sendo ele mesmo
            }
        }
        if (op== 'U'){
            scanf("%d %d", &par1 , &par2) ;
            if ((banco[par1-1] >= 0) && (banco[par2-1]>= 0) && (banco[par2-1]==(par2-1)) && (banco[par1-1]==(par1-1))){ //Atribui como dono do banco parametro 2 o bacno parametro 1 apos avaliar condicoes de validade
                    banco[par2-1] = par1-1 ;
            }
        }
        if(op== 'V'){
           scanf ("%d %d %d", &par1, &par2 , &par3) ;
                if ((banco[par2-1]==(par1-1)) && (banco[par3-1]==(par3-1)) && (banco[par1-1]==(par1-1)) && (banco[par3-1] >= 0)){ //Atribui como dono do banco parametro 2 o banc o parametro 3 caso 2 seja originalmente pertencente a 1
                    banco[par2-1] = par3-1 ;
           }
        }
        if(op=='S'){
           scanf ("%d %d", &par2, &par1);
                if (banco[par2-1]==(par1-1)) { //Apos avaliar que o banco parametro 2 realmente pertence ao 1, atribui ao banco parametro 2 o seu proprio indice
                   banco[par2-1] = par2-1 ;
                }
        }
        if(op=='F'){
            scanf ("%d", &par1) ;
            if ((banco[par1-1]==(par1-1)) && (banco[par1-1] >= 0)){ //Realiza a finalizacao de um banco, fazendo que seus bancos diretamente "filhos" se tornem donos de si mesmo
                for (i=0; i<1000; i++){
                    if (banco[i]==par1-1){
                        banco[i]= i ;
                    }
                }
                banco[par1-1]=-1 ;
            }
        }
        if(op=='I'){ // Loop de avaliacao de se dois bancos percentem a uma mesma instituicao
            scanf ("%d %d", &par1 , &par2) ;
            if ((banco[par1-1] >= 0) && (banco[par2-1] >= 0) && (root(par1-1)==root(par2-1))){ //Utiliza a funcao recursa root para achar o banco raiz "pai de todos" e os compara entre os bancos parametros
                   printf ("S\n");
                } else {
                   printf ("N\n") ;
                }
        }
    op = 0 ;
    }
return 0 ;
}
