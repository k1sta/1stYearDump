#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//prototipo
double dif_abs(double x, double y);


int main(){
    //dicionario de dados
    double n, x_novo, x_antigo = 10; //chute

    //pegando o numero
    printf("Digite o número: ");
    scanf("%lf", &n);

    //calculando
    while(1){
        x_novo = x_antigo - ((x_antigo * x_antigo) - n)/(2 * x_antigo);
        if (dif_abs(x_novo, x_antigo) < 0.000001) break;
        x_antigo = x_novo;
    }
    
    //impressao
    printf("Numero lido: %lf \nRaiz da math.h: %lf \nRaiz de Newton: %lf\n", n, sqrt(n), x_novo);

    //retorno esperado
    return 0;
}


//essa funcao faz o que o abs nao faz (aceita double)
double dif_abs(double x, double y){
    if (x - y < 0) return (x - y) * -1;
    return x - y;
}