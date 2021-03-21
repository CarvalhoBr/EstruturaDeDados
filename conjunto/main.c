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

int main(void){

    struct Set *set = initialize();
    printf("Conjunto inicializado, tamanho: %d\n", set->size);

    push(set, 3);
    printf("Adicionado 3, tamanho: %d, ultimo elemento: %d\n", set->size, set->data[set->size-1]);
    push(set, 5);
    printf("Adicionado 5, tamanho: %d, ultimo elemento: %d\n", set->size, set->data[set->size-1]);

    pop(set, 1);
    printf("Removendo ultimo elemento, tamanho: %d, ultimo elemento: %d\n", set->size, set->data[set->size-1]);

    push(set, 5);

    printf("Testando se o elemento 15 pertence ao conjunto\n");
    int index = indexOf(set, 15);
    printf("Caso o elemento não pertença o resultado é: %d\n", index);
    index = indexOf(set, 5);
    printf("Caso o elemento pertença é retornado a posição dele na coleção. Exemplo: indexOf(set, 5) = %d\n", index);
    
    return 0;
}