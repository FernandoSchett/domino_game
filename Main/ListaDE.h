#ifndef LISTADE_H 
#define LISTADE_H 
#include "ListaSEPedra.h"
#include <stdio.h>
#include<stdlib.h>

typedef struct tp_no_aux{
    struct tp_no_aux *ant;
    tp_itemM info;
    struct tp_no_aux *prox;
}tp_nod;

typedef struct{
  tp_nod *ini;
  tp_nod *fim;
}tp_listad;

tp_listad *inicializa_listad(){
  tp_listad *lista = (tp_listad *)malloc(sizeof(tp_listad));
  lista->ini = NULL;
  lista->fim = NULL;
  return lista;
}

int listad_vazia(tp_listad *lista){
  if(lista->ini == NULL) return 1;
  return 0;
}

tp_nod *aloca(){
  tp_nod *pt;
  pt = (tp_nod *)malloc(sizeof(tp_nod));
  return pt; 
}

int insere_listad_na_direita(tp_listad *lista, tp_itemM e){
  tp_nod *novo;
  novo=aloca();
  if(!novo) return 0;
  novo->info = e;
  novo->prox = NULL;
  if(listad_vazia(lista)) {
    novo->ant = NULL;
    lista->ini = lista->fim = novo;
  }
  else{
    novo->ant = lista->fim;
    lista->fim->prox = novo;
    lista->fim = novo;
  }
  return 1;
}

int insere_listad_na_esquerda(tp_listad *lista, tp_itemM e){
  tp_nod *novo;
  novo=aloca();
  if(!novo) return 0;
  novo->info = e;
  novo->prox = NULL;
  novo->ant = NULL;
  if(listad_vazia(lista)) {
    lista->ini = lista->fim = novo;
  }
  else{
    novo->prox = lista->ini;
    lista->ini = novo;
  }
  return 1;
}

void imprime_listad(tp_listad*lista, int ordem){
  if(lista==NULL) printf("Lista nao inicializada");
  if(listad_vazia(lista)) printf("Nao ha pecas na mesa!");
  tp_nod *atu;
  switch(ordem){
    case 1: atu = lista->ini;
            while(atu!=NULL){
              printf("%d|%d  ", atu->info.esquerda, atu->info.direita);
              atu=atu->prox;
            }
            break;
    case 2: atu = lista->fim;
            while(atu!=NULL){
              printf("%d|%d", atu->info.esquerda, atu->info.direita);
              atu = atu->ant;
            }        
            break;
    default: printf("codigo invalido");
  }
  printf("\n");
}

int checaSeDaPraJogarAPeca(tp_listad *lista, tp_itemM e){
  if(e.esquerda == lista->fim->info.direita){
    printf("peca inserida: %d|%d\n", e.esquerda, e.direita);
    insere_listad_na_direita(lista, e);
    return 1;
  }

  if(e.direita == lista->fim->info.direita){
    int aux;
    aux = e.esquerda;
    e.esquerda = e.direita;
    e.direita = aux;
    printf("peca inserida: %d|%d\n", e.esquerda, e.direita);
    insere_listad_na_direita(lista, e);
    return 1;
  }

  if(e.esquerda == lista->ini->info.esquerda){
    int aux;
    aux = e.esquerda;
    e.esquerda = e.direita;
    e.direita = aux;
    printf("peca inserida: %d|%d\n", e.esquerda, e.direita);
    insere_listad_na_esquerda(lista, e);
    return 1;
  }

  if(e.direita == lista->ini->info.esquerda){
    printf("peca inserida: %d|%d\n", e.esquerda, e.direita);
    insere_listad_na_esquerda(lista, e);
    return 1;
  }

  return 0;
}

#endif