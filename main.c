#include <stdio.h>
#include <stdlib.h>
#include "headers/caverna.h"
#include "headers/geradorArquivo.h"
#include "headers/modoAnalise.h"
#include <stdbool.h>
#include <time.h>


int main(){
     Caverna caverna;
     int loop=1;
     int loop1 = 1, opcao1;
     int opcao,tamLinha,tamColuna,tempoSamus,tempoLava;
     char nomeArquivo[100];
    while (loop)
    {
      printf("\n=================================================\n");
      printf("========================MENU=====================\n");
      printf("=================================================\n");
      printf("[1] Gerar um arquivo com um mapa aleatorio.\n");
      printf("[2] Executar o programa.\n"); 
      printf("[3] Modo Analise.\n");
      printf("[0] Sair.\n");
      printf("Opcao: ");
      scanf("%d", &opcao);
      switch(opcao){
          case 0:{
                loop=0; 
                break;
          }
          case 1:{
              printf("Insira o nome do arquivo(coloque .txt ao final), o tamanho da linha e coluna e o tempo do Samus e da lava subirem cada nível respectivamente.\n");
              printf("Exemplo:entradas/arquivo.txt 1 2 3 4\n");
              scanf("%s %d %d %d %d",nomeArquivo ,&tamLinha,&tamColuna,&tempoSamus,&tempoLava);
              fflush(stdin);
              gerarArquivo(nomeArquivo,tamLinha,tamColuna,tempoSamus,tempoLava);
              printf("Arquivo gerado com sucesso!!\n");
              break;
          }
          case 2:{
                printf("Insira o nome do arquivo(coloque .txt ao final).\n");
                printf("Exemplo:entradas/arquivo.txt\n");
                scanf("%s",nomeArquivo);
                preencherCaverna(&caverna,nomeArquivo);
                calcula(&caverna);
                break;
          }
          case 3:{
              int flag;
              printf("\n=================================================\n");
              printf("Bem vindo ao modo analise!!\n");
              printf("Este modo ira gerar arquivos de entrada pequenos e grandes, e calcular qual o melhor caminho de cada um.\n");
              printf("Atencao este modo ira demorar alguns minutos.\n");
              printf("Voce deseja continua com o modo Analise ?\n");
              printf("[1] sim - [2] nao\n");
              printf("Opcao: ");
              scanf("%d",&flag);
              if(flag == 1){
                  printf("Iniciando o modo analise...\n");
                  gerarArquivos();
                  calcularTempos(); 
              }
              break;
         }
              
          default:{
              printf("Insira uma opcao valida");
              break;
          }
      }
    }
     
  
    return 0;
}

