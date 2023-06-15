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

void maoJogador(tp_listase *mao){ //Funcao que serve para imprimir a mao do jogador
	imprime_listase(mao);
	printf("\n");
}

void distribuir_monte(tp_itemM *monteInicial, tp_pilhaM *monteTrue, tp_jogador *jogadores, int numj, int *comecador){ //Funcao para distribuir o monte
	tp_itemM e;
	inicializa_pilha(monteTrue);
	
	for(int i=0; i<numj; i++){ //Inicializa a quantidade pecas e as maos de todos os jogadores
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
			if(e.esquerda == 6 && e.direita ==6){ //Ve quem vai comecar
				 *comecador = k;
			}

			insere_listase_no_fim(&jogadores[k].mao, e);
			jogadores[k].QntPecas++;
		}
	}

	int k, g=0;
	tp_itemM buxa;
	buxa.esquerda = 6;
	buxa.direita = 6;
	
	if(numj == 2){ //Logica para detectar se quando tiver 2 jogadores, algum deles pegou a peca 6\6
		for(int i = 0; i < numj; i++){
		k = busca_listase(jogadores[i].mao, buxa);
		g=k+g;
		}
		if(!g) *comecador=0;
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

void arrumaMaoDeTodos(tp_jogador *jogadores, int numj){ //Funcao para arrumar a mao de todos os jogadores
	for(int i=0; i<numj; i++){
		arrumaMao(&jogadores[i].mao, jogadores[i].QntPecas);
	}
}

int checaQuantidade(tp_jogador *jogadores, int numj, char *vencedor){ //Funcao para checar se alguem venceu
	for(int i=0; i<numj; i++){ 
		if(jogadores[i].QntPecas==0){ 
			strcpy(vencedor, jogadores[i].name); 
			return 0;
			printf("Vencedor dentro da funcao: %s", vencedor);
		}
	}
	return 1;
}

void mostraPecasNaMesa(tp_listad *p, int i){ //Funcao para ver as pecas que estao sendo jogadas na mesa
	imprime_listad(p, i);
}

void retiraDaPilhaABuxaEJoga(tp_pilhaM *monteTrue){ //Funcao para tirar a buxa da pilha e jogar
	tp_itemM e;
	tp_pilhaM paux; //Uma pilha auxiliar
	inicializa_pilha(&paux); //Inicializando a pilha auxiliar
	while(!pilha_vazia(monteTrue)){ //Tira as pecas do monte e coloca em uma pilha auxiliar
		pop(monteTrue, &e);
		if((e.esquerda!=6) || (e.direita!=6)){ //Logica para tirar a peca 6\6 do monte
			push(&paux, e);
		}
	}

	while(!pilha_vazia(&paux)){ //Devolve as pecas para o monte sem a peca 6\6
		pop(&paux, &e);
		push(monteTrue, e);
	}

}

void jogo(tp_jogador *jogadores, int numj, tp_pilhaM *monteTrue, int comecador){//Funcao com todo a logica do jogo
	tp_itemM e, buxa; //Peca buxa
	int check=1, pos, possivelJogar, possivelCavar, vez, acaoCompleta, jogaBuxa, locbuxa=0, u=1, i; //Variaveis usadas para a logica
	char vencedor[100], acao; //Vencedor usada para receber o nome do ganhador e a acao eh usada para ler a acao do jogador
	tp_listad *pecasNaMesa; //Lista duplamente encadeada com as pecas na mesa

	buxa.esquerda = 6; //Atribuindo 6 na esquerda da peca
	buxa.direita = 6; //Atribuindo 6 na direta da peca
	
	pecasNaMesa = inicializa_listad(); //Inicializando as pecas na mesa
	printf("\nAGORA COMECA O JOGO DE DOMINO. BOA SORTE!\n"); //Comeco do jogo
	
	while(check){ //Laco  para checar se alguem venceu
		
		for(i=comecador; i<numj; i++){ //Laço que vai correr todos os jogadores
			vez = possivelJogar = possivelCavar = acaoCompleta = 0;
			Pause();//Pausa e da clean no console
			
			while(!acaoCompleta){ //Laco que vai detectar se a acao do jogador foi completada
				arrumaMao(&jogadores[i].mao, jogadores[i].QntPecas); //Arruma a mao do jogador

				if(!vez){ //Laco feito para ser executado so na primeira vez na rodada de cada jogador
					if(numj==2 && u==1){ //Laco para detectar se alguem tem a peca 6\6
						
						for(int i=0; i<numj; i++){//Laco para correr todos os jogadores
							locbuxa  = busca_listase(jogadores[i].mao, buxa)+locbuxa ; //Buscando para ver se tem a peca 6\6 na mao de algum jogador
						 	//Logica para detectar se encontrou alguma peca 6\6
						}	

						if(!locbuxa){ //Laco caso ninguem tenha a peca 2
							printf("Como nenhum dos dois jogadores possui a buxa, ela foi jogada automaticamente!\n");
							retiraDaPilhaABuxaEJoga(monteTrue);//Funcao para tirar a peca 6\6 do monte
							insere_listad_na_esquerda(pecasNaMesa, buxa); // Funcao para inserir a peca na esquerda
							acaoCompleta=1; //Acao completa, sai do loop
						}
					
					}

					u=0;			
					printf("Vez do jogador: %s\n", jogadores[i].name);
					jogaBuxa = busca_listase(jogadores[i].mao, buxa); //Funcao para encontrar se alguem tem a buxa
				
					if(jogaBuxa) { //Funcao para fazer o jogador jogar a buxa obrigatoriamente
						printf("Como voce tinha a peca 6|6 voce comecou jogando ela na mesa\n");
						retiraUltimoDaLista(&jogadores[i].mao, &e);	//Funcao para jogar a peca 6\6
						printf("Peca inserida: %d|%d\n", e.esquerda, e.direita);			
						insere_listad_na_direita(pecasNaMesa, e); //Colocando a peca 6\6 na mesa
						acaoCompleta=1; //Completando a acao
						jogadores[i].QntPecas--; //Diminuindo a quantidade de pecas do jogador					

					}

					maoJogador(jogadores[i].mao); //Mostra a mao do jogador
					printf("Pecas na mesa: ");
					mostraPecasNaMesa(pecasNaMesa, 1); //Mostra as pecas que estao na mesa
				}		
				vez++;
				
				if(!jogaBuxa){ //Funcao feita para ser executada caso o nao tenha sido jogada a buxa nessa rodada
					printf("O que gostaria de fazer? Cavar, jogar ou passar: [C/J/P]\n"); 
					scanf(" %c", &acao); //O jogador escolhe a acao que ele quer fazer 
					while((acao != 'c') && (acao != 'j') && (acao != 'p')){ //Funcao para ver se o jogador escolheu uma entrada certa
						printf("Entrada invalida! Atencao as entradas permitidas!!!");
						printf("\nO que gostaria de fazer? Cavar, jogar ou passar: [C/J/P]\n");
						scanf(" %c", &acao); //Le a acao do jogador
					}
				}	
				
				if(acao == 'c'){ //Funcao caso o jogador tenha escolhido cavar
					possivelCavar = pop(monteTrue, &e);
					if(possivelCavar){ //Se foi possivel cavar executa essa condicao
						acaoCompleta = 1; //Completando uma acao
						insere_listase_no_fim(&jogadores[i].mao, e); //Coloca a peca cavada na mao do jogador
						printf("\nVoce escolheu cavar, recebendo a peca: %d|%d\n", e.esquerda, e.direita);
						maoJogador(jogadores[i].mao); //Mostra a mao do jogador
						jogadores[i].QntPecas++; //Aumenta a quantidade de pecas do jogador
					}else{ // Caso nao seja possivel cavar
						printf("\nNao foi possivel cavar, o cava esta vazio. Talvez voce possua uma peca para jogar!\n");
					}
				}

				if(acao == 'j'){ //Caso o jogador tenha escolhido jogar
					printf("Posicao da peca que gostaria de jogar: \n");
					scanf(" %d", &pos);	//Le a posicao da peca que ele deseja jogar
					while(pos>jogadores[i].QntPecas){ //Laco para detectar se o jogador esta escolhendo uma posicao valida
						printf("Insira um posicao valida!\n");
						printf("Posicao da peca que gostaria de jogar: \n");
						scanf(" %d", &pos);	

					}
					jogaAPecaPelaPosicao(&jogadores[i].mao, &e, pos);//Tirando a peca da mao do jogador
					printf("Voce escolheu jogar a peca: %d|%d\n", e.esquerda, e.direita);
					possivelJogar = checaSeDaPraJogarAPeca(pecasNaMesa, e); //Detectando se for possivel jogar, caso positivo a peca eh inserida na mesa
					if(possivelJogar){//Caso seja possivel jogar 
						 jogadores[i].QntPecas--; //Diminuindo a quantidade de pecas do jogador
						 acaoCompleta = 1; //Completando uma acao
					}	else if(!possivelJogar){ //Caso nao seja possivel cavar
						insere_listase_no_fim(&jogadores[i].mao, e); //Devolve a peca a mao do jogador
						arrumaMao(&jogadores[i].mao, jogadores[i].QntPecas); //Arruma a mao do jogador
						printf("Sua pedra nao pode ser jogada, chece os valores presentes nela!\n");
						acaoCompleta = 0; //Acao nao foi completa, continuando no loop
					}
				}

				if(acao == 'p'){ //Caso o jogador tenha escolhido passar
					acaoCompleta = 1; //Acao completa
				}
			}
		}

		check = checaQuantidade(jogadores, numj, vencedor);	//Checa a quantidade de pecas de cada jogador para ver se alguem venceu
		comecador=0; //Logica para resetar o comecador e pasasr por todos os jogadores
	}

	Pause();	//Momento que eh dectado que algum jogador venceu, sendo o jogo finalizado
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("Jogador vencedor: %s", vencedor);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

int main(){ //Funcao main do codigo

	srand(time(NULL)); //Setando a semente de geracao de aleatoriedade para NULL
	setlocale(LC_ALL, "Portuguese"); // Definindo a liguagem para português.
	int numj, res, comecador; // Declarando as váriaveis.
	tp_itemM monteInicial[28]; // Iniciando o primeiro Monte
	tp_pilhaM monteTrue; // Iniciando a pilha que vai ser usada
	MenuDoJogo(&res); // Iniciando o menu jogo.

	if (res){	//Vai jogar.
		lendoNumj(&numj); //Lendo a quantidade de jogadores que vao jogar
		tp_jogador jogadores[numj]; //Vetor com todos os jogadores 
		EscolheOsNomesDosJogadores(numj, jogadores); // Escolhe os nomes dos jogadores
		startamonte(monteInicial); // Inicia o monte com 28 peças
		sorteiaomonte(monteInicial); // Embaralhar o monte criado
		distribuir_monte(monteInicial, &monteTrue, jogadores, numj, &comecador); // Distribui o monte para os jogadores 
		arrumaMaoDeTodos(jogadores, numj);//Arrumar a mao de todos os jogadores
		// infoJogadores(jogadores, numj);	//Mostra a mao de todos os jogadores
		jogo(jogadores, numj, &monteTrue, comecador); //O momento de jogar o jogo efetivamente começa aqui
	}
	else{ 
		printf("Percebi que voce desistiu. FRACO!\n"); //Não vai jogar/deistência. 	
	}
	return 0;           
}