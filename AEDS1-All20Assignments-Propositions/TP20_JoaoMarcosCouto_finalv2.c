#include <stdio.h>
#include <stdlib.h>

int main(){
    int L ; //largura - colunas
    int A; //altura - linhas
    int Xc, Yc ; //coordenadas iniciais
    int Xf, Yf ; //coordenadas finais
    int i, j, k ; //auxiliares de loop
    int numerodepassos = 0 ; //Armazena o numero de passos dado por um determinando conjunto de caminhos
    int posborda ; //Armazena a variacao na borda atual de possibilidades de andamentos para um determinado numero de passos
    int proxX, proxY ;//Armazena os valores possiveis para o proximo passo em determinando caminho

    scanf ("%d %d %d %d %d %d", &L, &A ,&Xc, &Yc, &Xf, &Yf) ; //Le a variaveis iniciais de montagens do labirinto

    char lab[L][A] ; //Declara a matriz que armazena as situacao de cada posicao no labirinto

    int AbordaX[A*L] ; //Armazena a coordenada X das atuais bordas alcancaveis apartir de um numero de passos
    int AbordaY[A*L] ; //Vide acima porem para coordenada Y
    int *bordaX=AbordaX; //Pointer auxiliar que faz a inversao/swap da borda atual e da proxima borda X
    int *bordaY=AbordaY;//Ideam para coordenada Y DA BORDA

    int finalborda = 0 ; //

    int novabordaXA[A*L] ; //Armazena as coordenadas X dos membros da nova borda
    int novabordaYA[A*L] ; //Armazena as coordenadas Y dos membros da nova borda
    int *novabordaX=novabordaXA ; //Atribui para cada pointer auxiliar da nova borda, a atual nova borda, para posteriormente realizar o swap
    int *novabordaY=novabordaYA ;// ^

    int finalnovaborda = 0 ;

    int *bordatemp ; //Pointer auxiliar de swap de bordas

    bordaX[0] = Xc ; //Atribui como primeira posicao da borda, o ponto de inicio no labirinto
    bordaY[0] = Yc ; // ^
    lab[Xc][Yc]= '*' ; //Inicializa a primeira posicao do labirinto como uma ja visita "*"
    numerodepassos = 1 ;//Atribui 1 ao numero de passos visto que a primeira posicao eh contada como um passo

    for (i = 0 ; i < A ; i++){ //Leitura dos elementos iniciais do labirinto
        for (j = 0 ; j < L ; j++){
            scanf (" %c", &lab[j][i]);
        }
    }
    while (lab[Xf][Yf] == '.'){ //Loop principal que eh executado ate que se visite a posicao final do labirinto

        if (numerodepassos > L*A ) { break ;} // Caso o numero de passos supere o numero de casas no labirinto, ele nao tem saida
        finalnovaborda = -1 ;
        for (posborda = 0 ; posborda <= finalborda ; posborda++){
            proxX = bordaX[posborda];
            proxY = bordaY[posborda];
            proxY-- ; //Condicional que realiza os caminhamentos para cima no labirinto
            if (proxY >= 0){
                if(lab[proxX][proxY] == '.'){
                    finalnovaborda++ ;
                    novabordaX[finalnovaborda] = proxX ;
                    novabordaY[finalnovaborda] = proxY ;
                    lab[proxX][proxY]= '*' ; //Coloca * nas posicoes ja visitadas pelo algoritmo
                }
            }


            proxX = bordaX[posborda];
            proxY = bordaY[posborda];
            proxY++ ;//Caminhamentos para baixo
            if (proxY < A ) {
                if(lab[proxX][proxY] == '.'){
                    finalnovaborda++ ;
                    novabordaX[finalnovaborda] = proxX ;
                    novabordaY[finalnovaborda] = proxY ;
                    lab[proxX][proxY]= '*' ;
                }
            }


            proxX = bordaX[posborda];
            proxY = bordaY[posborda];
            proxX-- ;//Caminhamento para a esquerda
            if (proxX >= 0) {
                if(lab[proxX][proxY] == '.'){
                    finalnovaborda++ ;
                    novabordaX[finalnovaborda] = proxX ;
                    novabordaY[finalnovaborda] = proxY ;
                    lab[proxX][proxY]= '*' ;
                }
            }


            proxX = bordaX[posborda];
            proxY = bordaY[posborda];
            proxX++ ;//Caminhamentos para direita
            if (proxX < L) {
                if(lab[proxX][proxY] == '.'){
                    finalnovaborda++ ;
                    novabordaX[finalnovaborda] = proxX ;
                    novabordaY[finalnovaborda] = proxY ;
                    lab[proxX][proxY]= '*' ;
                }
            }
        }
        bordatemp = bordaX ; //Atribuicoes que realizam o swap entre a borda antiga e a nova borda gerada pelos caminhamentos
        bordaX = novabordaX ;
        novabordaX = bordatemp ;

        bordatemp = bordaY ;
        bordaY = novabordaY ;
        novabordaY = bordatemp ;

        finalborda = finalnovaborda  ;
        numerodepassos++ ; //Apos calculados todos os caminhamentos com um determinado numero de passos, adiciona 1 ao numero de passos totais dados para o proximo loop
    }
    printf ( "%d", numerodepassos ) ; //Imprime o numero de passos dados assim que a posicao fnal do labirinto for atintigida (quebra do loop while )

return 0 ;
}
