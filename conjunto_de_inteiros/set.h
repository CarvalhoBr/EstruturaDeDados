#include <stdbool.h>

int* initialize();

//Adiciona um elemento na última posição
int* push(int* vet, int element);

//Retira o elemento da posição index do array
void pop(int* vet[], int index);

//Checa se o elemento pertence ao array, caso sim retorna o índice, caso não retorna -1
int findIndex(int* vet[], int element);

//Retorna o menor valor
int smallerValue(int* vet[]);

//União de dois conjuntos
int setUnion(int* vet[], int* vet2[]);

//Dois conjuntos são iguais
bool isEqual(int* vet[], int* vet2[]);

//Testar se um conjunto é vazio
bool isEmpty(int* vet[]);




