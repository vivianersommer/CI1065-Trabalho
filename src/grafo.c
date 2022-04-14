#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

#define MAX_NOME 20
#define MAX_VERTICES 100


//------------------------------------------------------------------------------
// Desaloca toda a memória usada em *g
// Retorna:
//       1, em caso de sucesso,
//       0, caso contrário

int destroi_grafo(grafo g) {

  for (int i=0; i <= g->numero_vertices; i++){
    struct vertice ver = g->vertices[i];
    free(ver.proximo);
  }

  free(g->vertices);
  free(g);
  return g == NULL;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Lê do arquivo o grafo
// Retorna:
//       Grafo lido,
//       NULL, em caso de erro

grafo le_grafo(FILE *input) {

  struct grafo *g;
  g = criar_grafo(g);

  char str1[MAX_NOME];
  char str2[MAX_NOME];

  while(!feof(input)){
    fscanf(input,"%s", str1);
    fscanf(input,"%s", str2);

    g = adiciona_aresta(g, str1, str2);
    printf("numero de vertices = %d\n", g->numero_vertices);
    printf("%s - %s\n", str1, str2);
    printf("---------------\n");


    strncpy(str1,"",strlen(str1));
    strncpy(str2,"",strlen(str2));

  }

  return (grafo)input;
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// lê um vertice 

vertice le_vertice(void) {

  return (vertice) NULL;
}




//------------------------------------------------------------------------------
// devolve o coeficiente de proximidade do vértice v de g
// 

double coeficiente_proximidade(grafo g, vertice v) {
	
  v = NULL;
  g = NULL;

  return !(v == (vertice) g);
}

//------------------------------------------------------------------------------
struct grafo* adiciona_aresta(struct grafo* g, char str1[MAX_NOME], char str2[MAX_NOME]){

    puts(str1);
    puts(str2);

    struct vertice vertices[MAX_VERTICES] = g->vertices;

    puts("VERTICES");
    for(int i; i<g->numero_vertices; i++){
        puts(vertices[i].nome);
    }
    puts("----------------------------------");
    struct vertice* vertice_1 , vertice_2;
    vertice_1 = malloc

    strcpy(vertice_1.nome, "");
    strcpy(vertice_2.nome, "");


    for (int i=0; i< g->numero_vertices; i++){
        vertice_1 = vertices[i];
        if (strcmp(vertice_1.nome, str1) == 0){
            printf("1 - %s\n", str1);
            break;
        }
    }

    for (int i=0; i< g->numero_vertices; i++){
        vertice_2 = vertices[i];
        if (strcmp(vertice_2.nome, str2) == 0){
            printf("1 - %s\n", str2);
            break;
        }
    }

    if(strcmp(vertice_1.nome, "") == 0){
        printf("2 - %s\n", str1);
        vertice_1 = criar_vertice(str1);
        g->vertices[g->numero_vertices] = vertice_1;
        g->numero_vertices = g->numero_vertices + 1;
    }

    if(strcmp(vertice_2.nome, "") == 0){
        printf("2 - %s\n", str2);
        vertice_2 = criar_vertice(str2);
        g->vertices[g->numero_vertices] = vertice_2;
        g->numero_vertices = g->numero_vertices + 1;
    }

//    for(int i=0; i<= 1000; i++){
//       if(vertice_1.proximo[i] == NULL){
//            vertice_1.proximo[i] = vertice_2;
//       }
//    }
//
//    for(int i=0; i<= 1000; i++){
//       struct v = vertice_2.proximo[i];
//       if(v == NULL){
//            vertice_2.proximo[i] = vertice_1;
//       }
//    }


    return g;
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
struct grafo* criar_grafo(struct grafo *g){

    g = malloc(sizeof (struct grafo));
    g->numero_vertices = 0;
    g->vertices = malloc(sizeof(struct vertice));
    return g;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
struct vertice criar_vertice(char str[MAX_NOME]){

    struct vertice v;
    strcpy(v.nome, str);
    v.proximo = NULL;

    return v;
}
//------------------------------------------------------------------------------

