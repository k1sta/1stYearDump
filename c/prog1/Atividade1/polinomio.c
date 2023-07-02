/*
descricao: funcoes. muitas funcoes. a header explica elas.
entrada: especificado nos parametros
saida: retornos das funcoees.
defesa: Jesus Cristo
*/

#include <stdio.h>
#include "polinomio.h"
#include <math.h>

polinomio somarPoli(polinomio p1, polinomio p2){ //soma que soma que soma os coeficientes
    //dados
    polinomio poliResultante;

    //soma dos coeficientes
    poliResultante.c3 = p1.c3 + p2.c3;
    poliResultante.c2 = p1.c2 + p2.c2;
    poliResultante.c1 = p1.c1 + p2.c1;
    poliResultante.c0 = p1.c0 + p2.c0;

    //retorna ®
    return poliResultante;
}

polinomio derivadaPoli(polinomio p){ //Ex.: derivada(x3 + 5x2 + 4x - 3) = 3x2 + 10x + 4
    //dados 
    polinomio poliResultante;

    //irmao derivar e muito simples
    poliResultante.c3 = 0;
    poliResultante.c2 = 3 * p.c3;
    poliResultante.c1 = 2 * p.c2;
    poliResultante.c0 = p.c1;
    
    //(re)torna
    return poliResultante;
}

solucao raizesPoli(polinomio p){ //BHASKARA IN A NUTSHELL DAMNNNNNNNN
    //dados
    solucao r;
    float delta;

    //calculo do delta
    delta = sqrt((p.c1 * p.c1) - (4 * p.c2 * p.c0));

    //calcula as raizessssssssssssssss
    r.x1 = ((-1 * p.c1) + delta)/(2 * p.c2);
    r.x2 = ((-1 * p.c1) - delta)/(2 * p.c2);

    //retorna as raizesssssssssssss
    return r;
}

float valorPoli(polinomio p, int x){ //Ex.: para x = 1, temos que x3 + 5x2 + 4x - 3 = 7
    // dados (ler como a 19ª sinfonia de bethoven) tananana
    float resultado;

    //calcula resultado do polinomio dado x esquisito
    resultado = p.c3 * x * x * x + p.c2 * x * x + p.c1 * x + p.c0;

    //results
    return resultado;
}