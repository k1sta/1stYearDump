#include <stdio.h>
#include <math.h>

int main(){
    int *vetor, nVetor, nPrimos;

    scanf("%d", &n);

    vetor = (int *) calloc (n, sizeof(int));

    for(int i = 1; i <= n; i++){
        vetor[i-1] = i;
    }

    
    
    nPrimos = n / log(n);

    
    
    return 0;
}