#include <stdio.h>
#include <stdlib.h>
#include "ES.h"

void lerArquivo(char nomeArquivoE[], int vet[]){
    FILE *arq;
    int num, i=0;
    arq = fopen(nomeArquivoE, "r");
    if(arq == NULL)
        printf("Erro, arquivo invalido");
    else{
        while((fscanf(arq, "%d", &num)) != EOF){
            vet[i] = num;
            i++;
        }
    }
    fclose(arq);
}
void escreverArquivo(int vetOrd[], int tam){
    FILE *arq;
    int i;
    arq = fopen("arqS.txt", "w");
    if(arq == NULL)
        printf("Erro, arquivo invalido");
    else{
            for(i=0;i<tam;i++){
                fprintf(arq, "%d\n", vetOrd[i]);
            }
    }
    fclose(arq);
}
