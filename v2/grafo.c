#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

#define MAX_NOME 20
#define MAX_VERTICES 100

struct Grafo* criar_grafo(int numero_vertices){
    struct Grafo* grafo = (struct Grafo*) malloc(sizeof(struct Grafo));

    grafo->numero_vertices = V;
    grafo->array = (struct Lista_Adj*) malloc(V * sizeof(struct Lista_Adj));

    for (int i = 0; i < V; ++i){
        grafo->lista[i].cabeca = NULL;
    }

    return grafo;
}

struct Nodo_Lista_Adj* criar_Nodo_Lista_Adj(char[MAX_NOME] nome){
    struct Nodo_Lista_Adj* nodo = (struct Nodo_Lista_Adj*) malloc(sizeof(struct Nodo_Lista_Adj));

    nodo->nome = nome;
    nodo->proximo = NULL;

    return nodo;
}

void adicionar_aresta(struct Grafo* grafo, char[MAX_NOME] src, char[MAX_NOME] dest){

    struct Nodo_Lista_Adj* check = NULL;
    struct Nodo_Lista_Adj* nodo = criar_Nodo_Lista_Adj(dest);

//    int index = procurar_vertice(grafo, dest);
    if (grafo->lista[src].cabeca == NULL) {
        nodo->proximo = grafo->lista[src].cabeca;
        grafo->lista[src].cabeca = nodo;
    } else {
        check = grafo->lista[src].cabeca;
        while (check->proximo != NULL) {
            check = check->proximo;
        }
        check->proximo = nodo;
    }

    nodo = criar_Nodo_Lista_Adj(src);
    if (grafo->lista[dest].cabeca == NULL) {
        nodo->proximo = grafo->lista[dest].cabeca;
        grafo->lista[dest].cabeca = nodo;
    } else {
        check = grafo->lista[dest].cabeca;
        while (check->proximo != NULL) {
            check = check->proximo;
        }
        check->proximo = nodo;
    }
}


void le_grafo(FILE *input) {

 struct Grafo* grafo = criar_grafo(0);

 while(!feof(input)){
     fscanf(input,"%s", str1);
     fscanf(input,"%s", str2);
     printf("%s - %s\n", str1, str2);
     printf("---------------\n");
 }

}

