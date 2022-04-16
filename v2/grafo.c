#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

#define MAX_NOME 20

struct Grafo* criar_grafo(int numero_vertices){
    struct Grafo* grafo = (struct Grafo*) malloc(sizeof(struct Grafo));

    grafo->numero_vertices = numero_vertices;

    // TODO: remover esse trecho ------------------
    grafo->lista = (struct Lista_Adj*) malloc(numero_vertices * sizeof(struct Lista_Adj));
    grafo->lista = malloc(1);
    for (int i = 0; i < numero_vertices; ++i){
        grafo->lista[i].cabeca = NULL;
    }
    //---------------------------------------------

    return grafo;
}

struct Nodo_Lista_Adj* criar_Nodo_Lista_Adj(char nome[MAX_NOME]){
    struct Nodo_Lista_Adj* nodo = (struct Nodo_Lista_Adj*) malloc(sizeof(struct Nodo_Lista_Adj));

    strcpy(nodo->nome, nome);
    nodo->proximo = NULL;

    return nodo;
}

void adicionar_aresta(struct Grafo* grafo, char src[MAX_NOME], char dest[MAX_NOME]){

    struct Nodo_Lista_Adj* check = NULL;
    struct Nodo_Lista_Adj* nodo = criar_Nodo_Lista_Adj(dest);
    int index_src, index_dest = 0;

    puts(src);
    index_src = procurar_vertice(grafo, src);
    puts(dest);
    index_dest = procurar_vertice(grafo, dest);

    printf("Adicionar no vértice %s - %d ligacao com vértice %s\n", src, index_src, dest);
    if (grafo->lista[index_src].cabeca == NULL) {
        nodo->proximo = grafo->lista[index_src].cabeca;
        grafo->lista[index_src].cabeca = nodo;
    } else {
        check = grafo->lista[index_src].cabeca;
        while (check->proximo != NULL) {
            check = check->proximo;
        }
        check->proximo = nodo;
    }

    nodo = criar_Nodo_Lista_Adj(src);
    printf("Adicionar no vértice %s - %d ligacao com vértice %s\n", dest, index_dest, src);
    if (grafo->lista[index_dest].cabeca == NULL) {
        nodo->proximo = grafo->lista[index_dest].cabeca;
        grafo->lista[index_dest].cabeca = nodo;
    } else {
        check = grafo->lista[index_dest].cabeca;
        while (check->proximo != NULL) {
            check = check->proximo;
        }
        check->proximo = nodo;
    }
}

int criar_vertice(struct Grafo* grafo, char ver[MAX_NOME]){

    int index_novo_vertice = grafo->numero_vertices + 1;

    grafo->lista = (struct Lista_Adj*) realloc(grafo->lista, index_novo_vertice * sizeof(struct Lista_Adj));
    
    strcpy(grafo->lista[index_novo_vertice].nome, ver);
    grafo->lista[index_novo_vertice].cabeca = NULL;

    grafo->numero_vertices = grafo->numero_vertices + 1;
    
    return index_novo_vertice;
}

int procurar_vertice(struct Grafo* grafo, char ver[MAX_NOME]){
    
    struct Lista_Adj item;
    for(int i=0; i <= grafo->numero_vertices; i++){

        item = grafo->lista[i];
        if (strcmp(item.nome, ver) == 0){ //vertice já está na lista
            puts("Encontrei o vértice");
            return i;
        }
    }

    puts("Não encontrei o vértice");
    // se após percorrer lista, não encontrar = criar novo vértice
    return criar_vertice(grafo, ver);
}

void imprimir_grafo(struct Grafo* grafo){
    for (int v = 1; v <= grafo->numero_vertices; ++v) {
        struct Nodo_Lista_Adj* temp = grafo->lista[v].cabeca;
        printf("\n Lista de adjacencia do vértice %s\n cabeca ", grafo->lista[v].nome);
        while (temp) {
            printf("-> %s", temp->nome);
            temp = temp->proximo;
        }
        printf("\n");
    }
}

struct Grafo* leitura_arquivo(FILE *input){
    struct Grafo* grafo = criar_grafo(0);

    char str1[MAX_NOME];
    char str2[MAX_NOME];

    while(!feof(input)){
        fscanf(input,"%s", str1);
        fscanf(input,"%s", str2);

        adicionar_aresta(grafo, str1, str2); 
        printf("--------------------------\n");
    }

    imprimir_grafo(grafo);

    return grafo;
}

