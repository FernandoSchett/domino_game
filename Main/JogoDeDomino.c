/* Esse programa é responsável por simular um jogo de dominó,com 2 ou 4 jogarores em cada partida.
 Desenvolvido por:
 Fernando Schettini, Github: github.com/FernandoSchett 
 Gabriel Souza Dunkel, Github: github.com/gabrielsdunkel
 Orlando Mota Pires, Github: github.com/orlandomotapires 
 Adrian Widmer, Github: github.com/Awi-24
 Leonardo Trinchão, Github: github.com/leotrinchao */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h> 
#include <time.h>
#include <Windows.h>
#include "pilhaMonte.h"
#include "ListaSEncadeada.h" 

	typedef struct{
		char name[100];
		int QntPecas;
		tp_itemM mao[21];
	}tp_jogador;

void EscolheOrdemJogadores(int *escolhido, int numj, tp_jogador *j1, tp_jogador *j2, tp_jogador *j3, tp_jogador *j4){
	if(numj == 4){
		switch (*escolhido){
			case 1:
				printf ("Jogador %s comeca!\n", j1->name);
					printf ("A ordem do escolhido sempre segue no sentido crescente!\nPrimeiro -> %s \nSegundo -> %s \nTerceiro-> %s\nQuarto -> %s\n", j1->name, j2->name, j3->name, j4->name);	

				break;		
			case 2:
				printf ("Jogador %s comeca!\n", j2->name);
					printf ("A ordem do escolhido sempre segue no sentido crescente!\nPrimeiro -> %s \nSegundo -> %s \nTerceiro-> %s\nQuarto -> %s\n", j2->name, j3->name, j4->name, j1->name);	

				break;
			case 3:
				printf ("Jogador %s comeca!\n", j3->name);
					printf ("A ordem do escolhido sempre segue no sentido crescente!\nPrimeiro -> %s \nSegundo -> %s \nTerceiro-> %s\nQuarto -> %s\n", j3->name, j4->name, j1->name, j2->name);	

				break;	
			case 4:	
				printf ("Jogador %s comeca!\n", j4->name);	
					printf ("A ordem do escolhido sempre segue no sentido crescente!\nPrimeiro -> %s \nSegundo -> %s \nTerceiro-> %s\nQuarto -> %s\n", j4->name, j1->name, j2->name, j3->name);	

				break;
		}
	}	


	if(numj == 2){
		switch (*escolhido){
			case 1:
				printf ("Jogador %s comeca!\n", j1->name);
					printf ("A ordem do escolhido sempre segue no sentido crescente!\nPrimeiro -> %s \nSegundo -> %s \n", j1->name, j2->name);	

				break;		
			case 2:
				printf ("Jogador %s comeca!\n", j2->name);
					printf ("A ordem do escolhido sempre segue no sentido crescente!\nPrimeiro -> %s \nSegundo -> %s \n", j2->name, j1->name);	
		}
	}	

	system("pause");
	system("cls"); 
}

void Sorteador(int *possibilidade, int *escolhido){ //Esse funcao vai sortear com base no inteiro que recebeu.
	int random, nrandom;
	float chance;
	
	//srand(time (NULL)); //Generate seed for rand(),based in your pc time.
	//printf("Possibilidade: %d\n", *possibilidade);
	random = rand() % 100 ; //Generate random number in range 1-100.
	//printf("random: %d\n", random);
	chance = 100 / *possibilidade; //chance of getting any number.
	//printf("chance: %f \n", chance);

	nrandom = 0;
	*escolhido = 0;
	
	while(nrandom < random){ //Look for the range.
		nrandom = nrandom  + chance;
		//printf("escolhido: %d\n", *escolhido);
		//printf("nrandom: %d\n", random);
		*escolhido = *escolhido + 1;	
	}
	//printf("escolhido: %d\n", *escolhido);
}

void MenuDoJogo(int *res){ //Função reponsável pelo menu inicial do jogo.
 
	printf("Bem-vindo ao MELHOR jogo de dominó da AMERA-LATINA e afiliados.\n");
	printf("Insira o número 1 para jogar ou 0 para arregar :'(\n");
	scanf(" %d", res);
	//printf(" |%s| ", res);

	while((*res != 0) && (*res != 1) ){
		printf("Valor inválido.\n");
    	printf("Insira um valor válido, 1 para jogar ou 0 para arregar:\n");
		scanf(" %d", res);
    //	printf(" |%s|\n", res);
	}
	system("pause");
	system("cls"); //Limpa o terminal.
}

