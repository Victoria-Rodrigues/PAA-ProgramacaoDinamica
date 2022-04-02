#include "../headers/caverna.h"
#include "../headers/modoAnalise.h"
#include "../headers/geradorArquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarArquivos(){
    gerarArquivo("entrada10.txt",10,10,0,1);
    gerarArquivo("entrada50.txt",50,50,0,1);
    gerarArquivo("entrada100.txt",100,100,0,1);
    gerarArquivo("entrada500.txt",500,500,0,1);
    gerarArquivo("entrada1000.txt",1000,1000,0,1);
    gerarArquivo("entrada5000.txt",5000,5000,0,1);
    gerarArquivo("entrada10000.txt",10000,10000,4,3);
}

void calcularTempos(){
    Caverna caverna;
    clock_t t;
    
    preencherCaverna(&caverna,"entrada10.txt");
    t=clock();
    calcula(&caverna);
    t=clock()-t;
    printf ("Tempo de execução para entrada 10x10:%lf\n",((float)t)/CLOCKS_PER_SEC);

    
    preencherCaverna(&caverna,"entrada50.txt");
    t=clock();
    calcula(&caverna);
    t=clock()-t;
    printf ("Tempo de execução para entrada 50x50:%lf\n",((float)t)/CLOCKS_PER_SEC);

    preencherCaverna(&caverna,"entrada100.txt");
    t=clock();
    calcula(&caverna);
    t=clock()-t;
    printf ("Tempo de execução para entrada 100x100:%lf\n",((float)t)/CLOCKS_PER_SEC);

    preencherCaverna(&caverna,"entrada500.txt");
    t=clock();
    calcula(&caverna);
    t=clock()-t;
    printf ("Tempo de execução para entrada 500x500:%lf\n",((float)t)/CLOCKS_PER_SEC);

    preencherCaverna(&caverna,"entrada1000.txt");
    t=clock();
    calcula(&caverna);
    t=clock()-t;
    printf ("Tempo de execução para entrada 1000x1000:%lf\n",((float)t)/CLOCKS_PER_SEC);

    preencherCaverna(&caverna,"entrada5000.txt");
    t=clock();
    calcula(&caverna);
    t=clock()-t;
    printf ("Tempo de execução para entrada 5000x5000:%lf\n",((float)t)/CLOCKS_PER_SEC);

    preencherCaverna(&caverna,"entrada10000.txt");
    t=clock();
    calcula(&caverna);
    t=clock()-t;
    printf ("Tempo de execução para entrada 10000x10000:%lf\n",((float)t)/CLOCKS_PER_SEC);

}