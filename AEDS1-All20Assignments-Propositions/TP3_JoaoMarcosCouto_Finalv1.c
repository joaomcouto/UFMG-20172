#include <stdlib.h>
#include <stdio.h>

// funcao : calcula o digito verificador de isbn13 dados seus digitos
// recebe : arranjo de numeros contendo os digitos do isbn13
// retorna: valor do digito verificador do isbn13

int digito_isbn13 (int d[12]) {
  // soma das posicoes pares
  int pares   = d[0] + d[2] + d[4] + d[6] + d[8] + d[10];
  // soma das posicoes impares
  int impares = d[1] + d[3] + d[5] + d[7] + d[9] + d[11];

  // soma final
  int soma = pares + (impares * 3);

  // calcula digito verificador
  int dv = 10 - (soma % 10);

  // corrige digito verificador caso ele seja igual a 10
  if (dv == 10) {
    dv = 0;
  }

  // retorna digito verificador
  return dv;
}

// funcao : calcula o digito verificador de cpf dados seus digitos
// recebe : arranjo de numeros contendo os digitos do cpf
// retorna: valor do digito verificador do cpf

int digito_cpf (int d[9]) {
  // primeira soma de produtos
  int soma = d[8] * 2 + d[7] * 3 + d[6] * 4 + d[5] * 5 +
             d[4] * 6 + d[3] * 7 + d[2] * 8 + d[1] * 9 + d[0] * 10;

  // resto da soma
  int resto = soma % 11;
  // variaveis auxiliares
  int dezena, unidade;

  // define valor da dezena
  if (resto == 0 || resto == 1) {
    dezena = 0;
  } else {
    dezena = 11 - resto;
  }

  // segunda soma de produtos
  soma = dezena * 2 + d[8] * 3 + d[7] * 4 + d[6] *  5 + d[5] *  6 +
         d[4]   * 7 + d[3] * 8 + d[2] * 9 + d[1] * 10 + d[0] * 11;

  // resto da soma
  resto = soma % 11;

  // define valor da unidade
  if (resto == 0 || resto == 1) {
    unidade = 0;
  } else {
    unidade = 11 - resto;
  }

  // retorna digito verificador
  return dezena * 10 + unidade;
}

// funcao : calcula o digito verificador de cnpj dados seus digitos
// recebe : arranjo de numeros contendo os digitos do cnpj
// retorna: valor do digito verificador do cnpj

int digito_cnpj (int d[12]) {
  // primeira soma de produtos
  int soma = d[11] * 2 + d[10] * 3 + d[9] * 4 + d[8] * 5 + d[7] * 6 + d[6] * 7 +
             d[ 5] * 8 + d[ 4] * 9 + d[3] * 2 + d[2] * 3 + d[1] * 4 + d[0] * 5;

  // resto da soma
  int resto = soma % 11;
  // variaveis auxiliares
  int dezena, unidade;

  // define valor da dezena
  if (resto == 0 || resto == 1) {
    dezena = 0;
  } else {
    dezena = 11 - resto;
  }

  // segunda soma de produtos
  soma = dezena * 2 + d[11] * 3 + d[10] * 4 + d[9] * 5 + d[8] * 6 + d[7] * 7 +
         d[6]   * 8 + d[ 5] * 9 + d[ 4] * 2 + d[3] * 3 + d[2] * 4 + d[1] * 5 +
         d[0]   * 6;

  // resto da soma
  resto = soma % 11;

  // define valor da unidade
  if (resto == 0 || resto == 1) {
    unidade = 0;
  } else {
    unidade = 11 - resto;
  }

  // retorna digito verificador
  return dezena * 10 + unidade;
}

int main (int argc, char **argv) {
    int CPF[9] ; //array que recebera a entrada CPF
    int ISNB[12] ; //array que recebera a entrada ISNB
    int CNPJ[12] ; //array que recebera a entrada CNPJ
    int tipo ; //variavel que recebera o tipo de registro
    int i ; //variavel auxiliar
    int j ; //variavel que recebera o digito verificador das funcoes
    int digito ; //variavel que recebera o digito verificador do usuario
    while (scanf("%d", &tipo) && tipo > 0) { //le o tipo de registro e repete enquanto for maior que 0
        if (tipo == 1){ //avalia se o tipo de registro corresponde aaquele de livros (ISNB - 1)
            for (i = 0 ; i < 12 ; i++){ //loop de leitura do ISNB
                scanf ("%d" , &ISNB[i]) ;
            }
            scanf ("%d" , &digito); //le o digito verificador do usuario
            j = digito_isbn13 (ISNB) ; //atribui a j o valor de retorno da funcao que calcula o valor do digito verificador

        } else if (tipo == 2){ //avalia se o tipo de registro corresponde aquele de pessoas fisica (CPF - 2)
                for (i = 0 ; i < 9; i++) { //faz a leitura do CPF do usuario
                    scanf("%d", &CPF[i]) ;
                }
                scanf ("%d", &digito); //le o digito verificador do usuario
                j = digito_cpf (CPF) ;
            } else if (tipo == 3){ //avalia se o tipo de registro corresponde aaqueles de pessoas
                    for (i = 0 ; i < 12 ; i++){//faz a leitura do CNPJ do usuario
                    scanf ("%d" , &CNPJ[i]) ;
                    }
                    scanf ("%d", &digito) ;
                    j = digito_cnpj (CNPJ) ;
            }
        if (digito == j){ //avalia se o digito verificador do usuario e igual aaquele obtido da funcao
            printf("valido\n") ;//caso sim, escreve "valido"
        } else {
            printf("invalido\n") ;//caso nao, escreve "invalido"
        }
        digito = 0;
        j = 0 ;
    }
  return 0;
}
