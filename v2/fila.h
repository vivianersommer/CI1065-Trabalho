#ifndef _FILA_H
#define _FILA_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// ESTRUTURAS DE DADOS ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

struct Fila {
    int frente, atras, tamanho, capacidade;
    struct Lista_Adj* itens;
};

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// FUNÇÕES +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // Função para criar fila -------------------------------------------------
    struct Fila* criar_fila(int capacidade);
    // ------------------------------------------------------------------------

    // Função para ver se fila esta cheia -------------------------------------
    int esta_cheia(struct Fila* fila);
    // ------------------------------------------------------------------------

    // Função para ver se fila esta vazia -------------------------------------
    int esta_vazia(struct Fila* fila);
    // ------------------------------------------------------------------------

    // Função para ver adicionar item na fila ---------------------------------
    void enfileira(struct Fila* fila, struct Lista_Adj item);
    // ------------------------------------------------------------------------

    // Função para ver remover item na fila -----------------------------------
    struct Lista_Adj desenfileira(struct Fila* fila);
    // ------------------------------------------------------------------------

    // Função para pegar primeiro item da fila --------------------------------
    struct Lista_Adj frente(struct Fila* fila);
    // ------------------------------------------------------------------------

    // Função para pegar ultimo item da fila ----------------------------------
    struct Lista_Adj atras(struct Fila* fila);
    // ------------------------------------------------------------------------

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#endif
