#include <stdio.h>

void arvore(int linhas, int invertida);

int main(){
    //dicionario de dados
    int linhas;
    char temp;

    //defesa do codigo + input do tamanho
    printf("Você deseja uma pirâmide invertida (s/n)? ");
    scanf("%c", &temp);

    do{
    printf("Digite o tamanho da piramide braba: ");
    scanf("%d", &linhas);
    if(linhas > 0 && linhas <= 10){
        break;
    } } while (1);

    //chamada da funcao 
    if(temp == 's') arvore(linhas, 1);
    else arvore(linhas, 0);

    //exito
    return 0;
}

void arvore(int linhas, int invertida){
    int asterisco = 1;
    
    if(invertida){
        int espaco = 0, asterisco = linhas + linhas - 1;
        while(linhas--){
            for(int i = 1; i <= espaco; i++){ printf(" "); }
            for(int i = asterisco; i > 0; i-- ){ printf("*"); }

            printf("\n");

            espaco++;
            asterisco -= 2;
        }

    } else{
        while(linhas--){
            for(int i = linhas - 1; i >= 0; i--){ printf(" "); }
            for(int i = asterisco; i > 0; i-- ){ printf("*"); }

            printf("\n");

            asterisco += 2;
        }
    }
}