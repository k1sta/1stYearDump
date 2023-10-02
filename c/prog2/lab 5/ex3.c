#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//tipo do exercicio
typedef struct
{
    char nome[100];
    double nota[3];
    double media;
} Taluno;

int main(){ 
    //dicionario de dados
    FILE *fp;
    Taluno alnTemp, *alunos;
    int numAlunos = 0, numAlt= 0;

    //abertura do arquivo
    fp = fopen("alunos.dat", "rb+");
    if (fp == NULL){ printf("erro arq"); return -1;}

    //essa parte le o arquivo, altera a variavel que esta recebendo e escreve ela por cima da parte lida
    puts("Arquivo antes da alteracao:");
    while(fread(&alnTemp, sizeof(Taluno), 1, fp) != 0){
        //printa as informações do aluno
        printf("%s, %lf, %lf, %lf, %lf\n", alnTemp.nome, alnTemp.nota[0], alnTemp.nota[1], alnTemp.nota[2], alnTemp.media);

        //calcula a media ponderada dele, se ela foi atualizada e atribui ela
        double mediaPond = alnTemp.nota[0] * 0.25 + alnTemp.nota[1] * 0.35 + 0.4 * alnTemp.nota[2];
        if(mediaPond != alnTemp.media) numAlt++;
        alnTemp.media = mediaPond;

        //move o ponteiro pro inicio das informacoes do aluno em questao
        fseek(fp, (sizeof(Taluno) * numAlunos), SEEK_SET);

        //escreve por cima com a media ponderada
        fwrite(&alnTemp, sizeof(Taluno), 1, fp);

        //contador do numero de alunos
        numAlunos++;
    }
    puts(" ");
    
    //leitura do arquivo alterado
    fseek(fp, 0, SEEK_SET);
    puts("Arquivo apos a alteracao:");
    while(fread(&alnTemp, sizeof(Taluno), 1, fp) != 0){
        printf("%s, %lf, %lf, %lf, %lf\n", alnTemp.nome, alnTemp.nota[0],alnTemp.nota[1],alnTemp.nota[2], alnTemp.media);
    }
    puts(" "); 

    //impressao do num de alunos + porcentagem de alterações
    printf("Numero de alunos: %d\nAlunos que tiveram a nota alterada: %.2lf%%\n", numAlunos,(((float)numAlt/numAlunos)*100.0));

    //fechar o arquivo
    fclose(fp);
    
    //ggwp
    return 0;
}