#ifndef _GRAFO_H
#define _GRAFO_H

#include <stdio.h>
#define MAX_NOME 20

// Nodo da lista de adjacencia --------------------------------------------
struct Nodo_Lista_Adj {
    char nome[MAX_NOME];
    struct Nodo_Lista_Adj* proximo;
};
// ------------------------------------------------------------------------

// Lista de adjacencia ----------------------------------------------------
struct Lista_Adj {
    char nome[MAX_NOME];
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
struct Nodo_Lista_Adj* criar_Nodo_Lista_Adj(char nome[MAX_NOME]);
// ------------------------------------------------------------------------

// Função para adicionar arestas no grafo ---------------------------------
void adicionar_aresta(struct Grafo* grafo, char src[MAX_NOME], char dest[MAX_NOME]);
// ------------------------------------------------------------------------

// Função para ler procurar vértice no grafo ------------------------------
int criar_vertice(struct Grafo* grafo, char ver[MAX_NOME]);
// ------------------------------------------------------------------------

// Função para ler procurar vértice no grafo ------------------------------
int procurar_vertice(struct Grafo* grafo, char ver[MAX_NOME]);
// ------------------------------------------------------------------------

// Função para imprimir_grafo ---------------------------------------------
void imprimir_grafo(struct Grafo* grafo);
// ------------------------------------------------------------------------

// Função para ler arquivo do grafo ---------------------------------------
struct Grafo* leitura_arquivo(FILE *input);
// ------------------------------------------------------------------------

#endif
