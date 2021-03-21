#include <stdlib.h>
#include <stdio.h>
#include "cilindro.h"

int main(void){
    
    Cilinder* cilinder = initialize(15, 6);
    printf("Cilindro inicializado com tamanho 15 e raio 6\n");

    float h = height(cilinder);
    printf("Altura do cilindro: %.2f\n", h);

    float r = radius(cilinder);
    printf("Raio do cilindro: %.2f\n", r);

    float v = volume(cilinder);
    printf("Volume do cilindro: %.2f\n", v);

    float sa = surfaceArea(cilinder);
    printf("Area do cilindro: %.2f\n", sa);


    return 0;
}