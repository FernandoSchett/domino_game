#ifndef LISTASE_H
#define LISTASE_H
#include<stdio.h>
#include<stdlib.h>
typedef int tp_item;
typedef struct tp_no{
  tp_item info;
  struct tp_no *prox;
}tp_listase;

tp_listase *inicializa_listase(){
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

int insere_listase_no_fim(tp_listase **l, tp_item e){
  tp_listase *novo_no, *atu;
  novo_no = aloca_listase();
  if(novo_no == NULL) return 0;
  novo_no->info = e;
  novo_no->prox = NULL;

  if(listase_vazia(*l)){
    *l = novo_no;
  } else{
    atu = *l;
    while(atu->prox != NULL){
      atu = atu->prox;
    }
    atu->prox=novo_no;
  }

return 1;
}

void imprime_listase(tp_listase *lista){
  tp_listase *atu;
  atu = lista;
  while(atu!=NULL){
    printf("%d\n", atu->info);
    atu=atu->prox;
  }
}

int remove_listase(tp_listase **lista, tp_item e){
  tp_listase *ant, *atu;
  atu = *lista;
  ant = NULL;
  while((atu!=NULL) && (atu->info!=e)){
    ant = atu;
    atu = atu->prox; }
  if(atu == NULL) return 0;
  if(ant == NULL){
    *lista = atu->prox;
  }else{
    ant->prox = atu->prox;    
  }
  free(atu);
  atu = NULL;
  return 1;
}

tp_listase *busca_listase(tp_listase *lista, tp_item e){
  tp_listase *atu;
  atu = lista;
  while((atu!=NULL) && (atu->info!=e)){
    atu = atu->prox; }
  if(atu == NULL) return NULL;
  return atu;
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

int insere_listase_no_inicio(tp_listase **l, tp_item e){
  tp_listase *novo_no;
  novo_no = aloca_listase();
  if(novo_no == NULL) return 0;
  novo_no->info = e;
  if(listase_vazia(*l)){
    novo_no->prox = NULL;
  } else novo_no->prox = *l;
  *l = novo_no;
  
return 1;
}

int contagem_maior_que_n(tp_listase *l, tp_item e){
  int cont = 0;
  tp_listase *atu;
  atu=l;
  while(atu!=NULL){
    if(atu->info > e) cont++;
    atu=atu->prox;
  }
  return cont;
}

void desfaz_lista(tp_listase **lista){
  tp_listase *atu;
  atu = *lista;
  while(atu!=NULL){
    *lista = atu->prox;
    free(atu);
  }
}

int checagem_igual(tp_listase *lista1, tp_listase *lista2){
  tp_listase *atu1, *atu2;
  atu1 = lista1;
  atu2 = lista2;
  if(tamanho_listase(lista1) != tamanho_listase(lista2) ) return 0;
  while(atu1!=NULL){
    if(atu1->info != atu2->info) return 0;
    atu1=atu1->prox;
    atu2=atu2->prox;    
  }
return 1;
}

#endif