 /*
Esse programa é responsável por simular um jogo de dominó,com 2 ou 4 jogarores em cada partida.
Desenvolvido por:
Fernando Schettini, Github: github.com/FernandoSchett 
Gabriel Souza Dunkel, Github: github.com/gabrielsdunkel
Orlando Mota Pires, Github: github.com/orlandomotapires 
Adrian Widmer, Github: github.com/Awi-24
Leonardo Trinchão, Github: github.com/leotrinchao 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h> 
#include <time.h>
#include <Windows.h>
#include "pilhaMonte.h" 

typedef struct{
	char name[100];
	int QntPecas;
	tp_listase *mao;
}tp_jogador;

void Pause(){
	system("pause");
	system("cls"); 
}

void MenuDoJogo(int *res){ //Função reponsável pelo menu inicial do jogo.
	printf("Bem-vindo ao MELHOR jogo de domino da AMERICA-LATINA e afiliados.\n");
	printf("Insira o numero 1 para jogar ou 0 para arregar :'(\n");
	scanf(" %d", res);
	Pause(); //Limpa o terminal.
}

void EscolheOsNomesDosJogadores(int numj, tp_jogador *jogadores){
	int i;
	for(i = 0; i < numj; i++){
	  printf("Digite o nome do jogador numero %d:\n", (i + 1));
		scanf(" %[^\n]s", jogadores[i].name);
	}
	Pause();
}

void startamonte(tp_itemM *monteInicial){ //Funcao que vai definir o valor de cada ladeo da peca dentor do vetor.
	 int numerodapeca=6, cont=0, contGeral=0;

	 while(numerodapeca > -1){	// Preenche a parte esquerda das pecas
 	 	while(cont < (numerodapeca + 1)){
 	 		monteInicial[contGeral].esquerda = numerodapeca;
	 		//printf("%d ", monteInicial[contGeral].esquerda);
 	 		contGeral ++;
 	 		cont ++;
 		}
 	 	cont = 0;
 	 	numerodapeca--;
	}
		printf("\n");
		contGeral = 0;
		cont = 7;
 		numerodapeca = 0;
	
	while(cont > 0){ // Preenche a parte direita das pecas.
	 	while(numerodapeca < cont){
 	 		monteInicial[contGeral].direita = numerodapeca;
	 		//printf("%d ", monteInicial[contGeral].direita);
	 		numerodapeca++;
	 		contGeral++;
	 	}
	 cont--;
	 numerodapeca = 0;
	 }
}

void sorteiaomonte(tp_itemM *monteInicial){ //Funcao que vai embaralhar as pecas dentro de um pilha.
	int peca, peca1, cont;
	tp_itemM aux;
		srand(time(NULL));
		for(int i = 0; i < 500; i++){
			peca = rand()%28;
			peca1 = rand()%28;
			aux = monteInicial[peca];
	 		monteInicial[peca] = monteInicial[peca1];
	 	 	monteInicial[peca1] = aux;
		}

	  // while(cont < 28){ // TESTA PRA VER SE O MONTE TA SENDO SORTEADO
	  // 	printf("%d ", monteInicial[cont].esquerda);
	  // 	cont++;
	  // }
	  // printf("\n");
	  // cont = 0;
	  // 	while(cont < 28){
	  // 	printf("%d ", monteInicial[cont].direita);
	  // 	cont++;
	  // }
}

// 👇👇👇👇 O problema começa aqui 👇👇👇👇
void distribuir_monte(tp_itemM *monteInicial, tp_pilhaM *monteTrue, tp_jogador *jogadores, int numj){ 
	tp_itemM e;
	inicializa_pilha(monteTrue);
	for(int i=0; i<numj; i++){
		jogadores[i].QntPecas = 0;
		jogadores[i].mao = inicializa_listase();
	}
	
	for(int i=0; i<28; i++){ //Tira as peças do vetor monteInicial e põe no monteTrue para serem usadas
		e = monteInicial[i];
		push(monteTrue, e);
	}
	
	for(int i=0; i<7; i++){
		for(int k = 0; k != numj; k++){
			pop(monteTrue, &e);
			printf("Peca retirada: %d|%d\n",e.esquerda, e.direita );  
			// 👇👇👇👇 O problema começa aqui 👇👇👇👇
			insere_listase_no_fim(&jogadores[k].mao, e);
		}
	}
	
	for(int k = 0; k != numj; k++){
		printf("Mao do jogador numero %d:", (k+1));
		imprime_listase(jogadores[k].mao);
		printf("\n");
	}

}

// void arrumaMao(tp_pilhaM **paux){
// 	tp_itemM vetAux[7], e;
// 	int c=0, n=7;
// 	while(!listase_vazia(paux)){
// 		retiraUltimoDaLista(paux, &e);
// 		vetAux[c] = e;
// 		c++;
// 	}
// 	for(int i= 1; i<n; i++){ //Uma simples função bubbleSort pra ordernar a pilha
// 		for(int k = 0; k<n-1; k++){
// 			if((vetAux[k].esquerda+vetAux[k].direita) > (vetAux[k+1].esquerda+vetAux[k+1].direita)){
// 			e = vetAux[k];
// 			vetAux[k] = vetAux[k+1];
// 			vetAux[k+1] = e;
// 			}
// 		}
// 	}	
// 	
// 	for(intc=0; c<7; c++){
// 		insere_listase_no_fim(paux, vetAux[c]);
// 	}
// }

int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese"); // Definindo a liguagem para português.
	int numj, choosen, res, cont=0; // Declarando as váriaveis.
	tp_itemM monteInicial[28]; // Iniciando o primeiro Monte
	tp_pilhaM monteTrue; // Iniciando a pilha que vai ser usada
	MenuDoJogo(&res); // Iniciando o menu jogo.
	if (res){	//Vai jogar.
		printf("Quantos jogadores vao jogar?\n");
		scanf(" %d", &numj);
		while(numj != 2 && numj != 4 ){
			printf("Valor inválido.\n");
			printf("Insira um valor válido, pode-se apenas jogar com 2 ou 4 jogadores:\n");
    	scanf(" %d", &numj);
		}
		tp_jogador jogadores[numj];
		EscolheOsNomesDosJogadores(numj, jogadores); // Escolhe os nomes dos jogadores
		printf("A ordem de jogo segue a ordem de quem colocou o nome primeiro:\n");
		for(int i=0; i<numj; i++){
			printf("%s", jogadores[i].name);
			if(i < (numj-1)) printf(" -> ");
		} 
		printf("\n");
		startamonte(monteInicial); // Inicia o monte com 28 peças
		sorteiaomonte(monteInicial); // Embaralhar o monte criado
		
	 	// 👇👇👇👇 O problema começa aqui 👇👇👇👇
		distribuir_monte(monteInicial, &monteTrue, jogadores, numj); // Distribui o monte para os jogadores 
	}
	else printf("Percebi que voce desistiu. FRACO!\n"); //Não vai jogar/Deistencia. 	

	return 0;           
}