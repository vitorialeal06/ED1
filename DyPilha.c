#include "DyPilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

struct _list{
    TNo* inicio;
    int qty;
};

TNo* Nfill(int info){
    TNo* novo = malloc(sizeof(TNo));
    if(novo){
        novo->info = info;
        novo->prox = NULL;
    }
    return novo;
}

Stack* create(){
    Stack* list = malloc(sizeof(Stack));
    if(list){
        list->inicio = NULL;
        list->qty = 0;
    }
    return list;

}
bool push(Stack* list, int info){
    TNo* novo = Nfill(info);
    if(!novo) return false;
    if(full(list)) return false;

    novo->prox = list->inicio;
    list->inicio = novo;
    list->qty++;
    return true;
}

bool pop(Stack* list, int* info){
    if(empty(list) || list== NULL) return false;
    info* = list->inicio->info;
    TNo* aux = list->inicio;
    list->inicio = list->inicio->prox;
    free(aux);
    list->qty--;
    
    return true;
}

int head(Stack* list, int* info){
    if(empty(list)) return false;
    info* = list->inicio->info;
    return true;
}

int qty(Stack* list){
    return list->qty;
}
bool destroy(Stack* list){
    TNo* aux = list->inicio;
    while(aux != NULL){
        free(aux);
        aux = aux->prox;
    }
    free(list);
    return true;
}

bool full(Stack* list){
    return false;

}

bool empty(Stack* list){
    return list->qty == 0;
}
