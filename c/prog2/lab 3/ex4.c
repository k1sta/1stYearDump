/*
é necessário um arquivo previamente criado. os inputs sao inseridos na execucao do codigo. 
detalhes da funcionalidade podem ser encontrados em /lab3/questoes. bjs<3
*/
#include <stdio.h>
#include <string.h>
#define MAX 80 //mesmo comentario do ex anterior

int main (int argc, char **argv){
    //creo que en espanol sea diccionario de datos (do espanhol, dicionario de dados)
    char cin[MAX];

    //abrindo os arquivos e atentando aos tipos de interações que teremos com eles
    FILE *arquivoEntrada = fopen(argv[1], "r");
    if (arquivoEntrada == NULL){
        printf("nao abriu o arquivo bobao1\n");
        return -1;
    }
    FILE *arquivoSaida = fopen(argv[2], "w+");
    if(arquivoSaida == NULL){
        printf("nao abriu o arquivo bobao2");
        return -2;
    }

    //vou explicar cada parte individualmente. o while-loop serve para iterar sobre o stream de dados em texto do arquivo
    while(!feof(arquivoEntrada)){
        //imprime a linha do documento na string cin
        fgets(cin, MAX, arquivoEntrada);

        //pega a quantidade de caracteres da string cin
        int len = strlen(cin);

        //se o ultimo caractere da linha for uma quebra de linha, vamos desconsiderar no loop abaixo
        if (cin[len-1] == '\n') len--;

        /*o for-loop itera até a metade da string, substituindo cin[i] por cin[(len-1) - i], sendo que len-1 é a posição
        do último caractere antes da quebra de linha ou do final da string. */
        if(len != 0)
        for(int i = 0; i <= (len - 1)/2; i++) 
        {
            char temp = cin[(len - 1) - i];
            cin[(len - 1) - i] = cin[i];
            cin[i] = temp;
            //printf("%s\n", cin); // por fins de debug, apenas. foi interessante para testar o comportamento do codigo
        };

        //imprime o resultado da linha invertida na linha correspondente do arquivo de saida
        fputs(cin, arquivoSaida);
    }

    //obrigado por servirem aos meus interesse pessoais, arquivos >:D.
    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    //fim. o comportamento dos fluxos de dados foi um misterio pra entender.
    return 0;
}