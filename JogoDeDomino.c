/* Esse programa é responsável por simular um jogo de dominó,com 2 ou 4 jogarores em cada partida.
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
#include "pilha.h"
#include "fila.h"	
#include"LIstaSEncadeada.h"
#include <Windows.h>

	typedef struct{
		int esquerda, direita; 
	}tp_pedra;  


void EscolhePrimeiro(int *escolhido, char *j1, char *j2, char *j3, char *j4){
	switch (*escolhido){
		case 1:
			printf ("Jogador %s comeca!\n", j1);	
		case 2:
			printf ("Jogador %s comeca!\n", j2);	
		case 3:
			printf ("Jogador %s comeca!\n", j3);	
		case 4:	
			printf ("Jogador %s comeca!\n", j4);	
	}
	printf ("A ordem do escolhido sempre segue no sentido crescente! 1 -> 2 -> 3 -> 4\n");	
	system("pause");
	system("cls"); 

}

void Sorteador(int *possibilidade, int *escolhido){ //Esse funcao vai sortear com base no inteiro que recebeu.
	int random, nrandom, choosen;
	float chance;
	
	//srand(time (NULL)); //Generate seed for rand(),based in your pc time.
	printf("Possibilidade: %d\n", *possibilidade);
	random = rand() % 100 ; //Generate random number in range 1-100.
	printf("random: %d\n", random);
	chance = 100 / *possibilidade; //chance of getting any number.
	printf("chance: %f \n", chance);

	nrandom = 0;
	*escolhido = 0;
	
	while(nrandom < random){ //Look for the range.
		nrandom = nrandom  + chance;
		//printf("escolhido: %d\n", *escolhido);
		//printf("nrandom: %d\n", random);
		*escolhido = *escolhido + 1;	
	}
	printf("escolhido: %d\n", *escolhido);
}

void MenuDoJogo(int *res){ //Função reponsável pelo menu inicial do jogo.
 
	printf("Bem-vindo ao MELHOR jogo de dominó da AMERA-LATINA e afiliados.\n");
	printf("Insira o número 1 para jogar ou 0 para arregar :'(\n");
	scanf(" %d", res);
	//printf(" |%s| ", res);

	while((*res != 0) && (*res != 1) ){
		printf("Valor inválido.\n");
    	printf("Insira um valor válido, 1 para jogar ou 0 para arregar:\n");
		scanf(" %d", res);;
    //	printf(" |%s|\n", res);
	}
	system("pause");
	system("cls"); //Limpa o terminal.
}

void EscolheOsNomesDosJogadores(int *numj, char *j1, char *j2, char *j3, char *j4){
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
		scanf(" %[^\n]s", j1);
		printf("Nome do segundo jogador:\n");
		scanf(" %[^\n]s", j2);
		printf("Nome do terceiro jogador:\n");
		scanf(" %[^\n]s", j3);
		printf("Nome do quarto jogador:\n");
		scanf(" %[^\n]s", j4);
		
		system("pause");
		system("cls"); //Limpa o terminal.
		
		//Apresenta os jogadores.
		printf("Os melhores jogadores de dominó tem nome!\n");
		printf("Jogador número 1: %s\n", j1);
		printf("Jogador número 2: %s\n", j2);
		printf("Jogador número 3: %s\n", j3);
		printf("Jogador número 4: %s\n", j4);
	}
	
	if( *numj == 2){ //2 jogadores.
		//Recolhe o nome dos jogaores.
		printf("Nome do primeiro jogador:\n");
		scanf(" %[^\n]s", j1);
		printf("Nome do segundo jogador:\n");
		scanf(" %[^\n]s", j2);
		
		system("pause");
		system("cls"); //Limpa o terminal.
		
		//Apresenta os jogadores.
		printf("Os melhores jogadores de dominó tem nome!\n");
		printf("Jogador número 1: %s \n", j1);
		printf("Jogador número 2: %s \n", j2);	
	}
	system("pause");
	system("cls"); 
}


// tp_pedra pedra00, pedra01, pedra02, pedra03, pedra04, pedra05, pedra06;
// tp_pedra pedra11, pedra21, pedra31, pedra41, pedra51, pedra61, pedra22;
// tp_pedra pedra32, pedra42, pedra52, pedra62, pedra33, pedra43, pedra53; 
// tp_pedra pedra63, pedra44, pedra54, pedra64, pedra55, pedra65, pedra66;

void startamonte(tp_pedra *monte){ //Funcao que vai definir o valor de cada ladeo da peca dentor do vetor.
	int contGeral, cont, numerodapeca;
	contGeral = 0;
	cont = 0;
	numerodapeca = 6;
	while(numerodapeca > -1){	// Preenche a parte esquerda das pecas
 		while(cont < (numerodapeca + 1)){
 			monte[contGeral].esquerda = numerodapeca;
			//printf("%d ", monte[contGeral].esquerda);
 			contGeral ++;
 			cont ++;
 		}
 	cont = 0;
 	numerodapeca--;
	}
	//printf("\n");
	contGeral = 0;
	cont = 7;
	numerodapeca = 0;
	
	while(cont > 0){ // Preenche a parte direita das pecas.
		while(numerodapeca < cont){
 			monte[contGeral].direita = numerodapeca;
			//printf("%d ", monte[contGeral].direita);
			numerodapeca++;
			contGeral++;
		}
	cont--;
	numerodapeca = 0;
	}

}

void sorteiaomonte(tp_pedra *monte){ //Funcao que vai embaralhar as pecas dentro de um pilha.
	int peca, peca1,cont,num;
	tp_pedra aux;
	cont = 0;
	num = 28;
	
		// while(cont< 500){	
		
	  // 	Sorteador(&num, &peca);
	  // 	//printf("%d ", peca);
	  // 	Sorteador(&num, &peca1);
	  // 	//printf("%d ", peca1);
	  // 	//printf("\n");
	  // 	aux = monte[peca];
	 	// monte[peca] = monte[peca1];
	 	// monte[peca1] = aux;
	  // 	cont++;
	  // }
		srand(time(NULL));
		for(int i = 0; i < 500; i++){
			peca = rand()%28;
			peca1 = rand()%28;
			aux = monte[peca];
	 		monte[peca] = monte[peca1];
	 	 	monte[peca1] = aux;
		}
		
	cont = 0;
	 while(cont < 28){
	 	printf("%d ", monte[cont].esquerda);
	 	cont++;
	 }
	 printf("\n");
	 cont = 0;
	 	while(cont < 28){
	 	printf("%d ", monte[cont].direita);
	 	cont++;
	 }
}




int main(){
	//Declarando as váriaveis.
	setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem para português.
	int numj, choosen, res;
	char j1[100], j2[100],j3[100],j4[100];
	tp_pedra monte[28];

	
	startamonte(monte);	
	sorteiaomonte(monte);
	system("pause");
	//Começando o jogo.
	MenuDoJogo(&res); //Iniciando o menu jogo.
	
	if (res == 0){  //Não vai jogar/Deistencia.
		printf("Percebi que voce desistiu. FRACO!\n"); 
	}
	else{      //Vai jogar.
		EscolheOsNomesDosJogadores(&numj, j1, j2, j3, j4);
		Sorteador(&numj, &choosen); //sorteia quem comeca.
		EscolhePrimeiro(&choosen, j1, j2, j3, j4);
		startamonte(monte);	
	
	}
	return 0;              // :(
}