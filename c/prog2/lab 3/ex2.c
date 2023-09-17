/*
é necessário um arquivo previamente criado. os inputs sao inseridos na execucao do codigo. 
detalhes da funcionalidade podem ser encontrados em /lab3/questoes. bjs<3
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 1000 //so para ter...

int main (int argc, char **argv){
    //dicionario de dados!
    char cin[MAX];

    //abertura dos arquivos e o teste para saber se ocorreu da forma certa. atencao aos "tipos de abertura" p cada arquivo
    FILE *arquivoEntrada = fopen(argv[1], "r");
    if (arquivoEntrada == NULL){
        printf("nao abriu o arquivo bobao1\n");
        return -1;
    }
    FILE *arquivoSaida = fopen(argv[2], "w+");
    if(arquivoSaida == NULL){
        printf("nao abriu o arquivo bobao2");
        return -1;
    }

    /*a cada linha obtida pelo fgets na iteracao desse while-loop, o for-loop nestado itera pela string cin e usa a funcao
    toupper para transformar todas as letras de caixa baixa em caixa alta. existia outra maneira de fazer isso utilizando
    a tabela ASCII (diminuir 32 caso a letra esteja em caixa baixa ou manter o mesmo se x < 97 || x > 122)*/
    while (!feof(arquivoEntrada)){
        fgets(cin, MAX, arquivoEntrada);
        for(int i = 0; i < MAX; i++){
            cin[i] = toupper(cin[i]);
        }
        fputs(cin, arquivoSaida);
    }

    //por fins de debug, um trecho pra imprimir na tela o resultado com um rewind bolado pra nao perder a estribeiras
    /*
    rewind(arquivoEntrada);
    rewind(arquivoSaida);

    while(!feof(arquivoSaida)){
        fgets(cin, MAX, arquivoSaida);
        fputs(cin, stdout);
    }
    printf("\n");
    */

    //fechar o arquivo pq ngm eh de ferro ne
    fclose(arquivoEntrada);
    fclose(arquivoSaida);
    
    //siga k1sta no github para mais dicas (nao tenho repositorios com portfolio mas terei um dia eu juro)
    return 0;
}