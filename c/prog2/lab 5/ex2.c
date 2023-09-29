#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[100];
    double nota[3];
    double media;
} Taluno;


int main(void){
    //DATA DICTIONARY
    FILE *fp;
    Taluno alunoTemp;
    char comp[100];
    //abertura do arquivo
    fp = fopen("alunos.dat", "wb+");
    if (fp == NULL){ printf("erro arq"); return -1;}

    while(1){
        printf("Nome: ");
        scanf("%[^\n]", alunoTemp.nome);
        if(strcmp(comp, alunoTemp.nome) == 0) break;
        strcpy(comp, alunoTemp.nome);

        printf("Nota 1: ");
        scanf("%lf", &alunoTemp.nota[0]);
        printf("Nota 2: ");
        scanf("%lf", &alunoTemp.nota[1]);
        printf("Nota 3: ");
        scanf("%lf", &alunoTemp.nota[2]);
        getchar();

        alunoTemp.media = (alunoTemp.nota[0] +alunoTemp.nota[1] +alunoTemp.nota[2])/3;

        /*printf("%s, %lf, %lf, %lf, %lf\n", alunoTemp.nome,
            alunoTemp.nota[0],alunoTemp.nota[1],alunoTemp.nota[2],
            alunoTemp.media);*/


        fwrite(&alunoTemp, sizeof(Taluno), 1, fp);
    }

    rewind(fp);

    while(!feof(fp)){
        if (fread(&alunoTemp, sizeof(Taluno), 1, fp) == NULL) break;
        printf("%s, %lf, %lf, %lf, %lf\n", alunoTemp.nome,
            alunoTemp.nota[0],alunoTemp.nota[1],alunoTemp.nota[2],
            alunoTemp.media);
    }


    fclose(fp);
    return 0;
}