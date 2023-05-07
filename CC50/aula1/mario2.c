#include <stdio.h>

int main(){
    //data dictionary
    int linha, bloco = 1;

    //input gathering
    do {
    printf("Digite o tamanho da escadaria: ");
    scanf("%d", &linha);
    } while (linha < 1 || linha > 8);

    //2 marios piramid!!!!!!!
    while(linha != 0){
        for (int i = linha - 1; i != 0; i--){
            printf(" ");
        }
        for (int j = bloco; j != 0; j--){
            printf("#");
        }
        printf(" ");
        for (int j = bloco; j != 0; j--){
            printf("#");
        }
        printf("\n");
        bloco++;
        linha--;
    }


    return 0;
}