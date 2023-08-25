#include <stdio.h>

float max(float v[], int n);

int main(){
    float maior, v[] = {-1, 2, -3, -4};
    int n = 3;

    printf("%f", max(v, n));

    return 0;
}

float max(float v[], int n){
    float max = v[0];
    while(n--){
        if (v[n] > max) max = v[n];
    }

    return max;
}