/*
Descricao: Esse código é um menu que acessibiliza o acesso das funções de polinomio.c para o usuario, alem de pedir os seus inputs.
Entrada: numero do menu & coeficientes e valores para x
Saída: Resultados das funções de polinomio.c
Defesa: doidao sei la kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk so sei que a funcao "raizesPoli" nao aceita coeficiente para x3
*/
#include <stdio.h>
#include "polinomio.h"
#include <math.h>

int main(){
    // dicionario de dados
    int temp, x;
    polinomio p1, p2, pR;
    solucao resultados;
    float resultadoFloat;

    do{
        //interacao com o usuario e escolha do menu
        puts("Hello! Welcome to the 'You're so dumb that you need to consult a low-quality program to solve your math problems!' Insert the function that you want to use: \n1 = somarPoli \n2 = derivadaPoli\n3 = raizesPoli \n4 = valorPoli \n0 = exit");
        scanf("%d", &temp);
        switch (temp)
        {
        case 1: //somarPoli
            //inputssssss
            puts("Type the firsts polynomial numbers in the following order: ax3 + bx2 + cx1 + d");
            scanf("%f %f %f %f", &p1.c3, &p1.c2, &p1.c1, &p1.c0);
            puts("Now, type the second ones in the same order: ");
            scanf("%f %f %f %f", &p2.c3, &p2.c2, &p2.c1, &p2.c0);
            
            //chama a desgraça
            pR = somarPoli(p1, p2);

            //RESULTADOS. FINALMENTE RESULTADOS.
            printf("The result is: (%.2f)x3 + (%.2f)x2 + (%.2f)x + (%.2f)\n\n", pR.c3, pR.c2, pR.c1, pR.c0);
            break;
        
        case 2://derivadaPoli
            //in(puts)
            puts("Type the polynomial numbers in the following order: ax3 + bx2 + cx1 + d\n ");
            scanf("%f %f %f %f", &p1.c3, &p1.c2, &p1.c1, &p1.c0);
            
            //chama o bagulho doidaoo
            pR = derivadaPoli(p1);

            //printa o resultado.
            printf("The result is: (%.2f)x2 + (%.2f)x + (%.2f)\n\n", pR.c2, pR.c1, pR.c0);
            break;

        case 3://raizesPoli
            //(in)não(puts)
            puts("Type the polynomial numbers in the following order: ax2 + bx1 + c ");
            scanf("%f %f %f", &p1.c2, &p1.c1, &p1.c0);

            //chama que chama que chama chama
            resultados = raizesPoli(p1);

            //imprime o results
            printf("The result is: \nx1 = %.2f\nx2 = %.2f\n\n", resultados.x1, resultados.x2);
            break;

        case 4://valorPoli
            //in(PUTS)
            puts("Type the polynomial numbers in the following order: ax3 + bx2 + cx1 + d ");
            scanf("%f %f %f %f", &p1.c3, &p1.c2, &p1.c1, &p1.c0);
            puts("Type a integer value for x: ");
            scanf("%d", &x);

            //liga para a função cade elaa
            resultadoFloat = valorPoli(p1, x);

            //results
            printf("The result is: %f\n\n", resultadoFloat);
            break;
        
        default://usuario burro ou mal agradecido
            break;
        }

        //pede pra sair 01.
        puts("Return to the menu? (y = 1 / n = 0)");
        scanf("%d", &temp);
    } while (temp != 0);
}