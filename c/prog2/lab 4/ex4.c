#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv){
    //declaração das variáveis
    FILE *fpIn;
    char word[50];
    int sum = 0;

    //inicializando o arquivo e atribuição de um ponteiro + teste
    fpIn = fopen (argv[1], "r");
    if (fpIn == NULL) return -1;

    /*aqui, presumi que o arquivo de input
    seria um arquivo formatado em palavras,
    basicamente um texto em lingua escrita mesmo.
    caso não fosse isso, eu poderia utilizar um
    fgets para capturar uma linha, procurar nela e,
    caso tivesse proxima, pegar a mesma linha a partir
    de -(numdecaracteresdapalavra + 1) bytes para
    garantir que a palavra não seria cortada pelo 
    limite do fgets */
    while(!feof(fpIn)){
        fscanf(fpIn, "%s ", word);
        if (strcmp(word, argv[2]) == 0) sum++;
    }
    
    //printando o output
    printf("%d\n", sum);
    
    //fechando o arquivo
    fclose(fpIn);

    //returnnnnnnnn cabooooooo
    return 0;
}