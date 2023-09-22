/*
pseudo:

1- inicializar os arquivos
2- leitura, calculo da media
3- escrita, nome + media
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    FILE *outFile, *inFile;
    float p1, p2, t, media;
    char name[100];

    inFile = fopen(argv[1], "r");
    if (inFile == NULL) return -1;

    outFile = fopen(argv[2], "w+");
    if (outFile == NULL) return -2;

    while(!feof(inFile)){
        fscanf(inFile, "%[A-Z a-z] %f %f %f\n", name, &p1, &p2, &t);
        media = (((p1+p2)/2)*0.8)+(t*0.2);
        fprintf(outFile, "%s %.2f\n", name, media);
    }

    fclose(outFile);
    fclose(inFile);

}