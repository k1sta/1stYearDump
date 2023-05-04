#include <stdio.h>

int main (){
    int troco, contador = 0;
    float troca_devida;
    do {
    printf("Troca devida: ");
    scanf("%f", &troca_devida);
    } while (troca_devida <= 0);

    troco = troca_devida * 100;

    while(troco != 0){
        if (troco >= 25){
            contador++;
            troco -= 25;
        } else if (troco >= 10){
            contador++;
            troco -= 10;
        } else if (troco >= 5){
            contador++;
            troco -= 5;
        } else {
            contador++;
            troco -= 1;
        }
    }
    printf("%d\n", contador);
    return 0;
}