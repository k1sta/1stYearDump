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
bool corretudeExpressao(char* p);

int main(){
    //dicionario de dados
    char expression[100];

    //coleta o input do usuario
    printf("Digite uma expressao: ");
    scanf("%[^\n]", expression);  

    //"outputa" coisas diferentes a depender do resultado da função (para mais detalhes, vide função linha XX)
    if(corretudeExpressao(expression) == true){
        printf("A expressao '%s' eh valida\n", expression);
        return 0;
    } else {
        printf("A expressao '%s' nao eh valida\n", expression);
        return 1;
    }
}

//aux functions
void inicializarPilha(PILHA* p) {
    p->topo = NULL;
}
void exibirPilha(PILHA* p) {
    PONT end = p->topo;
    printf("Pilha: \" ");
    while (end != NULL) {
    printf("%c ", end->reg.chave);
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

//essa função cria uma pilha auxiliar que, toda vez que checa a abertura de um parênteses, coloca ele na pilha. quando chega no fechamento, ele checa se o topo da pilha é o parênteses correspondente. se for, ele exclui o topo da pilha e continua. se não for, ele retorna falso. se a pilha não estiver vazia no final, ele retorna falso. se estiver, retorna true.
bool corretudeExpressao(char* expression) {
    PILHA p;
    inicializarPilha(&p);
    int i = 0;

    //loop-while que percorre a expressão e checa a expressão com a pilha auxiliar
    while (expression[i] != '\0') {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            REGISTRO reg;
            reg.chave = expression[i];
            inserirElemPilha(&p, reg);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            REGISTRO reg;
            if (excluirElemPilha(&p, &reg) == false) {
                return false;
            }
            if (expression[i] == ')' && reg.chave != '(') {
                return false;
            } else if (expression[i] == ']' && reg.chave != '[') {
                return false;
            } else if (expression[i] == '}' && reg.chave != '{') {
                return false;
            }
        }
        i++;
    }
    if (p.topo != NULL) {
        return false;
    }

    //se chegou até aqui, a expressão é válida
    return true;
}