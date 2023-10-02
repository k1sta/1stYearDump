#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct dada no exercicio
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

    //loop while com a leitura dos inputs do teclado
    while(1){
        //condiçao if para parada caso o usuario insira so '\n', pois o scanf nao atualiza a variavel nesse caso
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

        //media
        alunoTemp.media = (alunoTemp.nota[0] +alunoTemp.nota[1] +alunoTemp.nota[2])/3;

        //debug
        /*printf("%s, %lf, %lf, %lf, %lf\n", alunoTemp.nome, alunoTemp.nota[0],alunoTemp.nota[1],alunoTemp.nota[2], alunoTemp.media);*/

        //escrita
        fwrite(&alunoTemp, sizeof(Taluno), 1, fp);
    }

    //leitura e impressao do que foi escrito no arquivo
    rewind(fp);
    while(fread(&alunoTemp, sizeof(Taluno), 1, fp) != 0){
        printf("%s, %lf, %lf, %lf, %lf\n", alunoTemp.nome, alunoTemp.nota[0],alunoTemp.nota[1],alunoTemp.nota[2], alunoTemp.media);
    }

    //ggwp
    fclose(fp);
    return 0;
}