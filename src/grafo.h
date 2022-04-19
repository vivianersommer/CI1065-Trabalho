#ifndef _GRAFO_H
#define _GRAFO_H

#include <stdio.h>
#define MAX_NOME 20


// ESTRUTURAS DE DADOS ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 

    // Nodo da lista de adjacencia --------------------------------------------
    struct Nodo_Lista_Adj {
        char nome[MAX_NOME];                // nome do vértice que é vizinho ao vértice
        struct Nodo_Lista_Adj* proximo;     // ponteiro para próximo vizinho do vértice
    };
    // ------------------------------------------------------------------------

    // Lista de adjacencia ----------------------------------------------------
    struct Lista_Adj {
        char nome[MAX_NOME];                // nome do vértice
        struct Nodo_Lista_Adj* cabeca;      // lista de vizinhos do vértice
    };
    // ------------------------------------------------------------------------

    // Grafo ------------------------------------------------------------------
    struct Grafo {
        int numero_vertices;                // número de vértices no grafo
        struct Lista_Adj* lista;            // lista de vértices do grafo
    };
    // ------------------------------------------------------------------------

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 

// FUNÇÕES +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // Função para criar Grafo ------------------------------------------------
    struct Grafo* criar_grafo(void);
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

    // Função para ler vértice do terminal ------------------------------------
    struct Lista_Adj* leitura_vertice(void);
    // ------------------------------------------------------------------------

    // Função para calcular coeficiente de aproximação ------------------------
    double coeficiente_proximidade(struct Grafo* grafo, struct Lista_Adj* vertice);
    // ------------------------------------------------------------------------

    // Função para calcular coeficiente de aproximação ------------------------
    int destroi_grafo(struct Grafo* grafo);
    // ------------------------------------------------------------------------

    // Função para calcular coeficiente de aproximação ------------------------
    double busca_largura(struct Grafo* grafo, struct Lista_Adj u, struct Lista_Adj v);
    // ------------------------------------------------------------------------

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 

#endif
