#ifndef _GRAFO_H
#define _GRAFO_H

#include <stdio.h>
#define MAX_NOME 20

//------------------------------------------------------------------------------
// (apontador para) estrutura de dados para representar um grafo
// 
// o grafo tem um nome, que é uma "string"
struct grafo {
    char nome[MAX_NOME];
    int numero_vertices;
    struct vertice* vertices;
};
typedef struct grafo *grafo; //OK

//------------------------------------------------------------------------------
// (apontador para) estrutura de dados para representar um vértice
// 
// o vértice tem um nome, que é uma "string"
struct vertice {
    char nome[MAX_NOME];
    struct vertice* proximo;
};
typedef struct vertice *vertice; //OK

//------------------------------------------------------------------------------
// desaloca toda a memória usada em *g
// 
// devolve 1 em caso de sucesso,
//         ou 
//         0, caso contrário

int destroi_grafo(grafo g); //OK

//------------------------------------------------------------------------------
// lê um grafo de input.
// um grafo é um arquivo onde cada linha tem zero, uma ou duas
// strings (sequência de caracteres sem "whitespace").
// 
// devolve o grafo lido. Caso o arquivo esteja mal formado o
// comportamento da função é indefinido

grafo le_grafo(FILE *input);  



//------------------------------------------------------------------------------
// pede para o usuário entrar com um vértice.

vertice le_vertice(void);  

//------------------------------------------------------------------------------
// escreve o grafo g em output, no mesmo formato que o usado por le_grafo()
//
// devolve o grafo escrito,
//         ou 
//         NULL, em caso de erro 


//------------------------------------------------------------------------------
// devolve o coeficiente de agrupamento de g
// ou seja, o número de tríades fechadas divido pelo 
// total de tríades (ou seja, a soma de tríades abertas e fechadas).
// 

double coeficiente_proximidade(grafo g, vertice v);

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
struct grafo* adiciona_aresta(struct grafo* g, char str1[MAX_NOME], char str2[MAX_NOME]);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
struct grafo* criar_grafo(struct grafo *g);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
struct vertice criar_vertice(char str[MAX_NOME]);
//------------------------------------------------------------------------------


#endif
