#include <stdio.h>

int main (){
    //data dictionary
    int troco, contador = 0;
    float troca_devida;

    //input gathering
    do {
    printf("Troca devida: ");
    scanf("%f", &troca_devida);
    } while (troca_devida <= 0);

    //idk, cc50 asked us to do that istead of using float... that was nosense
    troco = troca_devida * 100;

    //that, in portuguese, is "Algoritmo Guloso"!
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

    //THE output.
    printf("%d\n", contador);

    return 0;
}