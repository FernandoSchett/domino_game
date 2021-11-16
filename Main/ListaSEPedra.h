#ifndef LISTASE_H
#define LISTASE_H
#include<stdio.h>
#include<stdlib.h>

typedef struct{
		int esquerda, direita; 
	}tp_pedra;

typedef tp_pedra tp_itemM;

typedef struct tp_no{
  tp_itemM info;
  struct tp_no *prox;
}tp_listase;

tp_listase*inicializa_listase(){
  return NULL;
}

int listase_vazia(tp_listase *lista){
  if(lista==NULL) return 1;
  else return 0;
}

tp_listase *aloca_listase(){
  tp_listase *novo_no;
  novo_no = (tp_listase*) malloc(sizeof(tp_listase));
  return novo_no;
}

int insere_listase_no_fim(tp_listase **l, tp_itemM e){
  tp_listase *novo_no, *atu;
  novo_no = aloca_listase();
  if(novo_no == NULL) return 0;
  novo_no->info = e;
  printf("Teste dentro");
  if(listase_vazia(*l)){
    *l = novo_no;
    printf("Teste dentro2");
  } else{
    printf("Teste dentro3");
    atu = *l;
    while(atu->prox != NULL){
      atu = atu->prox;
    }
    atu->prox=novo_no;
  }
printf("Teste dentro4");
return 1;
}

void imprime_listase(tp_listase *lista){
  tp_listase *atu;
  atu = lista;
  while(atu!=NULL){
    printf("%d|%d\n", atu->info.esquerda, atu->info.direita);
    atu=atu->prox;
  }
}

tp_pedra jogaAPecaPelaPosicao(tp_listase **lista, int e){
  tp_listase *ant, *atu;
  tp_pedra k;
  int c=0;
  atu = *lista;
  ant = NULL;
  while(c != e){
    ant = atu;
    atu = atu->prox; 
    c++;
  }
  if(ant == NULL){
    *lista = atu->prox;
  }else{
    ant->prox = atu->prox;    
  }
  k = atu->info;
  free(atu);
  atu = NULL;
  return k;
}

int tamanho_listase(tp_listase *lista){
  int cont = 0;
  tp_listase *atu;
  atu=lista;
  while(atu!=NULL){
    cont++;
    atu=atu->prox;
  }
  return cont;
}

int retiraUltimoDaLista(tp_listase **lista, tp_pedra *e){
  tp_listase *atu, *aux;
  tp_pedra k;
  if(listase_vazia(*lista)) return 0;
    
   else{
    atu = *lista;
    while(atu->prox != NULL){
      atu = atu->prox;
    }
    aux = atu->prox;
    *e = aux->info;
    atu->prox=NULL;
    free(aux);
    aux = NULL;
  }
  
  return 1;
}


#endif