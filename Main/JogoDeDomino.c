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
#include "ListaSEPedra.h" 

	typedef struct{
		char name[100];
		int QntPecas;
		tp_listase *mao;
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
	int peca, peca1;
	tp_itemM aux;
		srand(time(NULL));
		for(int i = 0; i < 500; i++){
			peca = rand()%28;
			peca1 = rand()%28;
			aux = monteInicial[peca];
	 		monteInicial[peca] =monteInicial[peca1];
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

void distribuir_monte(tp_itemM *monteInicial, tp_pilhaM *monteTrue, tp_jogador *j1, tp_jogador *j2, tp_jogador *j3, tp_jogador *j4, int numj){
	int cont=0, i=0, j=0, g, s;
	tp_itemM e, k;
	j1->QntPecas = 0;
	j2->QntPecas = 0;
	j3->QntPecas = 0;
	j4->QntPecas = 0;
	
	j1->mao = inicializa_listase(); 
	j2->mao = inicializa_listase();
	j3->mao = inicializa_listase();
	j4->mao = inicializa_listase();
 
	// while(cont<28){ //CHECA para ver se as peças estão certas
	// g = monteInicial[cont].esquerda;
	// s = monteInicial[cont].direita;
	// printf("%d %d\n", g, s);
	// cont++;
	// }

	while(cont<28){ //Tira as peças do vetor monteInicial e põe no monteTrue para serem usadas
		k = monteInicial[cont];
		push(monteTrue, k);
		cont++;
	}

	if(numj == 4){ //Adiciona as peças as mãos dos 4 jogadores
		cont=0;
		while(cont<7){
			pop(monteTrue, &e);
			printf("Teste 1");
			insere_listase_no_fim(j1->mao, e);
			printf("Teste 2");
			j1->QntPecas++;
			i++;
			pop(monteTrue, &e);
			insere_listase_no_fim(j2->mao, e);
			j2->QntPecas++;
			i++;
			pop(monteTrue, &e);
			insere_listase_no_fim(j3->mao, e);
			j3->QntPecas++;
			i++;
			pop(monteTrue, &e);
			insere_listase_no_fim(j4->mao, e);
			j4->QntPecas++;
			i++;
			j++;
			cont++;
		}

		arrumaMao(j1->mao);
		arrumaMao(j2->mao);
		arrumaMao(j3->mao);
		arrumaMao(j4->mao);
	}	

	if(numj == 2){ //Adiciona as peças as mãos dos 2 jogadores
		cont=0;
		while(cont<7){
			pop(monteTrue, &e);
			insere_listase_no_fim(j1->mao, e);
			j1->QntPecas++;
			i++;
			pop(monteTrue, &e);
			insere_listase_no_fim(j2->mao, e);
			j2->QntPecas++;
			i++;
			j++;
			cont++;
		}

	arrumaMao(j1->mao); //Arruma as mãos dos jogadores 
	arrumaMao(j2->mao); //Arruma as mãos dos jogadores	
	}

	// if(numj==2){ //CHECA as peças na mão do jogadores para ver se está certo (2 jogadores)  
	// 	printf("Nome jogador 1: %s\n", j1->name);
	// 	printf("Quantidade de pecas jogador 1: %d\n", j1->QntPecas);	
	// 	imprime_listase(j1->mao);
	// 	printf("\n");
	// 	printf("Nome jogador 2: %s\n", j2->name);
	// 	printf("Quantidade de pecas jogador 2: %d\n", j2->QntPecas);
	// 	imprime_listase(j2->mao);
	// 	printf("\n");
	// }
	
	if(numj==4){ //CHECA as peças na mão do jogadores para ver se está certo (4 jogadores)
		printf("Nome jogador 1: %s\n", j1->name);
		printf("Quantidade de pecas jogador 1: %d\n", j1->QntPecas);	
		imprime_listase(j1->mao);
		printf("\n");
		printf("Nome jogador 2: %s\n", j2->name);
		printf("Quantidade de pecas jogador 2: %d\n", j2->QntPecas);
		imprime_listase(j2->mao);
		printf("\n");	
		printf("Nome jogador 3: %s\n", j3->name);
		printf("Quantidade de pecas jogador 3: %d\n", j3->QntPecas);
		imprime_listase(j3->mao);
		printf("\n");
		printf("Nome jogador 4: %s\n", j4->name);
		printf("Quantidade de pecas jogador 4: %d\n", j4->QntPecas);
		imprime_listase(j4->mao);
	}
 
}

void arrumaMao(tp_pilhaM **paux){
	tp_itemM vetAux[7], e;
	int c=0, n=7;
	while(!listase_vazia(paux)){
		retiraUltimoDaLista(paux, &e);
		vetAux[c] = e;
		c++;
	}

	for(int i= 1; i<n; i++){ //Uma simples função bubbleSort pra ordernar a pilha
		for(int k = 0; k<n-1; k++){
			if((vetAux[k].esquerda+vetAux[k].direita) > (vetAux[k+1].esquerda+vetAux[k+1].direita)){
			e = vetAux[k];
			vetAux[k] = vetAux[k+1];
			vetAux[k+1] = e;
			}
		}
	}	
	
	c=0;
	while(c<7){
		insere_listase_no_fim(paux, vetAux[c]);
		c++;
	}

}

void oJogoPara4(tp_pilhaM *cava, tp_jogador *j1, tp_jogador *j2, tp_jogador *j3, tp_jogador *j4, int qntJogadores, int escolhido){
	EscolheOsNomesDosJogadores(qntJogadores, j1, j2, j3, j4);

	

}

void oJogoPara2(tp_pilhaM *cava, tp_jogador *j1, tp_jogador *j2, int qntJogadores, int escolhido){


}

int main(){
	setlocale(LC_ALL, "Portuguese"); // Definindo a liguagem para português.
	int numj, choosen, res, cont=0; // Declarando as váriaveis.
	tp_jogador j1, j2, j3, j4; // Iniciando os jogadores
	tp_itemM monteInicial[28]; // Iniciando o primeiro Monte
	tp_pilhaM monteTrue;
	inicializa_pilha(&monteTrue); // Iniciando a pilha que vai ser usada
	MenuDoJogo(&res); // Iniciando o menu jogo.
	
	if (res){	//Vai jogar.
		EscolheOsNomesDosJogadores(&numj, &j1, &j2, &j3, &j4); // Escolhe os nomes dos jogadores
		Sorteador(&numj, &choosen); // Sorteia quem comeca.
		EscolheOrdemJogadores(&choosen, numj, &j1, &j2, &j3, &j4); // 
		startamonte(monteInicial); // Inicia o monte com 28 peças
		sorteiaomonte(monteInicial); // Embaralhar o monte criado
		distribuir_monte(monteInicial, &monteTrue, &j1, &j2, &j3, &j4, numj); // Distribui o monte para os jogadores 
		if(numj == 4) oJogoPara4(&monteTrue, &j1, &j2, &j3, &j4, numj, choosen);
		if(numj == 2) oJogoPara2(&monteTrue, &j1, &j2, numj, choosen);
	}
	else printf("Percebi que voce desistiu. FRACO!\n"); //Não vai jogar/Deistencia. 	
	
	return 0;           
}