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
    printf("key: ");
    scanf("%d", &key);
    if (key < 0){
        key = 26 + key;
    }
    getchar(); // consume the newline character
    printf("plaintext: ");
    fgets(mensagem, 100000, stdin);

    //incrypting and printing
    int n = strlen(mensagem);
    printf("cyphertext: ");
    for (int i = 0; i < n; i++){
        if (mensagem[i] == ' '){
        } else if(mensagem[i] > 64 && mensagem[i] < 91){
            mensagem[i] = (((mensagem[i] - 65) + key) % 26) + 65;

        } else if(mensagem[i] > 96 && mensagem[i] < 123){
            mensagem[i] = (((mensagem[i] - 97) + key) % 26) + 97;
        }
        printf("%c", mensagem[i]);
    }

    //end of the function
    return 0;
}