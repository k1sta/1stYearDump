/*
Descricao: esse codigo calcula a raiz quadrada de um numero baseado no metodo de newton e compara com o resultado da funcao do math.h
Entrada: um número racional
Saida: o número inputado + a raiz dele de acordo com a funcao sqrt() + a raiz dele de acordo com o metodo de newton
defesa: nao aceita numero negativo e retorna 0 caso o input seja 0 por causa da imprecisao
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//prototipo
double d_abs(double x);


int main(){
    //dicionario de dados
    double n, x_novo, x_antigo = 10; //chute

    //pegando o numero
    do{
    printf("Digite o número: ");
    scanf("%lf", &n);
    if (n >= 0) break;
    } while(1);

    //calculando
    if (n != 0) while(1){
        x_novo = x_antigo - ((x_antigo * x_antigo) - n)/(2 * x_antigo);
        if (d_abs(x_novo - x_antigo) < 0.000001) break;
        x_antigo = x_novo;
    };
    
    //impressao
    printf("Numero lido: %lf \nRaiz da math.h: %lf \nRaiz de Newton: %lf\n", n, sqrt(n), x_novo);

    //retorno esperado
    return 0;
}


//essa funcao faz o que o abs nao faz (aceita double)
double d_abs(double x){
    if (x < 0) return x * (-1);
    return x;
}