void EscolheOsNomesDosJogadores(int *numj, tp_jogador *j1, tp_jogador *j2, tp_jogador *j3, tp_jogador *j4){
	printf("Quantos jogadores vao jogar?\n");
	scanf(" %d", numj);
	
	while(*numj != 2 && *numj != 4 ){
		printf("Valor inválido.\n");
		printf("Insira um valor válido, pode-se apenas jogar com 2 ou 4 jogadores:\n");
    	scanf(" %d", numj);
	}
	
	if( *numj == 4){ //4 jogadores.
		//Recolhe o nome dos jogaores.
		printf("Nome do primeiro jogador:\n");
		scanf(" %[^\n]s", j1->name);
		printf("Nome do segundo jogador:\n");
		scanf(" %[^\n]s", j2->name);
		printf("Nome do terceiro jogador:\n");
		scanf(" %[^\n]s", j3->name);
		printf("Nome do quarto jogador:\n");
		scanf(" %[^\n]s", j4->name);
		
		system("pause");
		system("cls"); //Limpa o terminal.
		
		//Apresenta os jogadores.
		printf("Os melhores jogadores de dominó tem nome!\n");
		printf("Jogador número 1: %s\n", j1->name);
		printf("Jogador número 2: %s\n", j2->name);
		printf("Jogador número 3: %s\n", j3->name);
		printf("Jogador número 4: %s\n", j4->name);
	}
	
	if(*numj == 2){ //2 jogadores.
		//Recolhe o nome dos jogaores.
		printf("Nome do primeiro jogador:\n");
		scanf(" %[^\n]s", j1->name);
		printf("Nome do segundo jogador:\n");
		scanf(" %[^\n]s", j2->name);
		
		system("pause");
		system("cls"); //Limpa o terminal.
		
		//Apresenta os jogadores.
		printf("Os melhores jogadores de dominó tem nome!\n");
		printf("Jogador número 1: %s \n", j1->name);
		printf("Jogador número 2: %s \n", j2->name);	
	}
	system("pause");
	system("cls"); 
}

void startamonte(tp_itemM *monteInicial){ //Funcao que vai definir o valor de cada ladeo da peca dentor do vetor.
	 int numerodapeca=6, cont=0, contGeral=0;

	 while(numerodapeca > -1){	// Preenche a parte esquerda das pecas
 	 	while(cont < (numerodapeca + 1)){
 	 		monteInicial[contGeral].esquerda = numerodapeca;
	 		//printf("%d ", monte[contGeral].esquerda);
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
	 		//printf("%d ", monte[contGeral].direita);
	 		numerodapeca++;
	 		contGeral++;
	 	}
	 cont--;
	 numerodapeca = 0;
	 }

}

void sorteiaomonte(tp_itemM *monteInicial){ //Funcao que vai embaralhar as pecas dentro de um pilha.
	int peca, peca1, cont=0;
	tp_itemM aux;
		srand(time(NULL));
		for(int i = 0; i < 500; i++){
			peca = rand()%28;
			peca1 = rand()%28;
			aux = monteInicial[peca];
	 		monteInicial[peca] =monteInicial[peca1];
	 	 	monteInicial[peca1] = aux;
		}

	  while(cont < 28){ // TESTA PRA VER SE O MONTE TA SENDO SORTEADO
	  	printf("%d ", monteInicial[cont].esquerda);
	  	cont++;
	  }
	  printf("\n");
	  cont = 0;
	  	while(cont < 28){
	  	printf("%d ", monteInicial[cont].direita);
	  	cont++;
	  }
}

