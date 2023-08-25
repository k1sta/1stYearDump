#include <stdio.h>

float aumentoSalarial(float *salario, float aumento);

int main (){
    float salario, aumento;

    printf("type the wage and the increase percentage value:\n");
    scanf("%f %f", &salario, &aumento);

    aumentoSalarial(&salario, aumento);

    printf("%.2f result\n", salario);

    return 0;
}

float aumentoSalarial(float *salario, float aumento){
    *salario = (*salario) * (aumento/100 + 1);

    return 0;
}