#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "grafo.h"
#include "fila.h"
#include "fila.h"

#define MAX_NOME 20

struct Grafo* criar_grafo(void){
    struct Grafo* grafo = (struct Grafo*) malloc(sizeof(struct Grafo));

    grafo->numero_vertices = 0;
    grafo->lista = malloc(1);

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
    struct Nodo_Lista_Adj* nodo_1 = criar_Nodo_Lista_Adj(dest);
    struct Nodo_Lista_Adj* nodo_2 = criar_Nodo_Lista_Adj(src);
    int index_src, index_dest = 0;

    index_src = procurar_vertice(grafo, src);
    index_dest = procurar_vertice(grafo, dest);

    if (grafo->lista[index_src].cabeca == NULL) {
        nodo_1->proximo = grafo->lista[index_src].cabeca;
        grafo->lista[index_src].cabeca = nodo_1;
    } else {
        check = grafo->lista[index_src].cabeca;
        while (check->proximo != NULL) {
            check = check->proximo;
        }
        check->proximo = nodo_1;
    }

    if (grafo->lista[index_dest].cabeca == NULL) {
        nodo_2->proximo = grafo->lista[index_dest].cabeca;
        grafo->lista[index_dest].cabeca = nodo_2;
    } else {
        check = grafo->lista[index_dest].cabeca;
        while (check->proximo != NULL) {
            check = check->proximo;
        }
        check->proximo = nodo_2;
    }

}

int criar_vertice(struct Grafo* grafo, char ver[MAX_NOME]){

    int index_novo_vertice = grafo->numero_vertices + 1;
    int index = grafo->numero_vertices;

    grafo->lista = (struct Lista_Adj*) realloc(grafo->lista, index_novo_vertice * sizeof(struct Lista_Adj));
    
    strcpy(grafo->lista[index].nome, ver);
    grafo->lista[index].cabeca = NULL;

    grafo->numero_vertices = grafo->numero_vertices + 1;
    
    return index;
}

int procurar_vertice(struct Grafo* grafo, char ver[MAX_NOME]){
    
    struct Lista_Adj item;
    for(int i=0; i <= grafo->numero_vertices; i++){

        item = grafo->lista[i];
        if (strcmp(item.nome, ver) == 0){
            return i;
        }
    }

    return criar_vertice(grafo, ver);
}

void imprimir_grafo(struct Grafo* grafo){
    for (int v = 0; v < grafo->numero_vertices; ++v) {
        struct Nodo_Lista_Adj* temp = grafo->lista[v].cabeca;
        printf("\n Lista de adjacencia do vértice %s\n cabeca ", grafo->lista[v].nome);
        while (temp != NULL) {
            printf("-> %s", temp->nome);
            temp = temp->proximo;
        }
        printf("\n");
    }
    printf("\n");
}

struct Grafo* leitura_arquivo(FILE *input){
    struct Grafo* grafo = criar_grafo();

    char str1[MAX_NOME];
    char str2[MAX_NOME];

    while(!feof(input)){
        fscanf(input,"%s", str1);
        fscanf(input,"%s", str2);

        if(str1 == '\0' && str2 == '\0'){
            continue;
        }

        adicionar_aresta(grafo, str1, str2); 
    }

    return grafo;
}

struct Lista_Adj* leitura_vertice(void){

    struct Lista_Adj* vertice = (struct Lista_Adj*) malloc(sizeof(struct Lista_Adj));
    char name[MAX_NOME];

    printf("Digite o nome do vértice, para ser usado no cálculo do coeficiente de aproximação: ");
    scanf("%s", name);

    strcpy(vertice->nome, name);
    vertice->cabeca = NULL;

    return vertice;
}

double coeficiente_proximidade(struct Grafo* grafo, struct Lista_Adj* vertice){

    double n , d, c;
    n = grafo->numero_vertices;

    for(int i=0; i< grafo->numero_vertices; i++){
        d = d + busca_largura(grafo, *vertice, grafo->lista[i]);
    }

    c = n / d;
    return c;
}

int destroi_grafo(struct Grafo* grafo){

    struct Nodo_Lista_Adj* temp_1;
    struct Nodo_Lista_Adj* temp_2;
    for(int i=0; i<grafo->numero_vertices; i++){
       temp_1 = grafo->lista[i].cabeca;
       while (temp_1 != NULL) {
            temp_2 = temp_1;
            temp_1 = temp_1->proximo;
            free(temp_2);
       }
    }
    free(grafo->lista);
    free(grafo);

    free(temp_1);

    return grafo == NULL;
}

int calcula_numero_vizinhos(struct Lista_Adj u){

    int vizinhos = 0;
    struct Nodo_Lista_Adj* viz = u.cabeca;
    while(viz != NULL){
        viz = viz->proximo;
        vizinhos = vizinhos + 1;
    }

    return vizinhos;
}

double busca_largura(struct Grafo* grafo, struct Lista_Adj u, struct Lista_Adj v){

    struct Fila* fila;
    int n, index_u, index_v, index_viz, index_x, distancia[grafo->numero_vertices];
    bool visitado[grafo->numero_vertices];

    n = grafo->numero_vertices;

    for(int i = 0; i < n; i++){
        visitado[i] = false;
        distancia[i] = 0;
    }

    index_u = procurar_vertice(grafo, u.nome);
    index_v = procurar_vertice(grafo, v.nome);

    u = grafo->lista[index_u];
    v = grafo->lista[index_v];

    if (strcmp(u.nome, v.nome) == 0){
            return 0;
    }

    fila = criar_fila(n);
    enfileira(fila, u);

    distancia[index_u] = 0;
    visitado[index_u] = true;

    while (!esta_vazia(fila)){

        struct Lista_Adj x = desenfileira(fila);
        struct Nodo_Lista_Adj* viz = x.cabeca;
        index_x = procurar_vertice(grafo, x.nome);

        while(viz != NULL){

            index_viz = procurar_vertice(grafo, viz->nome);
            if (visitado[index_viz] == true){
                viz = viz->proximo;
                continue;
            }

            distancia[index_viz] = distancia[index_x] + 1;
            visitado[index_viz] = true;
            enfileira(fila, grafo->lista[index_viz]);

            viz = viz->proximo;
        }
    }

    return distancia[index_v];
}


