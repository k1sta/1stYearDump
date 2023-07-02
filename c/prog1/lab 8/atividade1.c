#include <stdio.h>

//prototype
int internProdVetCalc(int d, int v[], int w[]);

int main(){
    //data dictionary
    int dimensions;
    float v[10], w[10], prod;

    //vectors size gathering
    do{
    puts("Insert the quantity of dimensions: ");
    scanf("%d", &dimensions);
    if(dimensions > 0 && dimensions <= 10) break;
    } while(1);

    //elements gathering
    printf("Insert %d dimensions for v:\n", dimensions);
    for(int i = 0; i < dimensions; i++){
        scanf("%f", &v[i]);
    }
    printf("Insert %d dimensions for w:\n", dimensions);
    for(int i = 0; i < dimensions; i++){
        scanf("%f", &w[i]);
    }

    //func call
    prod = internProdVetCalc(dimensions, v, w);
    
    //print the f* result
    printf("Your result is: %f", prod);
    
    return 0;
}

//this holy function calculates the intern product of vectors
float internProdVetCalc(int d, float v[], float w[]){

    float product = 0;

    for(int i = 0; i < d; i++){
        product += v[i] * w[i];
    }

    return product;
    
}
