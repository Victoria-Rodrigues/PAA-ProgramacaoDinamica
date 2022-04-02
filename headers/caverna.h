#ifndef CAVERNA_H
#define CAVERNA_H
#include <stdbool.h>
typedef struct {
    int **caverna;
    int linha;
    int coluna;
    int unidadeTempoGasta;
    int tempoLava;
    int tempoTotal;
    
}Caverna;

int** initCaverna(int linha, int coluna);

void preencherCaverna(Caverna *caverna, char* nomeAquivo);

void printCaverna(Caverna *caverna);

int movimentar(Caverna *caverna, int i, int j);

int caminhoMinimo(Caverna *caverna, int i, int j);

int minimo(int valor1,int valor2);

//int Min(Caverna *caverna, int i, int j); função inexistente

int posicaoEhValida(Caverna *caverna, int i, int j);

void calcula(Caverna *caverna);

int inicio(Caverna *caverna,int i,int j);

void calcularCelInalcancaveis(Caverna caverna);

void desenharMelhorCaminho(Caverna caverna);

#endif