#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p, *q;

    p = (int *) malloc (9 * sizeof(int));
    q = (int *) calloc (10, sizeof(int));

    for(int i = 0; i < 10; i++){
        printf("%d ", *(p + i));
    }

    printf("\n");   

    for(int i = 0; i < 10; i++){
        printf("%d ", *(q + i));
    }

    printf("\n");

    free(p);
    free(q);

    return 0;
}