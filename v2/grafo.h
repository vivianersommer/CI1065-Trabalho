#ifndef _GRAFO_H
#define _GRAFO_H

#include <stdio.h>
#define MAX_NOME 20

// Nodo da lista de adjacencia --------------------------------------------
struct Nodo_Lista_Adj {
    int dest;
    char[MAX_NOME] nome;
    struct Nodo_Lista_Adj* proximo;
};
// ------------------------------------------------------------------------

// Lista de adjacencia ----------------------------------------------------
struct Lista_Adj {
    struct Nodo_Lista_Adj* cabeca;
};
// ------------------------------------------------------------------------


// Grafo ------------------------------------------------------------------
struct Grafo {
    int numero_vertices;
    struct Lista_Adj* lista;
};
// ------------------------------------------------------------------------

// Função para criar Grafo ------------------------------------------------
struct Grafo* criar_grafo(int numero_vertices);
// ------------------------------------------------------------------------

// Função para criar Nodo_Lista_Adj ---------------------------------------
struct Nodo_Lista_Adj* criar_Nodo_Lista_Adj(char[MAX_NOME] nome);
// ------------------------------------------------------------------------

// Função para adicionar arestas no grafo ---------------------------------
void adicionar_aresta(struct Grafo* grafo, char[MAX_NOME] src, char[MAX_NOME] dest);
// ------------------------------------------------------------------------

#endif
