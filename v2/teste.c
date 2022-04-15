#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"


int main(void){

  struct grafo* g;
  struct vertice v;
  double coef;

  FILE *input;
  input = fopen("peterson.txt","r+");

  if(input == NULL){
    puts("Erro ao ler arquivo!");
    return 1;
  }

  g = le_grafo(input);


  // v = le_vertice();

  // if( !g ){
  //   return 1;
  // }

  // coef = coeficiente_proximidade(g,v);

  // printf ("O coeficiente de proximidade é %f\n", coef);

  // return ! destroi_grafo(g);
  return 0;
}
