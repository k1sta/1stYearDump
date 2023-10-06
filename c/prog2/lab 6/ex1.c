#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

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

void inicializarPilha(PILHA* p);
void exibirPilha(PILHA* p);
bool inserirElemPilha(PILHA* p, REGISTRO reg);
bool conversionDecToBin(int n, PILHA* p);

int main(void){
    PILHA p;
    int n;

    inicializarPilha(&p);

    do{
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &n);
    } while(n < 0); 

    conversionDecToBin(n, &p);
    
    exibirPilha(&p);
    return 0;
}

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

bool conversionDecToBin(int n, PILHA* p){
    REGISTRO resto;
    while (n != 0){
        resto.chave = n % 2;
        n = n / 2;
        inserirElemPilha(p, resto);
    }
    return true;
}
