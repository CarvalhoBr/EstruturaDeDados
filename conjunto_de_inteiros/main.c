#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>
#include "set.h"

int main(void){
    
    int* vet = initialize();
    printf("Set size: %lu\n", sizeof(vet));
    printf("Set elements: %i\n", vet[0]);
    printf("%lu\n", sizeof(int));

    printf("Adicionando novo elemento\n");
    int* newVet = push(vet, 3);
    printf("Adicionando novo elemento\n");
    int* newVet2 = push(vet, 4);
    
    //printf("Novo Elemento: %d\n", newVet[1]);

    for (int i = 0; i < (sizeof(newVet2)/sizeof(int)); i++)
    {
        printf("%d", newVet2[i]);
    }

    return 0;
} 