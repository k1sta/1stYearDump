/*
Descricao: esse programa resolve equacao de primeiro grau ax+b=0
Entrada: coeficientes reais a e b da equacao ax + b = 0
Saida: resultado da equacao (valor de x)
*/

#include <stdio.h>

int main() {
    //dicionario de dados
    float coef_linear, coef_angular;
    float x;
    
    //obtem os coeficientes e verifica se "a" eh valido
    printf("Digite o coeficiente angular: \n");
    scanf("%f", &coef_angular);
    if (coef_angular == 0) {
        printf("Valor de a não é válido.");
        return 1;
    }
    printf("Digite o coeficiente linear: \n");
    scanf("%f", &coef_linear);

    //calcula o valor de x
    x = -coef_linear / coef_angular;

    //imprime o valor de x
    printf("O valor de x é %f \n", x);

    return 0;
}