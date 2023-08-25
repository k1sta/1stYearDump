/*
Descricao: dados tres numeros inteiros, retorn o maior
Entrada: os tres numeros inteiros
Saida: o maior numero encontrado
*/

#include <stdio.h>

int main() {
    //dicionario de dados
    int a, b, c;
    int maior;

    //obtem os tres numeros
    printf("Digite os tres numeros separados por espaco: \n");
    scanf("%d %d %d", &a, &b, &c);

    //encontra o maior numero
    if (a > b) {
        maior = a;
    } else {
        maior = b;
    }
    if (c > maior) {
        maior = c;
    }
    //exibe o resultado
    printf("O maior numero eh: %d \n", maior);

    return 0;
}