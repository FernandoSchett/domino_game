#include<stdio.h>
#include<string.h>
#include"Pilha.h"
#include"Fila.h"
#include<random.h>

int menuDoJogo(){
  int d; 
  printf("Bem-vindo ao MELHOR jogo de domino da AMERA-LATINA e afiliados");
  printf("Insira o numero 1 para jogar ou 0 para arregar :'(");
  scanf("%d", &d);
 while(d != 0 & d != 1 ){
    printf("Valor invalido");
    printf("Insira um valor valido, 1 para jogar ou 0 para arregar");
    scanf("%d", &d);
  }
  return d;
}

int escolheOsNomesDosJogadores(){
  char jogador1[500], jogador2[500]; //Escolhi 2 jogadores mas podem ser 4
  printf("Nome do primeiro jogador: ");
  scanf("%s", &jogador1);
  printf("Nome do segundo jogador: ");
  scanf("%s", &jogador2);

}

typedef struct{
  int top, bottom;
}tp_pedra;

tp_pedra pedra00, pedra01, pedra02, pedra03, pedra04, pedra05, pedra06;
tp_pedra pedra11, pedra21, pedra31, pedra41, pedra51, pedra61, pedra22;
tp_pedra pedra32, pedra42, pedra52, pedra62, pedra33, pedra43, pedra53; 
tp_pedra pedra63, pedra44, pedra54, pedra64, pedra55, pedra65, pedra66; // Declarando todas as peças do jogo ** NAO SEI SE VAI SER ASSIM **


int embaralhandoPecas(){

}
int main(){

  int res;
  res = menuDoJogo();
  if (res == 0)                                // Não vai jogar/Deistencia
  printf("Percebi que voce desistiu. FRACO!"); 
  break;

  else                                         // Vai jogar
  escolheOsNomesDosJogadores();
  return 0;
} 