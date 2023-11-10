#include <stdio.h>
#include <stdlib.h>

int buscaBin(int arr[], int tam, int el);

int main(void)
{
    int *v;
    int n, tam;

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

    if (buscaBin(v, tam, n) == -1){
        printf("Elemento não existe no vetor.\n");
        return -1;
    }

    return 0;
}

int buscaBin(int arr[], int tam, int el)
{
    int fim = tam - 1;
    int ini = 0;
    int i = 0;
    while (ini <= fim)
    {
        i++;
        int meio = (fim + ini) / 2;
        if (arr[meio] < el){
            printf("%da. iteração: %d\n", i, meio - ini +1);
            ini = meio + 1;
        }
        else
        {
            if (arr[meio] > el){
                printf("%da. iteração: %d\n", i, fim - meio + 1);
                fim = meio - 1;
            }
            else{
                printf("%da. iteração: %d\n", i, fim - meio + meio - ini);
                return meio;
            }
        }
        printf("%da. iteração: 1\n", i);
    }
    return -1;
}