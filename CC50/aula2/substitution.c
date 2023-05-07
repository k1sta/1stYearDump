/*

isso eh uma cifra de substituicao

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
    char key[26];

    //input gathering
    printf("key: ");
    scanf("%s", key);
    getchar(); // consume the newline character
    printf("plaintext: ");
    fgets(mensagem, 100000, stdin);

    //incrypting and printing
    int n = strlen(mensagem);
    printf("cyphertext: ");
    for (int i = 0; i < n; i++){
        if (mensagem[i] == ' '){
        } else if(mensagem[i] > 64 && mensagem[i] < 91){
            mensagem[i] = key[mensagem[i] - 65];

        } else if(mensagem[i] > 96 && mensagem[i] < 123){
            mensagem[i] = key[mensagem[i] - 97] + 32;
        }
        printf("%c", mensagem[i]);
    }

    //end of the function
    return 0;
}