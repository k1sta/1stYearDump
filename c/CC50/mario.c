#include <stdio.h>

int main(){
    int linha, bloco = 1;

    do {
    printf("Digite o tamanho da escadaria: ");
    scanf("%d", &linha);
    } while (linha < 1 || linha > 8);

    while(linha != 0){
        for (int i = linha - 1; i != 0; i--){
            printf(" ");
        }
        for (int j = bloco; j != 0; j--){
            printf("#");
        }
        printf("\n");
        bloco++;
        linha--;
    }


    return 0;
}