void distribuir_monte(tp_itemM *monteInicial, tp_pilhaM *monteTrue, tp_jogador *j1, tp_jogador *j2, tp_jogador *j3, tp_jogador *j4, int numj){
	int cont=0, i=0, j=0, g, s;
	tp_itemM e, k;
	j1->QntPecas = 0;
	j2->QntPecas = 0;
	j3->QntPecas = 0;
	j4->QntPecas = 0;

	// cont=0;
	// while(cont<28){
	// g = monteInicial[cont].esquerda;
	// s = monteInicial[cont].direita;
	// printf("%d %d", g, s);
	// cont++;
	// }

	while(cont<28){
		k = monteInicial[cont];
		push(monteTrue, k);
		cont++;
	}

	// cont=0;
	// while(cont<28){
	// 	g = monteTrue->item[cont].esquerda;
	// 	s = monteTrue->item[cont].direita;
	// 	printf("%d %d \n", g, s);
	// 	cont++;
	// }

	

	cont=0;
	if(numj == 4){
		while(cont<7){
			pop(monteTrue, &e);
			j1->mao[j] = e;
			j1->QntPecas++;
			i++;
			pop(monteTrue, &e);
			j2->mao[j] = e;
			j2->QntPecas++;
			i++;
			pop(monteTrue, &e);
			j3->mao[j] = e;
			j3->QntPecas++;
			i++;
			pop(monteTrue, &e);
			j4->mao[j] = e;
			j4->QntPecas++;
			i++;
			j++;
			cont++;
		}
	}	

	if(numj == 2){
		while(cont<7){
			pop(monteTrue, &e);
			j1->mao[j] = e;
			j1->QntPecas++;
			i++;
			pop(monteTrue, &e);
			j2->mao[j] = e;
			j2->QntPecas++;
			i++;
			j++;
			cont++;
		}
	}

	// cont=0;
	// if(numj==2){ // MOSTRA AS PEÇAS PRA VER SE TA CERTO
	// 	char nome1[100], nome2[100];
	// 	printf("Nome jogador 1: %s\n", j1->name);
	// 	printf("Quantidade de pecas jogador 1: %d\n", j1->QntPecas);
	// 	while(cont<7){
	// 		printf("%d ", j1->mao[cont].esquerda);
	// 		printf("%d ", j1->mao[cont].direita);
	// 		cont++;
	// 	}

	// 	printf("\n");
	
	// 	cont=0;
	// 	printf("Nome jogador 2: %s\n", j2->name);
	// 	printf("Quantidade de pecas jogador 2: %d\n", j2->QntPecas);
	// 	while(cont<7){
	// 		printf("%d ", j2->mao[cont].esquerda);
	// 		printf("%d ", j2->mao[cont].direita);
	// 		cont++;
	// 	}

	// 	printf("\n");

	// }

	// cont=0;
	// if(numj==4){ // MOSTRA AS PEÇAS PRA VER SE TA CERTO
	// 	char nome1[100], nome2[100], nome3[100], nome4[100];
	// 	printf("Nome jogador 1: %s\n", j1->name);
	// 	printf("Quantidade de pecas jogador 1: %d\n", j1->QntPecas);
	// 	while(cont<7){
	// 		printf("%d ", j1->mao[cont].esquerda);
	// 		printf("%d ", j1->mao[cont].direita);
	// 		cont++;
	// 	}

	// 	printf("\n");

	// 	cont=0;
	// 	printf("Nome jogador 2: %s\n", j2->name);
	// 	printf("Quantidade de pecas jogador 2: %d\n", j2->QntPecas);
	// 	while(cont<7){
	// 		printf("%d ", j2->mao[cont].esquerda);
	// 		printf("%d ", j2->mao[cont].direita);
	// 		cont++;
	// 	}

	// 	printf("\n");

	// 	cont=0;
	// 	printf("Nome jogador 3: %s\n", j3->name);
	// 	printf("Quantidade de pecas jogador 3: %d\n", j3->QntPecas);
	// 	while(cont<7){
	// 		printf("%d ", j3->mao[cont].esquerda);
	// 		printf("%d ", j3->mao[cont].direita);
	// 		cont++;
	// 	}

	// 	printf("\n");

	// 	cont=0;
	// 	printf("Nome jogador 4: %s\n", j4->name);
	// 	printf("Quantidade de pecas jogador 4: %d\n", j4->QntPecas);
	// 	while(cont<7){
	// 		printf("%d ", j4->mao[cont].esquerda);
	// 		printf("%d ", j4->mao[cont].direita);
	// 		cont++;
	// 	}	
	// }
}

int main(){
	setlocale(LC_ALL, "Portuguese"); // Definindo a liguagem para português.
	int numj, choosen, res; // Declarando as váriaveis.
	tp_jogador j1, j2, j3, j4; // Iniciando os jogadores
	tp_itemM monteInicial; // Iniciando o primeiro Monte
	tp_pilhaM monteTrue; // Iniciando a pilha que vai ser usada
	MenuDoJogo(&res); // Iniciando o menu jogo.
	
	if (res){	//Vai jogar.
		EscolheOsNomesDosJogadores(&numj, &j1, &j2, &j3, &j4); // Escolhe os nomes dos jogadores
		Sorteador(&numj, &choosen); // Sorteia quem comeca.
		EscolheOrdemJogadores(&choosen, numj, &j1, &j2, &j3, &j4); // 
		startamonte(&monteInicial); // Inicia o monte com 28 peças
		sorteiaomonte(&monteInicial); // Embaralhar o monte criado
		distribuir_monte(&monteInicial, &monteTrue, &j1, &j2, &j3, &j4, numj); // Distribui o monte para os jogadores 
	}
	else printf("Percebi que voce desistiu. FRACO!\n"); //Não vai jogar/Deistencia. 	
	
	return 0;           
}