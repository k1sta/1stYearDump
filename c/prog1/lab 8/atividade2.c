#include <stdio.h>

int main(){
    int a[500], b[500], c[1000], biggerSize, aSize, bSize;

    do{
    puts("Insert the quantity of the a and b vectors: ");
    scanf("%d %d", &aSize, &bSize);
    if(aSize > 0 && bSize > 0 && aSize < 500 && bSize < 500) break;
    } while(1);

    printf("Insert %d ordened elements for a:\n", aSize);
    for(int i = 0; i < aSize; i++){
        scanf("%d", &a[i]);
    }

    printf("Insert %d ordened elements for b:\n", bSize);
    for(int i = 0; i < bSize; i++){
        scanf("%d", &b[i]);
    }

    int j = 0, k = 0;
    for(int i = 0; i < aSize + bSize; i++){
        if (j == aSize) a[j] = b[k] + 1;
        if (k == bSize) b[k] = a[j] + 1;

        if (a[j] < b[k]) {
            c[i] = a[j];
            printf("c[%d] recebeu a[%d] = %d\n", i, j, a[j]);
            j++;

        } else {
            c[i] = b[k];
            printf("c[%d] recebeu b[%d] = %d\n", i, k, b[k]);
            k++;
        }
    }

    for(int i = 0; i < aSize + bSize; i++){

        printf("%d ", c[i]);

    }
    
    return 0;


}