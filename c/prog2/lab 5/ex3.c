#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nome[100];
    double nota[3];
    double media;
} Taluno;

int main(){ 
    FILE *fp;
    Taluno alnTemp, *alunos;
    int n = 0;

    //abertura do arquivo
    fp = fopen("alunos.dat", "wb+");
    if (fp == NULL){ printf("erro arq"); return -1;}

    while(!feof(fp)){
        if (fread(&alnTemp, sizeof(Taluno), 1, fp) == NULL) break;
        printf("%s, %lf, %lf, %lf, %lf\n", alnTemp.nome,
            alnTemp.nota[0],alnTemp.nota[1],alnTemp.nota[2],
            alnTemp.media);
    }

    rewind(fp);

    alunos = malloc(n * sizeof(Taluno));
    fread(&alunos, sizeof(Taluno), n, fp);
    
    return 0;
}