#ifndef PILHAmonte_H    //boa pratica, nome da biblioteca_h
#define PILHAmonte_H
#define MAX 28          //td arquivo .h n pode ter main
#include <stdio.h>
#include "ListaSEPedra.h"

//tad - tipo abstrato de dado
// 0 é falso e qq coisa != 0 é vdd

typedef struct { //A struct da pilha
    int topo;  //guarda a posição do vetor onde está o elemento do topo
    tp_itemM item[MAX];  //vetor de max elementos (100)
} tp_pilhaM;

void inicializa_pilha(tp_pilhaM *p){ //Funcao para inicializar a pilha
    p -> topo = -1;
}

int pilha_vazia(tp_pilhaM *p){ //Funcao para detectar se a pilha esta vazia
    if (p-> topo == -1)
        return 1;
    return 0;
}

int pilha_cheia(tp_pilhaM *p){ //Funcao para detectar se a pilha esta cheia
    if (p->topo == MAX-1){
        return 1;
    } else{
        return 0;
    }
}

int push(tp_pilhaM *p, tp_itemM e){ //Funcao para colocar uma peca na pilha
    if (pilha_cheia(p)==1) return 0; // da falha
    p -> topo++; //aumenta  a posição ja q n pd inser4ir na posição -1 e n sobrescrever o resto
    p -> item[p->topo] = e; //insere conteudo da variavel e
    return 1;
}

int pop(tp_pilhaM *p, tp_itemM *e){ //Funcao para tirar uma peca da pilha
    if (pilha_vazia(p)) return 0; //falha
    *e = p->item[p->topo];
    p -> topo--;
    return 1;
}

void imprime_pilha(tp_pilhaM  p){ //Funcao para imprimir a pilha de pecas
    tp_itemM e;
    int g, k;
    while(!pilha_vazia(&p)){
        pop(&p, &e);
        g = e.direita;
        k = e.esquerda;
        printf("%d|%d ", k, g);
    }
    printf("\n");
}

#endif   //fim da biblioteca pilha.h