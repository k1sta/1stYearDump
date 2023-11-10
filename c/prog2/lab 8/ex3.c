#include <stdio.h>
#include <stdlib.h>

void buscaMenorMaiorBin(int arr[], int tam, int el,
int *menor, int *maior);

int main(void)
{
    int *v;
    int n, tam, maior, menor;

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

    buscaMenorMaiorBin(v, tam, n, &menor, &maior);

    if(menor == -1 && maior == -1){
        printf("Elemento não existe no vetor\n");
        return -1;
    }

    printf("Elementos maiores que [%d]: %d\n", n, maior);
    printf("Elementos menores que [%d]: %d\n", n, menor);

    return 0;
}

void buscaMenorMaiorBin(int arr[], int tam, int el,
int *menor, int *maior)
{
    int fim = tam - 1;
    int ini = 0;
    *menor = 0; *maior = 0;
    while (ini <= fim)
    {
        int meio = (fim + ini) / 2;
        if (arr[meio] < el){
            *menor += meio - ini +1;
            ini = meio + 1;
        }
        else
        {
            if (arr[meio] > el){
                *maior = fim - meio + 1;
                fim = meio - 1;
            }
            else{
                *maior = fim - meio; 
                *menor = meio - ini;
                return;
            }
        }
    }
}