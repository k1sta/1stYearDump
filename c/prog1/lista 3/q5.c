/*
descricao: analise de expressoes logicas
entrada: none
saida: uns bgl loco
defesa: deus
*/
#include <stdio.h>

//prototipos
int ehMultiplo(int r, int s);
void multiplos(int q, int x, int y);

int main(){
    //dicionario de dados
    int n, a, b;

    //defesa & coleta do input
    do{
    printf("Digite 3 valores naturais para n, a & b separados por um espaço: \n");
    scanf("%d %d %d", &n, &a, &b);
    if (n > 0 && a > 0 && b > 0) break;
    } while(1);

    //chamada da funcao
    multiplos(n, a, b);
    
    //retorno esperado chefe
    return 0;
}

//checa se o primeiro parametro e divisivel pelo segundo, mas so trabalha com numeros inteiros
int ehMultiplo(int r, int s){
    if (r % s == 0) return 1;
    else return 0;
}

//essa funcao imprime os q primeiros multiplos de x ou y
void multiplos(int q, int x, int y){
    //dicionario de dados
    int contador = 1, i = 1;

    //caso especial (0 eh multiplo de tudo)
    printf("0 ");

    //loop para imprimir os multiplos
    while (contador < q){
        if (ehMultiplo(i, x) || ehMultiplo(i, y)){
            printf("%d ", i);
            contador++;
        }
        i++;
    }
}