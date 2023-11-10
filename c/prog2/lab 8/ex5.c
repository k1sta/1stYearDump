#include <stdio.h>
#include <stdlib.h>

int buscaR(int v[], int n, int procurado, int esq, int dir)
{
    int meio = (esq + dir) / 2;
    if (esq <= dir)
    {
        if (v[meio] == procurado)
            return meio;
        else if (v[meio] > procurado)
            return buscaR(v, n, procurado, esq, meio -1);
        else if (v[meio] < procurado)
            return buscaR(v, n, procurado, meio + 1, dir);
    }
    return -1;
}

int main(void)
{
    int *v;
    int n, tam, pos;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &tam);

    v = (int *)malloc(tam * sizeof(int));
    if (!v)
        return -1;

    printf("Digite os elementos do vetor: ");
    for (int i = 0; i < tam; i++)
        scanf("%d", &v[i]);

    printf("Digite o elemento procurado: ");
    scanf("%d", &n);

    pos = buscaR(v,tam, n, 0, tam - 1);

    if(pos == -1){
        printf("Elemento não existe no vetor\n");
        return -1;
    }

    printf("Elemento na posição %d\n", pos);
    return 0;
}