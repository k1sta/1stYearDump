#include <stdio.h>
#include <stdlib.h>

void buscaSeqOrdRep(int arr[], int tam, int el, int *pos, int *quant);

int main(void)
{
    int* v;
    int n, qnt, pos, tam;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &tam);

    v = (int *) malloc (tam * sizeof(int));
    if (!v) return -1;

    printf("Digite os elementos do vetor: ");
    for(int i = 0; i < tam; i++)
        scanf("%d", &v[i]);

    printf("Digite o elemento procurado: ");
    scanf("%d", &n);

    buscaSeqOrdRep(v, tam, n, &pos, &qnt);

    printf("Posição da primeira ocorrência: %d\n", pos);
    printf("Quantidade de ocorrências: %d\n", qnt);

    return 0;
}

void buscaSeqOrdRep(int arr[], int tam, int el, int *pos, int *quant)
{
    for (int i = 0; i < tam; i++)
    {
        if (arr[i] == el)
        {
            *pos = i;
            *quant = 1;
            break;
        }
        else
        {
            *pos = -1;
            *quant = 0;
        }
    }

    for (int i = (*pos) + 1; i < tam; i++){
        printf("%d", el);
        if (arr[i] == el)
            *quant += 1;
    }
    return;
}