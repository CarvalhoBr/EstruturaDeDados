#include <stdlib.h>
#include <stdio.h>
#include "cilindro.h"

int main(void){
    
    Cilinder* cilinder = initialize(15, 6);
    float h = height(cilinder);
    printf("%f", h);

    return 0;
}