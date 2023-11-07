#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, **matriz, *vetor, auxVetor = 0;

    scanf("%d %d", &i, &j);

    vetor = (int *) calloc (i*j, sizeof(int));
    if(vetor == NULL){
        printf("erro de alocacao 1\n");
        return 1;
    }

    matriz = (int **) calloc (i, sizeof(int *));
    if(matriz == NULL){
        printf("erro de alocacao 2\n");
        return 1;
    }
    for(int k = 0; k < i; k++){
        *(matriz + k) = (int *) calloc (j, sizeof(int));
        if(matriz[k] == NULL){
            printf("erro de alocacao 3\n");
            return 1;
        }
    }  

    for(int k = 0; k < i; k++){
        for (int l = 0; l < j; l++){
            scanf("%d", &matriz[k][l]);
            if (matriz[k][l] % 2 == 0) vetor[auxVetor++] = matriz[k][l];
        }
    }

    printf("matriz:\n");
    for(int k = 0; k < i; k++){
        for (int l = 0; l < j; l++){
            printf("%d ", matriz[k][l]);
        }
        printf("\n");
    }

    printf("vetor:\n");
    for (int k = 0; k < auxVetor; k++){
        printf("%d ", vetor[k]);
    }
    printf("\n");

    return 0;
}