#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void){ 
    FILE *arqSaida;
    int numAlunos, i = 1;
    char arqName[50], temp[100];
    float p1, p2, t;

    
    printf("Insina o número de alunos: ");
    scanf("%d", &numAlunos);
    getchar();
    printf("Insira o nome do arquivo: ");
    scanf("%[^\n]", arqName);
    getchar();
    
    arqSaida = fopen(arqName, "w+");
    if(arqSaida == NULL) return -1;

    while(numAlunos--){
        printf("\n_Aluno %d_\nNome: ", i++);
        scanf("%[^\n]", temp);
        getchar();
        printf("P1: ");
        scanf("%f", &p1);
        printf("P2: ");
        scanf("%f", &p2);
        printf("T: ");
        scanf("%f", &t);
        fprintf(arqSaida, "%s %.1f %.1f %.1f\n", temp, p1, p2, t);
        getchar();
    }

    fclose(arqSaida);
    

    return 0;
}

/*
pseudo:

1- pede numero de alunos
1.1- pede nome do arq
2- cria um loop com numAlunos--
3- dentro do loop, pede nome de aluno, nota etc e inputa formatado no arquivo
4- cabop
*/