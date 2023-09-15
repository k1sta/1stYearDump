#include <stdio.h>
#include <stdlib.h>

int main (void){
    int m, n, l, c;
    
    do{
        printf("Insira o valor de L, C, M, N, respectivamente: \n");
        scanf("%d %d %d %d", &l, &c, &m, &n);
        if (l % m == 0 && c % n == 0 && l > 0 && c > 0 && n > 0 && m > 0) break;    
    } while(1);

    int **grade = (int **) malloc (l * sizeof(int *));
    if (!grade){
        printf("alocacao deu merda");
        return -1;
    }

    for(int i = 0; i < l; i++){
        *(grade + i) = (int *) malloc (c * sizeof(int));
        if (!(*(grade + i))){
            printf("alocacao deu merda");
            return -1;
        }
    }

    for(int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            printf("plantacao[%d][%d]: ", i, j);
            scanf("%d", *(grade + i) + j);
        }
    }

    int max = 0;

    for (int x = 0; x < l/m; x++){
        for (int y = 0; y < c/n; y++){
            int soma = 0;
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    soma += *(*(grade + (i + x * m)) + (j + y * n));
                }
            }
            max = (soma > max) ? soma : max;
        }
    }
    
    printf("\n%d\n", max);

    return 0;
}