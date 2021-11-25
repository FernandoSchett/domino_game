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
#include "listaDE.h"

typedef struct{ //Struct de tudo relacionado ao jogador
	char name[100];
	int QntPecas;
	tp_listase *mao;
}tp_jogador;

void Pause(){ // Pause e cleanse :)
	system("pause");
	system("cls"); 
}

void MenuDoJogo(int *res){ //Função reponsável pelo menu inicial do jogo.
	printf("Bem-vindo ao MELHOR jogo de domino da AMERICA-LATINA e afiliados.\n");
	printf("Insira o numero 1 para jogar ou 0 para arregar :'(\n");
	scanf(" %d", res);
	Pause(); //Limpa o terminal.
}

void EscolheOsNomesDosJogadores(int numj, tp_jogador *jogadores){ //Funcao para escolher os nomes do jogadores
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
	int peca, peca1;
	tp_itemM aux;
		for(int i = 0; i < 500; i++){
			peca = rand()%28;
			peca1 = rand()%28;
			aux = monteInicial[peca];
	 		monteInicial[peca] = monteInicial[peca1];
	 	 	monteInicial[peca1] = aux;
		}
}

void arrumaMao(tp_listase **paux, int QntPecas){ //Funcao para arrumar a mao do jogador
	tp_itemM vetAux[QntPecas], e;
	int c = 0, n = QntPecas;

	while(c < QntPecas){
		retiraUltimoDaLista(paux, &e);
		vetAux[c] = e;
		c++;
	}

	for(int c= 1; c<n; c++){ //Uma simples função bubbleSort pra ordernar a pilha
		for(int k = 0; k<n-1; k++){
			if((vetAux[k].esquerda+vetAux[k].direita) > (vetAux[k+1].esquerda+vetAux[k+1].direita)){
			e = vetAux[k];
			vetAux[k] = vetAux[k+1];
			vetAux[k+1] = e;
			}
		}
	}	
	
	*paux = inicializa_listase();
	
	for(c = 0; c < QntPecas; c++){
		insere_listase_no_fim(paux, vetAux[c]);	
	}
}

void infoJogadores(tp_jogador *jogadores, int numj){ //Funcao para printar tudo sobre a mao do jogador, utilizada para testes
	for(int k = 0; k != numj; k++){ //Imprime a lista para ver se ta certo
			printf("Nome do jogador numero %d: %s\n", k+1, jogadores[k].name);
			printf("Quantidade de pecas: %d\n", jogadores[k].QntPecas);
			printf("Mao do jogador numero %d:\n", (k+1));
			imprime_listase(jogadores[k].mao);
			printf("\n");
	}

}

void maoJogador(tp_listase *mao){
	printf("Mao:\n");
	imprime_listase(mao);
	printf("\n");
}

void distribuir_monte(tp_itemM *monteInicial, tp_pilhaM *monteTrue, tp_jogador *jogadores, int numj, int *comecador){ //Funcao para distribuir o monte
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
		for(int k = 0; k < numj; k++){
			pop(monteTrue, &e);
			if(e.esquerda == 6 && e.direita ==6){
				 *comecador = k;
			}
			insere_listase_no_fim(&jogadores[k].mao, e);
			jogadores[k].QntPecas++;
		}
	}

}

void lendoNumj(int *numj){ //Funcao lendo quantos jogadores vao jogar
	printf("Quantos jogadores vao jogar?\n");
		scanf(" %d", numj);
		while(*numj != 2 && *numj != 4 ){
			printf("Valor inválido.\n");
			printf("Insira um valor válido, pode-se apenas jogar com 2 ou 4 jogadores:\n");
    	scanf(" %d", numj);
		}
}

void arrumaMaoDeTodos(tp_jogador *jogadores, int numj){
	for(int i=0; i<numj; i++){
		arrumaMao(&jogadores[i].mao, jogadores[i].QntPecas);
	}
}

int checaQuantidade(tp_jogador *jogadores, int numj, char *vencedor){
	for(int i=0; i<numj; i++){ 
		if(jogadores[i].QntPecas==0){ 
			vencedor = jogadores[i].name; 
			return 0;
		}
	}
	return 1;
}

int checaSeDaPraJogarAPeca(tp_listad *pecasNaMesa, tp_itemM e){
	
	return 1;
}

void jogo(tp_jogador *jogadores, int numj, tp_pilhaM *monteTrue, int comecador){
	tp_itemM e;
	tp_listad *pecasNaMesa;
	int check=1, pos, possivel;
	char vencedor[100], acao, lado;
	
	while(check){
		for(int i=0; i<numj; i++){ //precisa de uma outra logica por causa do comecador
			printf("Vez do jogador: %d", jogadores[i].name);
			arrumaMao(&jogadores[i].mao, jogadores[i].QntPecas);
			maoJogador(jogadores[i].mao);
			
			printf("\nO que gostaria de fazer? Cavar ou jogar: [C/J]\n");
			scanf(" %s", acao);
			while((acao != 'c') && (acao != 'j')){
				printf("Entrada invalida! Atencao as entradas permitidas!!!");
				printf("\nO que gostaria de fazer? Cavar ou jogar: [C/J]\n");
				scanf(" %s", acao);
			}

			if(acao == 'c'){
				pop(monteTrue, &e);
				insere_listase_no_fim(&jogadores[i].mao, e);
				jogadores[i].QntPecas++;
			}

			if(acao == 'j'){
				printf("Posicao da peca que gostaria de jogar: \n");
				scanf(" %d", pos);
				printf("Onde gostaria de jogar a peca, esquerda ou direita: [E/D]\n");
				scanf(" %s", lado);
				jogaAPecaPelaPosicao(&jogadores[i].mao, &e, pos);
				possivel = checaSeDaPraJogarAPeca(pecasNaMesa, e);
				if(possivel == 1){
				if(lado=='e') insere_listad_na_esquerda(pecasNaMesa, e);
				if(lado=='d') insere_listad_na_direita(pecasNaMesa, e);
				jogadores[i].QntPecas--;
				}
			}		
		}
		
	  check = checaQuantidade(jogadores, numj, vencedor);
	}
}

int main(){ //Sus
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese"); // Definindo a liguagem para português.
	int numj, res, comecador; // Declarando as váriaveis.
	tp_itemM monteInicial[28]; // Iniciando o primeiro Monte
	tp_pilhaM monteTrue; // Iniciando a pilha que vai ser usada
	MenuDoJogo(&res); // Iniciando o menu jogo.
	if (res){	//Vai jogar.
		lendoNumj(&numj);
		tp_jogador jogadores[numj];
		EscolheOsNomesDosJogadores(numj, jogadores); // Escolhe os nomes dos jogadores
		startamonte(monteInicial); // Inicia o monte com 28 peças
		sorteiaomonte(monteInicial); // Embaralhar o monte criado
		distribuir_monte(monteInicial, &monteTrue, jogadores, numj, &comecador); // Distribui o monte para os jogadores 
		arrumaMaoDeTodos(jogadores, numj);
		infoJogadores(jogadores, numj);	
		//jogo(jogadores, numj, &monteTrue, &comecador);
}
	else printf("Percebi que voce desistiu. FRACO!\n"); //Não vai jogar/Deistencia. 	

	return 0;           
}