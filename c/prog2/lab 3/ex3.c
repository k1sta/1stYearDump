/*
é necessário um arquivo previamente criado. os inputs sao inseridos na execucao do codigo. 
detalhes da funcionalidade podem ser encontrados em /lab3/questoes. bjs<3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80 //entao, fiquei em duvida se os 80 caracteres eram para essa constante. deduzi que sim, mas posso estar enganado.

int main (int argc, char **argv){
    //data dictionary (do ingles, aurelio de dados :fogo:)
    char cin[MAX];
    int counter = 0;

    //abrindo o arquivo e testando para ver se deu certo
    FILE *arquivoEntrada = fopen(argv[2], "r");
    if (arquivoEntrada == NULL){
        printf("erro de abertura de arquivo");
        return -1;
    }

    /* aqui, a variavel counter determina a linha em que o loop está no momento do teste da funcao strstr. se a linha a needle
    estiver em cin, ele imprime o valor de counter (linha do documento) e a linha inteira */
    while (!feof(arquivoEntrada)){
        fgets(cin, MAX, arquivoEntrada);
        counter++;
        if(strstr(cin, argv[1]) != NULL){
            printf("%d %s", counter, cin);
        };
    }

    puts("");
    fclose(arquivoEntrada);

    return 0;
}