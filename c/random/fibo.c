/*forgive my coments bad organization, it was a
 fast code for a explanation to my friend xD*/

#include <stdio.h> //biblioteca pra usar as funções

int fib(int n); //isso aqui é só pra dizer que essa função existe. não faz nada, basicamente

int main(int argc, char **argv){ //esse argc e argv é uma maneira de fazer o input ser inserido na execução do arquivo. basicamente, quando ver "argv[n]", pensa que é um input
    int n = atoi(argv[1]);//variavel inteira

    printf("%d\n", fib(n));//impressão do resultado e chamada de função (sim eu chamei a função dentro da função de imprimir no terminal)

    return 0;
}

int fib(int n){// bora la. essa linha significa que é uma função que retorna um inteiro "int" chamada de "fib" que aceita um inteiro n "int n" como parâmetro
    if(n == 1){ //fib(1)
        return 1; //é igual a 1
    } else if(n == 0){//fib(0)
        return 0;//é igual a 0
    } else { //caso contrário
        return fib(n-1) + fib(n - 2);//é isso aqui
    }
}