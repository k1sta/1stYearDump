#include <stdio.h>
#include <string.h>
#define MAX 1000

int main (int argc, char **argv){
    char cin[MAX];

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

    while(!feof(arquivoEntrada)){
        fgets(cin, MAX, arquivoEntrada);
    }
    
    return 0;
}