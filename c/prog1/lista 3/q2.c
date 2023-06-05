/*
Descricao: programa imprime uma piramide de altura entre 1 e 10
entrada: um numero pra altura
Saida: piramide!!!!!!!
defesa: nao aceita numero negativo e nem acima de 10
*/
#include <stdio.h>

int main(){
    //dicionario de dados
    int linhas, asterisco = 1;

    //defesa do codigo + input do tamanho
    do{
    printf("Digite o tamanho da piramide braba: ");
    scanf("%d", &linhas);
    if(linhas > 0 && linhas <= 10){
        break;
    } } while (1);

    //piramide!!!!!!!!!
    while(linhas--){
        for(int i = linhas - 1; i >= 0; i--){ printf(" "); }
        for(int i = asterisco; i > 0; i-- ){ printf("*"); }

        printf("\n");

        asterisco += 2;
    }

    //retorno esperado chefe
    return 0;
}