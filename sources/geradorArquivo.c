#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../headers/geradorArquivo.h"

void gerarCaracteres(char* str){
    int string,valor;
    char string2[4];
    string=rand()%3;
    if(string==0){
        str[0]='#';
        str[1]='#';
        str[2]='#';
    }else if(string==1){
        str[0]='0';
        str[1]='0';
        str[2]='0';
    }else{
        valor=1+rand()%1000;
        valor = valor==1000 ? 999 : valor; 
        sprintf(string2,"%d",valor);
        if(valor>0 && valor<=99){
             str[0]='0';
            if(valor>0 && valor<=9){
                str[1]='0';
                str[2]=string2[0];
            }else{
                str[1]=string2[0];
                str[2]=string2[1]; 
            }
            
        }else{
         sprintf(str,"%d",valor);
        }
        
    }
}

void gerarArquivo(char* nomeArquivo,int tamLinha, int tamColuna, int tempoSamus,int tempoLava){
    FILE* arquivo = fopen(nomeArquivo, "w");
    char string[4];
    int i,j,cont=0;
    srand(time(0));

    if(arquivo == NULL){
        printf("Arquivo Inexistente!!");
    }else{
        fprintf(arquivo,"%d %d %d %d\n",tamLinha,tamColuna,tempoSamus,tempoLava);
        for(i=0;i<tamLinha;i++){
            for(j=0;j<tamColuna;j++){
                if(i%2!=0 && cont==0){
                    fprintf(arquivo,"  ");
                    cont++;
                }
                gerarCaracteres(string);
                if (j!=tamColuna-1)
                {
                    fprintf(arquivo,"%s ",string);
                }else{
                    fprintf(arquivo,"%s",string);
                }
                
                
            }
            if(i!=tamLinha-1){
                fputc('\n',arquivo);
            }
            cont=0;
        }
         fclose(arquivo);
        
    }

}