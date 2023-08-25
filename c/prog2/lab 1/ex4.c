#include <stdio.h>

void inicM(int m[][9]);
void mostraM(int m[][9]);
void incluiElem(int s[][9], int i, int j, int num);

int main(){
    int m[9][9];

    inicM(m);

    mostraM(m);

    incluiElem(m, 1, 2, 10);

    printf("\n%d\n", m[1][2]);
    
    return 0;
}

void inicM(int m[][9]){
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            *(*(m + i) + j) = 0;
        }
    }
}

void mostraM(int m[][9]){
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            printf("%d ", *(*(m + i) + j));
        }
        printf("\n");
    }
}

void incluiElem(int s[][9], int i, int j, int num){
    *(*(s + i)+ j) = num;
}