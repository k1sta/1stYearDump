/*
os inputs sao pedidos em tempo de execucao. detalhes da funcionalidade podem ser encontrados em /lab3/questoes. bjs<3
*/
#include <stdio.h>
#include <stdlib.h>

int main (void){
    //dicionario de dados
    int m, n, l, c;
    
    //coleta dos inputs m, n, l & c
    do{
        printf("Insira o valor de L, C, M, N, respectivamente: \n");
        scanf("%d %d %d %d", &l, &c, &m, &n);
        if (l % m == 0 && c % n == 0 && l > 0 && c > 0 && n > 0 && m > 0) break;    
    } while(1);

    //declaração do vetor de ponteiros de ponteiros
    int **grade = (int **) malloc (l * sizeof(int *));
    if (!grade){
        printf("alocacao deu problema amigo");
        return -1;
    }

    //declaração dos ponteiros para cada ponteiro de ponteiros
    for(int i = 0; i < l; i++){
        *(grade + i) = (int *) malloc (c * sizeof(int));
        if (!(*(grade + i))){
            printf("alocacao deu problema amigo");
            return -1;
        }
    }

    //por fins de debug, esse trecho coleta os valores da matriz com uma linha indicando a celula que esta sendo inputada
    for(int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            printf("plantacao[%d][%d]: ", i, j);
            scanf("%d", *(grade + i) + j);
        }
    }

    //para ficar mais aceitavel para os inputs de exemplo, esse trecho é mais recomendado (comente o outro para usar esse)
    /*for(int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            scanf("%d", *(grade + i) + j);
        }
    }*/

    //variavel de controle para o maximo
    int max = 0;

    /* a ideia aqui eh DAC (divide and conquer). criamos uma matriz X x Y composta por sub-matrizes M x N que, quando expandida,
    nos da uma matriz L x C. entretanto, o que garante a leitura integral dos dados da matriz L x C inicial, sao os dois
    nests externos, que determinam uma quantidade X e Y para localizar a leitura de uma sub-matriz M x N na matriz inicial feita
    pelo for-loop da linha 58. a consequencia disso eh a linha 60, que soma os valores de cada lote baseado na logica
    explicada acima. */
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
    
    //output do que foi pedido na questao
    printf("\n%d\n", max);

    //eh isso beijos nos vemos na proxima
    return 0;
}