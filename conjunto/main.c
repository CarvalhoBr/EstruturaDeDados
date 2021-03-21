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

int main(void){

    struct Set *set = initialize();
    printf("Conjunto inicializado, tamanho: %d\n", set->size);

    push(set, 3);
    printf("Adicionado 3, tamanho: %d, ultimo elemento: %d\n", set->size, set->data[set->size-1]);
    return 0;
}