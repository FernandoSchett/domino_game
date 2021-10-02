#ifndef PILHA_H    //boa pratica, nome da biblioteca_h
#define PILHA_H
//td arquivo .h n pode ter main
#include <stdio.h>
#define MAX 100

//tad - tipo abstrato de dado
// 0 é falso e qq coisa != 0 é vdd
typedef int
    tp_item;

typedef struct{
    int topo;  //guarda a posição do vetor onde está o elemento do topo
    tp_item item[MAX];  //vetor de max elementos (100)
} tp_pilha;

void inicializa_pilha(tp_pilha *p){
    p -> topo = -1;
}

int pilha_vazia(tp_pilha *p){
    if (p-> topo == -1)
        return 1;
    return 0;
}

int pilha_cheia(tp_pilha *p){
    if (p->topo == MAX-1){
        return 1;
    } else{
        return 0;
    }
}

int push(tp_pilha *p, tp_item e){
    if (pilha_cheia(p)==1) return 0; // da falha
    p -> topo++; //aumenta  a posição ja q n pd inserir na posição -1 e n sobrescrever o resto
    p -> item[p->topo] = e; //insere conteudo da variavel e
    return 1;
}

//smp q tiver pop tem q ter uma var aux
int pop(tp_pilha *p, tp_item *e){
    if (pilha_vazia(p)) return 0; //falha
    *e = p-> item[p->topo];
    p -> topo--;
    return 1;
}

int top(tp_pilha *p, tp_item *e) {
    if (pilha_vazia(p)) return 0; //falha
    *e = p-> item[p->topo];
    return 1;
}

//n pode ser ponteiro pq senão no final a pilha vai ficar vazia, logo tem q ser copia
void imprime_pilha(tp_pilha p){
    tp_item e;
    printf("\n");
    while(!pilha_vazia(&p)){
        pop(&p, &e);
        printf("%d ", e);
    }
}

int altura_pilha(tp_pilha *p){
    return p->topo+1;
}

void retira_impares(tp_pilha *p){  // tem q ser ponteiro tipo um atalho de um arquivo do pc
    tp_pilha paux;
    inicializa_pilha(&paux);
    tp_item e;
    // desempilha a pilha original e armazena apenas os pares na pilha auxiliar
    while(!pilha_vazia(p)){
        pop(p, &e);
        if(e%2==0) // se par
        push(&paux,e);
    } //fim while pop

    while(!pilha_vazia(&paux)){
        pop(&paux, &e);
        push(p, e);
    } //fim do empilhamento pra pilha anterior
} //fim func

void retira_pares(tp_pilha *p){  // tem q ser ponteiro tipo um atalho de um arquivo do pc
    tp_pilha paux;
    inicializa_pilha(&paux);
    tp_item e;
    // desempilha a pilha original e armazena apenas os impares na pilha auxiliar
    while(!pilha_vazia(p)){
        pop(p, &e);
        if(e%2!=0) // se impar
        push(&paux,e);
    } //fim while pop

    while(!pilha_vazia(&paux)){
        pop(&paux, &e);
        push(p, e);
    } //fim do empilhamento pra pilha anterior
} //fim func

int pilhas_iguais(tp_pilha pilha1, tp_pilha pilha2){
    tp_item e1, e2;
    if (altura_pilha(&pilha1) != altura_pilha(&pilha2)) //se o tamanho for dif as pilhas ja são dif. ent acaba ai
        return 0;
    while(!pilha_vazia(&pilha1)){
        pop(&pilha1, &e1);
        pop(&pilha2, &e2);
        if(e1 != e2)  // compara os elementos de p1 e p2
            return 0;
        }
    return 1;
}

int empilha_pilha (tp_pilha *pilha1, tp_pilha *pilha2){
    tp_pilha paux;
    tp_item e;
    inicializa_pilha(&paux);
    if (altura_pilha(pilha1) + altura_pilha(pilha2) > MAX){
        return 0; //pra n estourar o limite da pilha 1 ---> FALHA
    }
    while(!pilha_vazia(pilha2)){
        pop(pilha2, &e);
        push(&paux,e);
    }
    while(!pilha_vazia(&paux)){
        pop(&paux, &e);
        push(pilha1,e);
    }
    return 1; //SUCESSO
}

#endif   //fim da biblioteca pilha.h