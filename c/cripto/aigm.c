#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, d;
    int quociente, resto, divisor;

    printf("Digite o dividendo e o divisor seguidos por um espaco:\n");
    scanf("%d %d", &x, &d);

    //passo 1
    quociente = 0;
    resto = abs(x);
    divisor = abs(d);

    //passo 2
    if (x > 0 && d > 0){
        while (resto >= divisor){
            resto = resto - divisor;
            quociente++;
        }
    } else if (x > 0 && d < 0) {
        while (resto >= divisor){
            resto = resto - divisor;
            quociente--;
        }
    } else if(x < 0 && d > 0){
        while (resto > 0){
            resto = resto - divisor;
            quociente--;
        }
        resto = resto * -1;
    } else{
        while (resto > 0){
            resto = resto - divisor;
            quociente++;
        }
        resto = resto * -1;
    }

    //passo 3
    printf("%d %d\n", quociente, resto);



    return 0;
}