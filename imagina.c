#include "imagina.h"
#include <stdio.h>
#include <stdlib.h>

struct _imaginario{
    int a,i;
    
};

Imagina* create(int a , int i){
    Imagina* novo = (Imagina*)malloc(sizeof(Imagina));
    if(novo != NULL){
        novo -> a = a;
        novo -> i = i;
    }
    return novo;
}

void destroy(Imagina* imagina){
    free(imagina);
}

void soma(Imagina* x1, Imagina* x2){
    int num = x1->a + x2->a;
    int im = x1->i + x2->i;
    printf("a soma é: %i + %ii", num, im);
}

void subtracao(Imagina* x1, Imagina* x2){
    int num = x1->a - x2->a;
    int im = x1->i - x2->i;
    printf("a subtracao é: %i - %ii", num, im);
}

