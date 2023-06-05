/*
descricao: analise de expressoes logicas
entrada: none
saida: numeros inteiros baseados na execucao das linhas
defesa: deus
*/

#include<stdio.h>

//prototipo / assinatura
int f(int a);

int main() {
    //dicionario de dados
    int a = 2, b = 3, c = 4;

    f(a) || f(b) && f(c); // 2
    f(a) || (f(b) && f(c)); // 2
    (f(a) || f(b)) && f(c); // 2, 4
    (a > b) && f(a) || f(b) && f(c); // 3, 4
    (b > a) && f(a) || f(b) && f(c); // 2 
    ((b > a) && f(a) || f(b)) && f(c); // 2, 4

    //retorno esperado chefe
    return 0;
}

// funcao para printar o parametro!
int f(int a) {
    printf("%d ", a);
    return a;
}