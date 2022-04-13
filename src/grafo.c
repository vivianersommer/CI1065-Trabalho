#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

//------------------------------------------------------------------------------
// (apontador para) estrutura de dados para representar um grafo
// 
// o grafo tem um nome, que é uma "string"

typedef struct grafo *grafo;

//------------------------------------------------------------------------------
// (apontador para) estrutura de dados para representar um vértice
// 
// o vértice tem um nome, que é uma "string"

typedef struct vertice *vertice;

//------------------------------------------------------------------------------
// desaloca toda a memória usada em *g
// 
// devolve 1 em caso de sucesso,
//         ou 
//         0, caso contrário

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
// lê um grafo
// 
// devolve o grafo lido,
//         ou 
//         NULL, em caso de erro 

grafo le_grafo(FILE *input) {

  struct grafo *g;
  
  input = fopen("peterson.txt","w");
  char *str2 = malloc(MAX_NOME * sizeof(char));
  while(!feof(input)){
    
    fgets(str2, MAX_NOME, input);
    puts(str2);
  }
  free(str2);

  return (grafo)input;
}


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

