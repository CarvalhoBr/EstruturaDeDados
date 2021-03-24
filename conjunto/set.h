#include <stdlib.h>
#include <stdio.h>

typedef struct Set{
    int* data;
    int size;
} Set;

Set* initialize();

void push(Set *set, int element);

void pop(Set *set, int element);

int indexOf(Set *set, int element);

int smallerValue(Set *set);

Set* setUnion(Set *set1, Set *set2);

void printSet(Set *set);

int isSameSet(Set *set1, Set *set2);

int isEmptySet(Set *set);