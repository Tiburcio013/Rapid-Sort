#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quadraticos.h"

clock_t t0, tf;
double tempo_gasto;
double compChave = 0.0;
double numCopias = 0.0;

void selecao(int vet[], int tam){
    int i, j;
    int min, aux;
    t0 = clock();
    for(i=0; i<tam-1; i++) {
        min = i;
        for(j=i+1; j<tam; j++) {
            compChave++;
            if (vet[j] < vet[min]){
                min = j;
            }
        }
        compChave= compChave+1.0;
        if (i != min) {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
            numCopias = numCopias+3.0;
        }
    }

    tf = clock();
    tempo_gasto = (( (double) (tf - t0) ) / (((double)CLOCKS_PER_SEC)/1000));
    printf("\n\nTempo gasto SELECAO: %lf ms\nNumeros de copias de registro: %llf\nComparacoes de chave: %llf", tempo_gasto, numCopias, compChave);
    return;
}

void rapidSort(int vet[], int tam){
    int lowerBound = 0, upperBound = tam-1;
    int flagLB = 0, flagAuxLB;
    int flagUB = 0, flagAuxUB;
    int tempLB, tempUB;
    int next_number, dist_lb, dist_ub;
    int minA = 0, maxA = 0;
    int aux, j, i;
    t0 = clock();
    for(j=0; j<tam; j++) {
        compChave = compChave+1;
        if (vet[j] <= vet[minA]){
            minA = j;
        }
    }
    if(0!=minA){
        aux = vet[0];
        vet[0] = vet[minA];
        vet[minA] = aux;
        numCopias = numCopias+3;
    }
    for(j=0; j<tam; j++) {
        compChave = compChave+1;
        if(vet[j] >= vet[maxA]){
            maxA = j;
        }
    }
    if((tam-1)!=maxA ){
        aux = vet[(tam-1)];
        vet[(tam-1)] = vet[maxA];
        vet[maxA] = aux;
        numCopias = numCopias+3;
    }

    for(i=1;i<tam-1;i++){
        if(!(upperBound == lowerBound+1)){
            flagAuxLB = 0, flagAuxUB = 0;
            flagLB = 0, flagUB = 0;
            next_number = i;
            dist_lb = abs(vet[next_number]-vet[0]);
            dist_ub = abs(vet[next_number]-vet[tam-1]);

            compChave = compChave+1;
            if(dist_lb<dist_ub){
                aux = vet[lowerBound+1];
                vet[lowerBound+1] = vet[next_number];
                vet[next_number] = aux;
                lowerBound++;
                flagAuxLB = 1;
                numCopias = numCopias+3;
            }
            else{
                aux = vet[upperBound-1];
                vet[upperBound-1] = vet[next_number];
                vet[next_number] = aux;
                upperBound--;
                i--;
                flagAuxUB = 1;
                numCopias = numCopias+3;
            }

            tempLB = lowerBound;
            tempUB = upperBound;

            aux = vet[next_number];

            compChave = compChave+1;
            while(aux < vet[tempLB-1] && flagAuxLB == 1){
                flagLB = 1;
                vet[tempLB] = vet[tempLB-1];
                tempLB--;
            }
            if(flagLB==1){
                vet[tempLB] = aux;
            }

            aux = vet[upperBound];
            compChave = compChave+1;
            while((aux > vet[tempUB+1]) && flagAuxUB == 1){
                flagUB = 1;
                vet[tempUB] = vet[tempUB+1];
                tempUB++;
                numCopias = numCopias+1;
            }
            if(flagUB==1){
                vet[tempUB] = aux;
                numCopias = numCopias+1;
            }
        }
    }
    tf = clock();
    tempo_gasto = (( (double) (tf - t0) ) / (((double)CLOCKS_PER_SEC)/1000));
    printf("\n\nTempo gasto RAPID: %lf ms\nNumeros de copias de registro: %llf\nComparacoes de chave: %llf", tempo_gasto, numCopias, compChave);
    return;
}
