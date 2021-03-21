#include <stdlib.h>
#include <stdio.h>

struct Set
{
    int* data;
    int size;
};

struct Set* initialize(){
    struct Set *set = (struct Set *) malloc(sizeof(struct Set));
    if(set != NULL){
        set->data = NULL;
        set->size = 0;
        return set;
    }
    return NULL;
} 

void push(struct Set *set, int element){
    set->size += 1;
    int *newData = (int *) malloc(sizeof(int) * set->size);

    for (int i = 0; i < set->size-1; i++)
    {
        newData[i] = set->data[i];
    }

    newData[set->size-1] = element;
    set->data = newData;

    return;
      
};

void pop(struct Set *set, int index){
    if(index > (set->size-1)){
        return;
    }
    int *newData = (int *)malloc(sizeof(set->size-1));
    set->size -= 1;

    int oldIndex, newIndex = 0;
    while (oldIndex < set->size)
    {
        if(oldIndex == index){
            oldIndex++;
            continue;
        }
        newData[newIndex] = set->data[oldIndex];

        oldIndex++;
        newIndex++;
    }
    return;
    
}

int indexOf(struct Set *set, int element){
    for (int i = 0; i < set->size; i++)
    {
        if(set->data[i] == element){
            return i;
        }
    }
    return -1;
}

int smallerValue(struct Set *set){
    int smaller = set->data[0];
    for (int i = 0; i < set->size; i++){
        if(set->data[i] < smaller){
            smaller = set->data[i];
        }
    }
    return smaller;
}

struct Set* setUnion(struct Set *set1, struct Set *set2){
    struct Set *newSet = (struct Set*)malloc(sizeof(struct Set));
    newSet->size = ((set1->size + set2->size));
    newSet->data = (int*) malloc((set1->size + set2->size));

    int index = 0;
    for (int i = 0; i < set1->size; i++)
    {
        newSet->data[index] = set1->data[i];
        index++;
    }
    for (int j = 0; j < set2->size; j++)
    {
        newSet->data[index] = set2->data[j];
        index++;
    }

    return newSet;
    
}

void printSet(struct Set *set){
    printf("Tamanho do conjunto: %d\n", set->size);
    printf("[");
    for (int i = 0; i < set->size; i++)
    {
        printf(" %d,", set->data[i]);
    }
    printf("]\n");
    return;
}

int isSameSet(struct Set *set1, struct Set *set2){
    if(set1->size != set2->size){
        return 0;
    }
    for (int i = 0; i < set1->size; i++)
    {
        if(set1->data[i] != set2->data[i]){
            return 0;
        }
    }
    return 1;
    
}

int isEmptySet(struct Set *set){
    return set->size == 0? 1:0;
}

int main(void){

    struct Set *set = initialize();
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

    struct Set *set2 = initialize();
    push(set2, 80);
    push(set2, 12);
    push(set2, 13);
    push(set2, 7);

    printf("Conjunto 1: \n");
    printSet(set);
    printf("Conjunto 2: \n");
    printSet(set2);

    struct Set *bigSet = setUnion(set, set2);
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
    struct Set *emptySet = initialize();
    int isEmpty = isEmptySet(emptySet);
    printf("Caso seja vazio o resultado é: %d\n", isEmpty);
    isEmpty = isEmptySet(set);
    printf("Caso não seja vazio o resultado é: %d\n", isEmpty);


    return 0;
}