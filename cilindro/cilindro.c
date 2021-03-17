#include <stdlib.h>
#include <math.h>
#include "cilindro.h"

struct Cilinder{
    float height;
    float radius;
};

Cilinder* initialize(float height, float radius){
    Cilinder* c = (Cilinder*) malloc(sizeof(Cilinder));
    if (c != NULL){
        c->height = height;
        c->radius = radius;
    }
    return c;
}

float height(Cilinder* cilinder){
    if (cilinder != NULL){
        return cilinder->height;
    }
    return -1;
}

float radius(Cilinder* cilinder){
    if (cilinder != NULL){
        return cilinder->radius;
    }
    return -1;
}

float volume(Cilinder* cilinder){
    if(cilinder == NULL){
        return -1;
    }
    float c_height = cilinder->height;
    float c_radius = cilinder->radius;

    float volume = (M_PI * c_radius*c_radius *c_height);

    return volume;
}

float surfaceArea(Cilinder* cilinder){
    if(cilinder == NULL){
        return -1;
    }
    float c_height = cilinder->height;
    float c_radius = cilinder->radius;

    float circunference = (M_PI * c_radius *2);

    float circularArea = (M_PI * c_radius*c_radius *2/*Dois círculos*/);
    float rectangularArea = (circunference * c_height);

    return (circularArea + rectangularArea);
}



