#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE *fpIn;
    int a, c, sec, min, hour, top = 0, topSum = 1000000000, sum = 0;

    fpIn = fopen("tempos.txt", "r");
    if(fpIn == NULL) return -1;

    fscanf(fpIn, "%d %d\n", &a, &c);

    for(int j = 1; j <= a; j++){
        sum = 0;
        for(int i = 0; i < c; i++){
            if(i == c -1) fscanf(fpIn, "%d %d %d\n", &hour, &min, &sec);
            else fscanf(fpIn, "%d %d %d ", &hour, &min, &sec);
            sum += (hour * 60 * 60) + (min * 60) + sec;
            // printf("%dh %dm %ds || total = %d \n", hour, min, sec, sum);
        }
        // printf("sum %d = %d\n\n", j, sum);
        if (sum < topSum){
            topSum = sum;
            top = j;
        }
    }

    // printf("a=%d\nc=%d\ntop=%d\n", a, c, top);
    printf("%d\n", top);

    fclose(fpIn);


    return 0;
}