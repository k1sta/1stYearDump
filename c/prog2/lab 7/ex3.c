#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;
typedef struct
{
    TIPOCHAVE chave;
    // outros campos...
} REGISTRO;
typedef struct aux
{
    REGISTRO reg;
    struct aux *prox;
} ELEMENTO;
typedef ELEMENTO *PONT;
typedef struct
{
    PONT inicio;
} LISTA;

void inicializarLista(LISTA *l);
int tamanho(LISTA *l);
void exibirLista(LISTA *l);
bool insere(LISTA *l, REGISTRO reg, int pos);
bool exclui(LISTA *l, int pos);
void reinicializarFila(LISTA *l);
void concatenaListas(LISTA* ll, LISTA* li);
bool iguaisListas(LISTA* l1, LISTA* l2);
bool modificaElem(LISTA* l, REGISTRO reg, int pos);

int main(){
    LISTA teste1, teste2;
    int k = 0, j = 0;

    inicializarLista(&teste1);
    inicializarLista(&teste2);
    
    for(int i = 1; i <= 10; i++){
        REGISTRO reg;
        reg.chave = i;
        insere(&teste1, reg, j++);
        insere(&teste2, reg, k++);
    }

    REGISTRO reg;
    reg.chave = 100;

    modificaElem(&teste1, reg, 5);

    exibirLista(&teste1);

    return 0;
}

void inicializarLista(LISTA *l)
{
    l->inicio = NULL;
}
int tamanho(LISTA *l)
{
    PONT end = l->inicio;
    int tam = 0;
    while (end != NULL)
    {
        tam++;
        end = end->prox;
    }
    return tam;
}
void exibirLista(LISTA *l)
{
    PONT end = l->inicio;
    printf("Lista: \" ");
    while (end != NULL)
    {
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}
bool insere(LISTA *l, REGISTRO reg, int pos)
{
    if (pos < 0 || pos > tamanho(l))
        return false;
    ELEMENTO *novo = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    int i;
    ELEMENTO *p;
    if (pos == 0)
    {
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    else
    {
        p = l->inicio;
        for (i = 0; i < pos - 1; i++)
            p = p->prox;
        novo->prox = p->prox;
        p->prox = novo;
    }
    return true;
}
bool exclui(LISTA *l, int pos)
{
    if (pos < 0 || pos > tamanho(l) - 1)
        return false;
    int i;
    ELEMENTO *p;
    ELEMENTO *apagar;
    if (pos == 0)
    {
        apagar = l->inicio;
        l->inicio = apagar->prox;
    }
    else
    {
        p = l->inicio;
        for (i = 0; i < pos - 1; i++)
            p = p->prox;
        apagar = p->prox;
        p->prox = apagar->prox;
    }
    free(apagar);
    return true;
}
void reinicializarFila(LISTA *l)
{
    PONT end = l->inicio;
    while (end != NULL)
    {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
}


void concatenaListas(LISTA* l1, LISTA* l2){
    PONT aux = l1->inicio, finalL1;
    while (aux != NULL)
    {
        finalL1 = aux;
        aux = aux->prox;
    } 
    finalL1->prox = l2->inicio;
}

bool iguaisListas(LISTA* l1, LISTA* l2){
    PONT endL1 = l1->inicio, endL2 = l2->inicio;
    while(1){
        if((endL1 != NULL) != (endL2 != NULL)) return false;
        if(endL1 == NULL && endL2 == NULL) return true;

        if(endL1->reg.chave != endL2->reg.chave) return false;
        else{
            endL1 = endL1->prox;
            endL2 = endL2->prox;
        }
    }
}

bool modificaElem(LISTA* l, REGISTRO reg, int pos){
    PONT aux = l->inicio;
    for(int i = 0; i < pos; i++){
        aux = aux->prox;
        if(aux == NULL) return false;
    }
    aux->reg = reg;
    return true;
}