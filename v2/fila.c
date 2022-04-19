#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"
#include "fila.h"

struct Fila* criar_fila(int capacidade){

    struct Fila* fila = (struct Fila*) malloc(sizeof(struct Fila));

    // configurações iniciais da Fila
    fila->capacidade = capacidade;
    fila->frente = fila->tamanho = 0;
    fila->atras = capacidade - 1;

    // cria Fila com capacidade máxima fornecida
    fila->itens = (struct Lista_Adj*) malloc(fila->capacidade * sizeof(struct Lista_Adj));

    return fila;
}

int esta_vazia(struct Fila* fila){
    return (fila->tamanho == 0);
}

void enfileira(struct Fila* fila, struct Lista_Adj item){

    // adiciona item , ajusta o vértice que fica na ultima posição (atras)
    // e atualiza tamanho da Fila

    fila->atras = (fila->atras + 1) % fila->capacidade;
    fila->itens[fila->atras] = item;
    fila->tamanho = fila->tamanho + 1;
}

struct Lista_Adj desenfileira(struct Fila* fila){

    // remove item , ajusta o vértice que fica na primeira posição (frente)
    // e atualiza tamanho da Fila

    struct Lista_Adj item = fila->itens[fila->frente];

    fila->frente = (fila->frente + 1)% fila->capacidade;
    fila->tamanho = fila->tamanho - 1;

    return item;
}
