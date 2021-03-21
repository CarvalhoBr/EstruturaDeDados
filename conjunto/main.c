#include <stdlib.h>
#include <stdio.h>
#include "set.h"

int main(void){

    Set *set = initialize();
    printf("Conjunto inicializado, tamanho: %d\n", set->size);

    printf("\n-------------------------------------------------------------------------------\n\n");

    push(set, 3);
    printf("Adicionado 3, tamanho: %d, ultimo elemento: %d\n", set->size, set->data[set->size-1]);
    push(set, 5);
    printf("Adicionado 5, tamanho: %d, ultimo elemento: %d\n", set->size, set->data[set->size-1]);

    printf("\n-------------------------------------------------------------------------------\n\n");

    pop(set, 1);
    printf("Removendo ultimo elemento, tamanho: %d, ultimo elemento: %d\n", set->size, set->data[set->size-1]);

    push(set, 5);

    printf("\n-------------------------------------------------------------------------------\n\n");

    printf("Testando se o elemento 15 pertence ao conjunto\n");
    int index = indexOf(set, 15);
    printf("Caso o elemento não pertença o resultado é: %d\n", index);
    index = indexOf(set, 5);
    printf("Caso o elemento pertença é retornado a posição dele na coleção. Exemplo: indexOf(set, 5) = %d\n", index);

    printf("\n-------------------------------------------------------------------------------\n\n");

    push(set, 9);
    push(set, 1);
    push(set, 6);

    int smaller = smallerValue(set); 
    printf("Testando o menor valor, esperado: 1, retorno: %d\n", smaller);

    printf("\n-------------------------------------------------------------------------------\n\n");

    printf("Printando o conjunto: \n");
    printSet(set);

    printf("\n-------------------------------------------------------------------------------\n\n");

    Set *set2 = initialize();
    push(set2, 80);
    push(set2, 12);
    push(set2, 13);
    push(set2, 7);

    printf("Conjunto 1: \n");
    printSet(set);
    printf("Conjunto 2: \n");
    printSet(set2);

    Set *bigSet = setUnion(set, set2);
    printf("União dos dois conjuntos: \n");
    printSet(bigSet);

    printf("\n-------------------------------------------------------------------------------\n\n");

    printf("Testando se dois conjuntos são exatamente iguais: \n");
    int isEqual = isSameSet(set, set);
    printf("Caso sejam iguais o resultado é: %d\n", isEqual);
    isEqual = isSameSet(set, set2);
    printf("Caso sejam diferentes o resultado é: %d\n", isEqual);

    printf("\n-------------------------------------------------------------------------------\n\n");

    printf("Testando se um conjunto é vazio: \n");
    Set *emptySet = initialize();
    int isEmpty = isEmptySet(emptySet);
    printf("Caso seja vazio o resultado é: %d\n", isEmpty);
    isEmpty = isEmptySet(set);
    printf("Caso não seja vazio o resultado é: %d\n", isEmpty);


    return 0;
}