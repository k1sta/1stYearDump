#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    //declaração da variavel
    FILE *fp;
    char name[80];
    int n, *idk, *final;    

    //input do arquivo
    printf("File name: ");
    scanf("%[^\n]", name);
    getchar();  

    //abertura do arquivo
    fp = fopen(name, "wb+");
    if (fp == NULL){ printf("erro arq"); return -1;}

    //input do N
    do{
    printf("N: ");
    scanf("%d", &n);
    } while (n < 1);

    //alocação do vetor + escrita
    idk = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        *(idk + i) = n - i;
    }
    fwrite(idk, sizeof(int), n, fp);

    rewind(fp);
    final = malloc(n * sizeof(int));

    fread(final, sizeof(int), n, fp);

    for(int i = 0; i < n; i++) printf("%d ", *(final + i));
    puts("");

    fclose(fp);

    return 0;
}