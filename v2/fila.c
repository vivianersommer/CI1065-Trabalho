#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"
#include "fila.h"

struct Fila* criar_fila(int capacidade){

    struct Fila* fila = (struct Fila*) malloc(sizeof(struct Fila));

    fila->capacidade = capacidade;
    fila->frente = fila->tamanho = 0;
    fila->atras = capacidade - 1;
    fila->itens = (struct Lista_Adj*) malloc(fila->capacidade * sizeof(struct Lista_Adj));

    return fila;
}

int esta_cheia(struct Fila* fila){
    return (fila->tamanho == fila->capacidade);
}

int esta_vazia(struct Fila* fila){
    return (fila->tamanho == 0);
}

void enfileira(struct Fila* fila, struct Lista_Adj item){

    fila->atras = (fila->atras + 1) % fila->capacidade;
    fila->itens[fila->atras] = item;
    fila->tamanho = fila->tamanho + 1;
}

struct Lista_Adj desenfileira(struct Fila* fila){

    struct Lista_Adj item = fila->itens[fila->frente];

    fila->frente = (fila->frente + 1)% fila->capacidade;
    fila->tamanho = fila->tamanho - 1;

    return item;
}

struct Lista_Adj frente(struct Fila* fila){
    return fila->itens[fila->frente];
}

struct Lista_Adj atras(struct Fila* fila){
    return fila->itens[fila->atras];
}