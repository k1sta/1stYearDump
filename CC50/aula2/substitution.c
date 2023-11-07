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

int main (int argc, char *argv[]){
    //data dictionary
    char mensagem[10000];

    //input validation
    if (argc != 2){
        puts("use: ./substitution <key>");
        return 1;
    } else if (strlen(argv[1]) < 26 || strlen(argv[1]) > 26 ){
        puts("the key must contain 26 characters");
        return 2;
    } else {
        for(int i = 0; i < 26; i++){
            for(int j = i + 1; j < 26; j++){
                if(argv[1][i] == argv[1][j] || argv[1][i] == argv[1][j] + 32 || argv[1][i] == argv[1][j] - 32){
                    puts("the key must not contain repeated characters");
                    return 3;
                }
            }
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z'){
                argv[1][i] -= 32;
            }
        }
    }

    //input gathering
    printf("plaintext: ");
    fgets(mensagem, 100000, stdin);

    //incrypting
    for (int i = 0; mensagem[i] != '\0'; i++){
        if(mensagem[i] >= 'A' && mensagem[i] <= 'Z'){
            mensagem[i] = argv[1][mensagem[i] - 'A'];

        } else if(mensagem[i] >= 'a' && mensagem[i] <= 'z'){
            mensagem[i] = argv[1][mensagem[i] - 'a'] + 32;
        }
    }


    //printing
    printf("cyphertext: %s", mensagem);

    //end of the function
    return 0;
}