#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

//def tipos
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

//prototypessss
void inicializarPilha(PILHA* p);
void exibirPilha(PILHA* p);
bool inserirElemPilha(PILHA* p, REGISTRO reg);
bool excluirElemPilha(PILHA* p, REGISTRO* reg);
int tamanho(PILHA* p);
bool operacaoPosFix(PILHA* p, char sinal);

int main(int argc, char** argv){
    //dicionario de dados
    PILHA p;
    FILE *fileptr;
    
    //abrir o arquivo
    fileptr = fopen(argv[1], "r");
    if(fileptr == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    //atribuir NULL ao topo da fila
    inicializarPilha(&p);

    //esse loop-while le o arquivo e difere os caracteres da seguinte maneira:
    //se for um algarismo, ele o insere na pilha
    //se não, utiliza a função para realizar a conta (para mais detalhes, vide a função na linha XX)
    while(!feof(fileptr)){
        char temp;
        fscanf(fileptr, "%c ", &temp);
        if(temp >= '0' && temp <= '9'){
            REGISTRO reg;
            reg.chave = temp - '0';
            inserirElemPilha(&p, reg);
        } else {
            operacaoPosFix(&p, temp);  
        }
    }

    //exibe o resultado
    exibirPilha(&p);

    //acabou:)
    fclose(fileptr);

    //acabou agora, no caso:)
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

//essa função recebe um char que contém a operação a ser feita e realiza a operação com os dois ultimos elementos da pilha passada por referência.
bool operacaoPosFix(PILHA* p, char sinal){
    REGISTRO reg1, reg2, reg3;
    if (excluirElemPilha(p, &reg1) && excluirElemPilha(p, &reg2)){
        switch (sinal)
        {
        case '+':
            reg3.chave = reg2.chave + reg1.chave;
            inserirElemPilha(p, reg3);
            break;
        case '-':
            reg3.chave = reg2.chave - reg1.chave;
            inserirElemPilha(p, reg3);
            break;
        case '*':
            reg3.chave = reg2.chave * reg1.chave;
            inserirElemPilha(p, reg3);
            break;
        case '/':
            reg3.chave = reg2.chave / reg1.chave;
            inserirElemPilha(p, reg3);
            break;
        
        default:
            break;
        }
    }

    //imprime a conta
    printf("%d %c %d = %d\n", reg2.chave, sinal, reg1.chave, reg3.chave);

    return true;
}