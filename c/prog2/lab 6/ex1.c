#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

//def. tipos
typedef int bool;
typedef int TIPOCHAVE;
typedef struct {
    TIPOCHAVE chave;
    //outros campos...
} REGISTRO;
typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;
typedef ELEMENTO* PONT;
typedef struct {
    PONT topo;
} PILHA;

//prototypes
void inicializarPilha(PILHA* p);
void exibirPilha(PILHA* p);
bool inserirElemPilha(PILHA* p, REGISTRO reg);
bool conversionDecToBin(int n, PILHA* p);

int main(void){
    //dicionario de dados   
    PILHA p;
    int n;

    //atribuir NULL ao topo da pilha
    inicializarPilha(&p);

    //input de um numero inteiro positivo
    do{
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &n);
    } while(n < 0); 

    //converter o numero para binario (para mais detalhes, vide função linha XX)
    conversionDecToBin(n, &p);
    
    //exibir resultado
    exibirPilha(&p);

    //acabou :)
    return 0;
}

//aux functions
void inicializarPilha(PILHA* p) {
    p->topo = NULL;
}
void exibirPilha(PILHA* p) {
    PONT end = p->topo;
    printf("Pilha: \" ");
    while (end != NULL) {
    printf("%i ", end->reg.chave);
    end = end->prox; }
    printf("\"\n"); 
}
bool inserirElemPilha(PILHA* p, REGISTRO reg)
{
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

//função da questão
bool conversionDecToBin(int n, PILHA* p){
    REGISTRO resto;
    //o loop-while abaixo segue a lógica da conversão de um número decimal para binário utilizando a base decimal para realizar a conta. caso usássemos a binária, utilizaríamos a técnica de conversão multiplicativa.
    while (n != 0){
        resto.chave = n % 2;
        n = n / 2;
        inserirElemPilha(p, resto);
    }
    return true;
}
