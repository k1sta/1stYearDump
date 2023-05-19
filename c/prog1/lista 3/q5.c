#include <stdio.h>

int ehMultiplo(int r, int s);
void multiplos(int q, int x, int y);

int main(){
    int n, a, b;

    do{
    printf("Digite 3 valores naturais para n, a & b separados por um espaço: \n");
    scanf("%d %d %d", &n, &a, &b);
    if (n > 0 && a > 0 && b > 0) break;
    } while(1);

    multiplos(n, a, b);
    
    return 0;
}

int ehMultiplo(int r, int s){
    if (r % s == 0) return 1;
    else return 0;
}

void multiplos(int q, int x, int y){
    int contador = 1, i = 1;
    printf("0 ");
    while (contador < q){
        if (ehMultiplo(i, x) || ehMultiplo(i, y)){
            printf("%d ", i);
            contador++;
        }
        i++;
    }
}