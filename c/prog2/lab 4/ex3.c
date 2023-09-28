#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    //declaração das variáveis
    FILE *fpIn;
    int a, c, sec, min, hour, top, topSum, sum = 0; 

    //inicialização do arquivo dos inputs + teste
    fpIn = fopen("tempos.txt", "r");
    if(fpIn == NULL) return -1;

    //coleta dos inputs para quantidade de atletas e tentativas
    fscanf(fpIn, "%d %d\n", &a, &c);

    //iteração pelos inputs
    for(int j = 1; j <= a; j++){
        sum = 0;
        for(int i = 0; i < c; i++){
            if(i == c -1) fscanf(fpIn, "%d %d %d\n", &hour, &min, &sec);
            else fscanf(fpIn, "%d %d %d ", &hour, &min, &sec);
            sum += (hour * 60 * 60) + (min * 60) + sec;
            // printf("%dh %dm %ds || total = %d \n", hour, min, sec, sum); //debug
        }
        // printf("sum %d = %d\n\n", j, sum); //debug

        //comparação do resultado do melhor atleta com o atleta analisado atualmente
        if (sum < topSum || j == 1){ 
            topSum = sum;
            top = j;
        }
    }

    // printf("a=%d\nc=%d\ntop=%d\n", a, c, top); //debug

    //print do output
    printf("%d\n", top);

    //fecha
    fclose(fpIn);

    //e acaba
    return 0;
}