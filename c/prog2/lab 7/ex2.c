#include <stdio.h>
#include <stdlib.h>


#define true 1
#define false 0
#define MAX 100

typedef int bool;
typedef struct {
    int numProdutos;
    int segChegada;
    int segSaida;
    char nome[MAX];
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

void inicializarFila(FILA* f) ;
int tamanho(FILA* f);
bool inserirNaFila(FILA* f,REGISTRO reg);
bool excluirDaFila(FILA* f, REGISTRO* reg);
void reinicializarFila(FILA* f);

int main(){
    FILA filaCaixa;
    const int pagamento = 10;
    int k, c;
    REGISTRO auxAnt, auxNovo;

    inicializarFila(&filaCaixa);

    auxNovo.segChegada = 0;
    auxNovo.segSaida = 0;

    scanf("%d", &k);
    getchar();
    scanf("%d", &c);
    getchar();

    for(int i = 0; i < c; i++){ 
        auxAnt = auxNovo;

        scanf("%s %d %d", auxNovo.nome, &auxNovo.segChegada, &auxNovo.numProdutos);
        getchar();
        
        if(auxNovo.segChegada < auxAnt.segSaida){
            auxNovo.segSaida = pagamento + auxNovo.numProdutos * k + auxAnt.segSaida;
        } else {
            auxNovo.segSaida = pagamento + auxNovo.numProdutos * k + auxNovo.segChegada;
        }

        inserirNaFila(&filaCaixa, auxNovo);
    }
    printf("\n");
    while(excluirDaFila(&filaCaixa, &auxAnt)) printf("%s %d %d\n", auxAnt.nome, auxAnt.segChegada, auxAnt.segSaida);

    return 0;
}

void inicializarFila(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
}
int tamanho(FILA* f) {
    PONT end = f->inicio;
    int tam = 0;
    while (end != NULL) {
        tam++;
        end = end->prox;
    }
    return tam;
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
    return true;
}
void reinicializarFila(FILA* f) {
    PONT end = f->inicio;
    while (end != NULL) {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
}
