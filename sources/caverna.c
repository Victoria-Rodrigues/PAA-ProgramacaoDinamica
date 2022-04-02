#include "../headers/caverna.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(x, y) (((x) < (y)) ? (x) : (y))

int** initCaverna(int linha, int coluna){
    int **caverna;
    int i;

    caverna = malloc((linha)*sizeof(int*));
    for ( i = 0; i < linha; i++)
    {
        caverna[i] = malloc((coluna)*sizeof(int));
    }
   
    return caverna;
}



void preencherCaverna(Caverna *caverna, char *nomeAquivo){
    FILE *arquivo;
    int cont = 0;
    char line[10];
    int linha, coluna, unidadeTempoGasta, tempoLava,i,j;
    arquivo = fopen(nomeAquivo, "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!!\n");
    }else{
        while (!feof(arquivo)){
            fscanf(arquivo,"%d %d %d %d", &caverna->linha, &caverna->coluna, &caverna->unidadeTempoGasta, &caverna->tempoLava);
           //printf("\n");
            caverna->caverna = initCaverna(caverna->linha, caverna->coluna);
            for( i = 0; i<caverna->linha; i++){
                cont++;
                for( j = 0; j < caverna->coluna; j++){
                     fscanf(arquivo,"%s",line);
                     if(strcmp(line,"###") == 0){
                        // printf("%s ", line);
                         caverna->caverna[i][j] = -1;
                     }else{
                       //  printf("%s ", line);
                         int value = atoi(line);
                         caverna->caverna[i][j] = value;
                     }
                      
                 } 
                // printf("\n");
            } 
        }
    }
    fclose(arquivo);
}



int caminhoMinimo(Caverna *caverna, int i, int j){
    if(i == 0){
        return 0;
    }else{ 
        if(posicaoEhValida(caverna, i, j)){
            if(i%2!=0){
                // printf("m[%d][%d] = %d\n", i,j,caverna->caverna[i][j]);
                

                if((posicaoEhValida(caverna,i-1,j)) && (posicaoEhValida(caverna,i-1,j+1))){
                    return min(caverna->caverna[i-1][j],caverna->caverna[i-1][j+1]);
                }
                else if((!posicaoEhValida(caverna,i-1,j)) && (posicaoEhValida(caverna,i-1,j+1))){
                    return caverna->caverna[i-1][j+1];
                }else if((posicaoEhValida(caverna,i-1,j)) && (!posicaoEhValida(caverna,i-1,j+1))){
                    return caverna->caverna[i-1][j];
                }else{

                    return -1;
                }
            }else{
                if((posicaoEhValida(caverna,i-1,j-1)) && (posicaoEhValida(caverna,i-1,j))){
                    return min(caverna->caverna[i-1][j-1],caverna->caverna[i-1][j]);
                }
                else if(!(posicaoEhValida(caverna,i-1,j-1)) && (posicaoEhValida(caverna,i-1,j))){
                    return caverna->caverna[i-1][j];
                }else if((posicaoEhValida(caverna,i-1,j-1)) && !(posicaoEhValida(caverna,i-1,j))){
                    return caverna->caverna[i-1][j-1];
                }else{
                    return -1;
                }
            }

        
        }
        
    }
    return 0;
}

void calcularCelInalcancaveis(Caverna caverna){
    int i,j;
    int copia;
    for( i=caverna.linha-2; i>=0;i--){
        for( j=0; j<caverna.coluna;j++){
            if(caverna.caverna[i][j]!=-1){
            if(i%2!=0){
            if(posicaoEhValida(&caverna,i+1,j)==false && posicaoEhValida(&caverna,i+1,j+1)==false) {
                copia= caverna.caverna[i][j];
                caverna.caverna[i][j]=-1;
                printf("Celula inalcancavel: %d ; Posicao-> i:%d j:%d\n",copia,i,j);
            }
            }else{
             if(posicaoEhValida(&caverna,i+1,j)==false && posicaoEhValida(&caverna,i+1,j-1)==false) {
                copia= caverna.caverna[i][j];
                caverna.caverna[i][j]=-1;
                printf("Celula inalcancavel: %d ; Posicao> i:%d j:%d\n",copia,i,j);
            }
        }
            }
                
        }
    }
    printf("\n");
}

