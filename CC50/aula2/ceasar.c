/*
O problema trabalha a Cifra de Cesar, uma famosa cifra que consiste na ideia de adicionar o valor de uma chave
ao valor alfanumerico de uma letra em uma sequencia de letras. A partir disso, essa nova mensagem ja estara
criptografada e pode ser revertida a partir da subtracao do valor da chave do alfanumerico da letra criptografada

portanto, o pseudocodigo desse problema:

INICIO
1. Receber a mensagem que sera criptografada.
2. Iterar por cada letra e substitui-la pela nova correspondente.
3. Retornar a nova mensagem
FIM
*/

#include <stdio.h>
#include <string.h>

int main (void){
    //data dictionary
    char mensagem[100000];
    int key;

    //input gathering
    printf("plaintext: ");
    fgets(mensagem, 100000, stdin);

    //incrypting and printing
    int n = strlen(mensagem);
    printf("cyphertext: ");
    for (int i = 0; i < n; i++){
        printf("%c", mensagem[i] + 1);
    }

    //end of the function
    return 0;
}

/*SEGUINTE PEDRO DO FUTURO, o output tambem esta convertendo o " " para o proximo caractere. tudo errado
abre a tabela ascii, usa o %26 que vai dar certo fe em deus
*/