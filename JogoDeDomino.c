// Esse programa é responsável por simular um jogo de dominó,com 2 ou 4 jogarores em cada partida.
// Feito por:
// Fernando Schettini ( o mais foda) Github:https://github.com/FernandoSchett

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h> 
#include "Pilha.h"
#include "Fila.h"	

void sorteador(int *numj){ //Esse funcao vai sortear com base no inteiro que recebeu.
	
	
	
	
}

void menuDoJogo(int *res){ //Função reponsável pelo menu inicial do jogo.
 
	printf("Bem-vindo ao MELHOR jogo de dominó da AMERA-LATINA e afiliados.\n");
	printf("Insira o número 1 para jogar ou 0 para arregar :'(\n");
	scanf(" %d", res);
	while(*res != 0 & *res != 1 ){
		printf("Valor inválido.\n");
    	printf("Insira um valor válido, 1 para jogar ou 0 para arregar:\n");
    	scanf(" %d", res);
	}
	system("cls"); //Limpa o terminal.
}

void escolheOsNomesDosJogadores(int *numj, char *j1, char *j2, char *j3, char *j4){
	printf("Quantos jogadores vao jogar?\n");
	scanf(" %d", numj);
	
	while(*numj != 2 & *numj != 4 ){
		printf("Valor inválido.\n");
		printf("Insira um valor válido, pode-se apenas jogar com 2 ou 4 jogadores:\n");
    	scanf(" %d", numj);
	}
	
	if( *numj == 4){ //4 jogadores.
		//Recolhe o nome dos jogaores.
		printf("Nome do primeiro jogador:\n");
		scanf(" %s", j1);
		printf("Nome do segundo jogador:\n");
		scanf(" %s", j2);
		printf("Nome do terceiro jogador:\n");
		scanf(" %s", j3);
		printf("Nome do quarto jogador:\n");
		scanf(" %s", j4);
		
		system("cls"); //Limpa o terminal.
		
		//Apresenta os jogadores.
		printf("Os melhores jogadores de dominó tem nome!\n");
		printf("Jogador número 1: %s\n", *j1);
		printf("Jogador número 2: %s\n", *j2);
		printf("Jogador número 3: %s\n", *j3);
		printf("Jogador número 4: %s\n", *j4);
	}
	
	if( *numj == 2){ //2 jogadores.
		//Recolhe o nome dos jogaores.
		printf("Nome do primeiro jogador:\n");
		scanf(" %s", j1);
		printf("Nome do segundo jogador:\n");
		scanf(" %s", j2);
		
		system("cls"); //Limpa o terminal.
		
		//Apresenta os jogadores.
		printf("Os melhores jogadores de dominó tem nome!\n");
		printf("Jogador número 1: %s \n", *j1);
		printf("Jogador número 2: %s \n", *j2);	
	}
}

typedef struct{
  int top, bottom; //EITA BIXO SEXO
}tp_pedra;

tp_pedra pedra00, pedra01, pedra02, pedra03, pedra04, pedra05, pedra06;
tp_pedra pedra11, pedra21, pedra31, pedra41, pedra51, pedra61, pedra22;
tp_pedra pedra32, pedra42, pedra52, pedra62, pedra33, pedra43, pedra53; 
tp_pedra pedra63, pedra44, pedra54, pedra64, pedra55, pedra65, pedra66; // Declarando todas as pecas do jogo ** NAO SEI SE VAI SER ASSIM **


void embaralhandoPecas(){

}
int main(){
	//Declarando as váriaveis.
	setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem para português.
	int res, numj;
	char j1[100], j2[100],j3[100],j4[100];
	
	//Começando o jogo.
	//textbackground(1); // PINTA O FUNDO DO TEXTO
	//textcolor(3);
	menuDoJogo(&res); //Iniciando o menu jogo.
	if (res == 0){                               //Não vai jogar/Deistencia.
		printf("Percebi que voce desistiu. FRACO!\n"); 
	}
	else{                                        //Vai jogar.
		escolheOsNomesDosJogadores(&numj, &j1, &j2, &j3, &j4);
	
		sorteador(numj); //sorteia quem comeca.
	}
	return 0;
} 
