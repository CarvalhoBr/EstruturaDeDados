#include "set.h"

Set* initialize(){
    Set *set = (Set *) malloc(sizeof(Set));
    if(set != NULL){
        set->data = NULL;
        set->size = 0;
        return set;
    }
    return NULL;
} 

void push(Set *set, int element){
    set->size += 1;
    int *newData = (int *) malloc(sizeof(int) * set->size);

    for (int i = 0; i < set->size-1; i++)
    {
        newData[i] = set->data[i];
    }

    newData[set->size-1] = element;

    free(set->data);
    set->data = newData;

    return;  
};

void pop(Set *set, int index){
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
    free(set->data);
    set->data = newData;

    return;
}

int indexOf(Set *set, int element){
    for (int i = 0; i < set->size; i++)
    {
        if(set->data[i] == element){
            return i;
        }
    }
    return -1;
}

int smallerValue(Set *set){
    int smaller = set->data[0];
    for (int i = 0; i < set->size; i++){
        if(set->data[i] < smaller){
            smaller = set->data[i];
        }
    }
    return smaller;
}

Set* setUnion(Set *set1, Set *set2){
    Set *newSet = (Set*)malloc(sizeof(Set));
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

void printSet(Set *set){
    printf("Tamanho do conjunto: %d\n", set->size);
    printf("[");
    for (int i = 0; i < set->size; i++)
    {
        printf(" %d,", set->data[i]);
    }
    printf("]\n");
    return;
}

int isSameSet(Set *set1, Set *set2){
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

int isEmptySet(Set *set){
    return set->size == 0? 1:0;
}