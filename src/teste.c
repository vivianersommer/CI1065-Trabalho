#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"


int main(void){

  struct Grafo* grafo;
  struct Lista_Adj* vertice;
  double coef;

  FILE *input;
  input = fopen("peterson.txt","r+");

  if(input == NULL){
    puts("Erro ao ler arquivo!");
    return 1;
  }

  grafo = leitura_arquivo(input);

  if(grafo == NULL){
     return 1;
  }

  vertice = leitura_vertice();

   if(vertice == NULL){
     return 1;
   }

   coef = coeficiente_proximidade(grafo, vertice);

   printf ("O coeficiente de proximidade é %f\n", coef);

   return ! destroi_grafo(grafo);
}
