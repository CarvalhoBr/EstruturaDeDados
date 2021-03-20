#include <stdlib.h>
#include <stdio.h>
#include "set.h"
#include <stdbool.h>

int* initialize(){
    int* set = (int*) malloc(sizeof(int));

    return set;
}

int* push(int* vet, int element){
    /*if(sizeof(vet)/sizeof(int) == 1){
        vet[0] = element;
        return vet;
    }*/

    int* newVet = malloc(sizeof(vet) + sizeof(int));

    for (int i = 0; i<(sizeof(vet) / sizeof(int));i++){
        newVet[i] = vet[i];
    }
    newVet[sizeof(newVet)/sizeof(int)] = element;

    return newVet;
}