void desenharMelhorCaminho(Caverna caverna){
    int i,j;
    int min2;
    int posI=caverna.linha-1;
    int posJ=inicio(&caverna,caverna.linha,0);
    int cont=0;

    caverna.caverna[posI][posJ]=-2;

    // printf("%d %d",posI,posJ);
    for(i=0;i<caverna.linha-1;i++){
        posI-=1;
        if(posI%2!=0){
            if(posicaoEhValida(&caverna,posI,posJ) && posicaoEhValida(&caverna,posI,posJ-1)) {
                min2=minimo(caverna.caverna[posI][posJ],caverna.caverna[posI][posJ-1]);
                if (caverna.caverna[posI][posJ]!=min2)
                {
                    posJ-=1;   
                } 
            }else if(!posicaoEhValida(&caverna,posI,posJ) && posicaoEhValida(&caverna,posI,posJ-1)){
                posJ-=1;
            }
        }else{

             if(posicaoEhValida(&caverna,posI,posJ) && posicaoEhValida(&caverna,posI,posJ+1)) {
                min2=minimo(caverna.caverna[posI][posJ],caverna.caverna[posI][posJ+1]);
                if (caverna.caverna[posI][posJ]!=min2)
                {
                    posJ+=1;   
                } 
            }else if(!posicaoEhValida(&caverna,posI,posJ) && posicaoEhValida(&caverna,posI,posJ+1)){
                posJ+=1;
            }
        }       
        caverna.caverna[posI][posJ]=-2;
    }

    for(i=0;i<caverna.linha;i++){
    for(j=0;j<caverna.coluna;j++){
        if (i%2!=0 && cont==0)
        {
           printf("  ");
           cont++;
        }
        
        if(caverna.caverna[i][j]==-2) printf("[X]");
        else printf("[-]");
        }
        cont=0;
        printf("\n");
    }
    

}


void calcula(Caverna *caverna){
    int i,j;
    int min2;
    int posI=0,posJ=0;
    printf("Calculando celulas inalcancaveis...\n");
    calcularCelInalcancaveis(*caverna);
    printf("Procurando melhor caminho...\n");
    for( i=0; i<caverna->linha;i++){
        for( j=0; j<caverna->coluna;j++){
            if(caminhoMinimo(caverna, i, j)==-1){
                caverna->caverna[i][j] = -1;
            }else{
                caverna->caverna[i][j] = caverna->caverna[i][j] + caminhoMinimo(caverna, i, j);
            }
        }
    }
    posJ=inicio(caverna,caverna->linha,0);
    posI=caverna->linha-1;
    if(posJ==-1){
        printf("Samus falhou na missao");
        }else{
        min2=caverna->caverna[posI][posJ];
        // printf("%d\n", min2);
        printf("Samus deve seguir as coordenadas abaixo:\n");
        printf("%d %d\n", posI,posJ);
    for(i=0;i<caverna->linha-1;i++){
        posI-=1;
        if(posI%2!=0){
            if(posicaoEhValida(caverna,posI,posJ) && posicaoEhValida(caverna,posI,posJ-1)) {
                min2=minimo(caverna->caverna[posI][posJ],caverna->caverna[posI][posJ-1]);
                if (caverna->caverna[posI][posJ]!=min2)
                {
                    posJ-=1;   
                } 
            }else if(!posicaoEhValida(caverna,posI,posJ) && posicaoEhValida(caverna,posI,posJ-1)){
                posJ-=1;
            }
        }else{

             if(posicaoEhValida(caverna,posI,posJ) && posicaoEhValida(caverna,posI,posJ+1)) {
                min2=minimo(caverna->caverna[posI][posJ],caverna->caverna[posI][posJ+1]);
                if (caverna->caverna[posI][posJ]!=min2)
                {
                    posJ+=1;   
                } 
            }else if(!posicaoEhValida(caverna,posI,posJ) && posicaoEhValida(caverna,posI,posJ+1)){
                posJ+=1;
            }
        }       
        // printf("%d\n", caverna->caverna[posI][posJ]);
    printf("%d %d\n", posI,posJ);
      
    }
    printf("\nDesenhando caminho...\n");
    desenharMelhorCaminho(*caverna);
        }
    
  
}

int minimo(int valor1,int valor2){
    if(valor1!=-1 && valor2==-1) return valor1;
    if(valor1==-1 && valor2!=-1) return valor2;
    return min(valor1,valor2);
}

int inicio(Caverna *caverna,int i,int j){
    int menor = 1000;
    int posC = -1;
    int tempoTotal =caverna->tempoLava*caverna->linha;
     
    for( i = 0; i <caverna->coluna;i++){
        if((caverna->caverna[caverna->linha-1][i] < menor) && (caverna->caverna[caverna->linha-1][i]!=-1)
         && (tempoTotal >=caverna->caverna[caverna->linha-1][i])){
            menor = caverna->caverna[caverna->linha-1][i];
            posC = i;
        }   
    }
    return posC;
}


int posicaoEhValida(Caverna *caverna, int i, int j){
    if(i<0 || j<0 || i >= caverna->linha || j>= caverna->coluna){
        return false;
    }else if(caverna->caverna[i][j] == -1){
        return false;
    }else{
         return true;
    }
}

void printCaverna(Caverna *caverna){
    int i,j;
 for(i=0;i<caverna->linha;i++){
    for(j=0;j<caverna->coluna;j++){
    printf("[%d]",caverna->caverna[i][j]);  
        }
        printf("\n");
    }
}