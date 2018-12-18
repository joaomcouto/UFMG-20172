#include <stdio.h>
#include <stdlib.h>

int main(){
    int P ; //comprimento da praia em metros
    int S ; //numero de sorveteiros
    int V ; //numero de regioes com vagas ocupadas
    int i , k, l ; //auxiliares de loop
    int vaga ;
    int inicial, fim ; // armazenam o inicio e o fim de determinado conjunto
    while(scanf ("%d %d %d", &P , &S, &V) && ((P != 0) || (S!= 0) || (V!=0))){ //loop central do programa, le os dados basicos
        int praia[P] ; //armazena o status ocupabilidade de cada vaga (1 metro) na praia
        for (i = 0 ; i < P; i++) { praia[i] = 0; } //inicializacao do array praia
        for (i = 0 ; i < S ; i++){ //loop que recebe os conjuntos de atuacao dos sorveteiros
            scanf ("%d %d", &inicial, &fim) ;
            for (k = inicial ; k <= fim ; k++){ //loop que coloca no lugar equivalente de praia os locais com sorveteiros
                praia[k] = 1 ;
            }
        }
        for (i = 0 ; i < V ; i++){ //loop que altera o estado de ocupabilidade de um local de acordo com as vagas
            scanf("%d %d", &inicial, &fim ) ;
            for (k = inicial ; k <= fim ; k++){
                praia[k] = 0 ;
            }
        }
        vaga = 0 ;
        for (i = 0 ; i < P ; i++){ //loop que imprime os conjuntos de locais com vagas e sorveteiros
            if (praia[i]==1) { //imprime o local de comeco de um conjunto viavel de vagas
                printf ("%d ", i ) ;
                vaga = 1 ;
                for(k=i+1 ; k< P ; k++){ //imprime o final de cada conjunto de vagas viaveis
                    if (praia[k] == 0) {
                        printf ("%d\n", k-1) ;
                        i = k ;
                        break ;
                    }
                }
                if ( k >= P ) { //caso percorra a praia ate o final sem achar um fim, imprime o valor da borda da praia
                        printf ("%d\n", k-1) ;
                        i = k ;
                }
            }
        }
        if (vaga==0) printf ("Nao ha vagas\n") ;//caso nao existam conjuntos de vagas viaveis, imprime "nao ha vagas"
    }


return 0 ;
}
