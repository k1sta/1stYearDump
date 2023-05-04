/*
description: this program calculates the "tabuada" (idk the english word for that) of a number
input: a number
output: the "tabuada" of the number
*/

#include<stdio.h>

int main(void) {
    //data dictionary
    int n, x;

    //input
    printf("Digite o número para calcular a sua tabuada: ");
    scanf("%d", &n);

    //calculus and the output
    x = 1;
    while (x <= 10) {
        printf("%d", x * n);
        x += 1;
    }
    return 0;
}