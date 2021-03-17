typedef struct Cilinder Cilinder;

Cilinder* initialize(float height, float radius);
//Cria novo cilindro 

float height(Cilinder* cilinder);
//Retorna a altura

float radius(Cilinder* cilider);
//retorna o raio

float volume(Cilinder* cilinder);
//retorna o volume 

float surfaceArea(Cilinder* cilinder);
//retorna a área