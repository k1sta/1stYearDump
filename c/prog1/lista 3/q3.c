/*
descricao: imprime a uma piramide, que nem a q3, mas permite a escolha entre uma piramide em pe ou invertida.
entrada: um caractere entre s ou n e um numero para a altura da piramide
saída: piramide!!!!!!
defesa: o caractere n pode ser algo diferente de s, S, n ou N e o numero nao pode ser menor que 0 ou maior que 10
*/
#include <stdio.h>

void arvore(int linhas, int invertida);

int main(){
    //dicionario de dados
    int linhas;
    char temp;

    //defesa do codigo + input do tamanho
    do{
    printf("Você deseja uma pirâmide invertida (s/n)? ");
    scanf("%c", &temp);
    if (temp == 's' || temp == 'S'|| temp == 'n' || temp == 'N') break;
    } while (1);

    do{
    printf("Digite o tamanho da piramide braba: ");
    scanf("%d", &linhas);
    if(linhas > 0 && linhas <= 10) break;
    } while (1);

    //chamada da funcao 
    if(temp == 's' || temp == 'S') arvore(linhas, 1);
    else arvore(linhas, 0);

    //exito
    return 0;
}


//essa funcao imprime a piramide de acordo com as preferencias do usuario atraves de 1 parametro inteiro para definir o tamanho e outro tambem inteiro pra definir se sera invertida
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