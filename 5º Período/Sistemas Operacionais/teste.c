/*
  Programa de teste de alocacao maxima de memória
  usando apenas C padrão (conforme ISO C99).
*/

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t alloc_max(size_t chunk_size){
  void *old_p, *new_p;
  size_t total;

  if(chunk_size<sizeof(size_t)){
    fprintf(stderr, "O tamanho minimo do bloco deve ser de %zu bytes.\n", sizeof(size_t));
    return 0;
  }

  total=0;
  old_p=NULL;
  while((new_p=malloc(chunk_size))!=NULL){
    total+=chunk_size;
    /*
      XXX: Preenche memória alocada (para forçar seu uso efetivo em sistema com lazy allocation.
           Por isso, aliás, a restrição de tamanho mínimo, imposta acima.
    */
    memset(new_p, rand(), chunk_size);

    /* Guarda o endereço do bloco anterior no começo do novo bloco, para poder desalocar depois. */
    *(size_t **)new_p=old_p;
    old_p=new_p;
  }

  for(new_p=old_p; new_p!=NULL; new_p=old_p){
    old_p=*(void **)new_p;
    free(new_p);
  }

  return total;
}

int main(void){
  size_t chunk, max;
  for(chunk=4096; chunk<SIZE_MAX/32+1; chunk*=16){
    max=alloc_max(chunk);
    printf("Total de %zu bytes (%zu blocos de %zu bytes).\n", max, max/chunk, chunk);
  }
  return 0;
}
