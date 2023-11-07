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
PONT inicio;
PONT fim;
} FILA;

void inicializarFila(FILA* f);
bool inserirNaFila(FILA* f,REGISTRO reg);
bool excluirDaFila(FILA* f, REGISTRO* reg);

int main(){
    FILA oddLine, evenLine;
    REGISTRO aux;

    inicializarFila(&oddLine);
    inicializarFila(&evenLine);

    do{
        printf("insert a number: ");
        scanf("%d", &aux.chave);

        if(aux.chave == 0) break;

        if(aux.chave % 2) inserirNaFila(&oddLine, aux);
        else inserirNaFila(&evenLine, aux);
        
    } while (1);

    while(excluirDaFila(&oddLine, &aux)) printf("%d\n", aux.chave);
    while(excluirDaFila(&evenLine, &aux)) printf("%d\n", aux.chave);

    return 0;
}

void inicializarFila(FILA* f) {
f->inicio = NULL;
f->fim = NULL;
}
bool inserirNaFila(FILA* f,REGISTRO reg) {
PONT novo = (PONT) malloc(sizeof(ELEMENTO));
novo->reg = reg;
novo->prox = NULL;
if (f->inicio==NULL) f->inicio = novo;
else f->fim->prox = novo;
f->fim = novo;
return true;
}
bool excluirDaFila(FILA* f, REGISTRO* reg) {
if (f->inicio==NULL) return false;
*reg = f->inicio->reg;
PONT apagar = f->inicio;
f->inicio = f->inicio->prox;
free(apagar);
if (f->inicio == NULL) f->fim = NULL;
return true; }