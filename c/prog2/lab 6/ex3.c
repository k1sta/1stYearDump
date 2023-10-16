#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

//def tipos
typedef int bool;
typedef char TIPOCHAVE;
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
bool excluirElemPilha(PILHA* p, REGISTRO* reg);
int tamanho(PILHA* p);

int main(int argc, char** argv){
    //dicionario de dados
    PILHA p1, p1Cpy, p2;
    char word[50];
    int sizePile;

    //atribuir NULL ao topo das pilhas
    inicializarPilha(&p1);
    inicializarPilha(&p1Cpy);
    inicializarPilha(&p2);

    //input da palavra
    printf("Digite uma palavra: ");
    scanf("%s", word); 

    //inserir a palavra nas pilhas
    for(int i = 0; word[i] != '\0'; i++){
        REGISTRO reg;
        reg.chave = word[i];
        inserirElemPilha(&p1, reg);
        inserirElemPilha(&p1Cpy, reg);
    }

    //checa o tamanho da pilha e atribui para auxiliar os loops-for 
    sizePile = tamanho(&p1);

    //inverte a pilha p1 e insere em p2
    for(int i = 0; i < sizePile; i++){
        REGISTRO reg;   
        excluirElemPilha(&p1Cpy, &reg);
        inserirElemPilha(&p2, reg);
    }

    //compara as pilhas p1 e p2.
    //se forem diferentes, a palavra não é palíndroma
    for(int i = 0; i < sizePile; i++){
        REGISTRO reg1, reg2;
        excluirElemPilha(&p1, &reg1);
        excluirElemPilha(&p2, &reg2);
        if(reg1.chave != reg2.chave){
            printf("A palavra '%s' nao eh palindroma\n", word);
            return 1;
        }
    }

    //se chegou até aqui, a palavra é palíndroma
    printf("A palavra '%s' eh palindroma\n", word);

    //acabou :)
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
bool excluirElemPilha(PILHA* p, REGISTRO* reg)
{
    if (p->topo == NULL) return false;
    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}
int tamanho(PILHA* p) {
    PONT end = p->topo;
    int tam = 0;
    while (end != NULL) {
        tam++;
        end = end->prox;
    }
    return tam;
}   