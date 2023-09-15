#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

    while (!feof(arquivoEntrada)){
        fgets(cin, MAX, arquivoEntrada);
        for(int i = 0; i < MAX; i++){
            cin[i] = toupper(cin[i]);
        }
        fputs(cin, arquivoSaida);
    }

    rewind(arquivoEntrada);
    rewind(arquivoSaida);

    while(!feof(arquivoSaida)){
        fgets(cin, MAX, arquivoSaida);
        fputs(cin, stdout);
    }

    printf("\n");

    fclose(arquivoEntrada);
    fclose(arquivoSaida);
    
    return 0;
}