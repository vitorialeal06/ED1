#include "TCircList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no
{
    int info;
    struct _no *prox;
} TNo;

struct tcirc_list
{
    TNo *inicio;
};

TNo *TNo_createNFill(int info)
{
    TNo *novo = malloc(sizeof(TNo));
    if (novo)
    {
        novo->info = info;
        novo->prox = novo;
    }
    return novo;
}

TCircList *TCircList_create()
{
    TCircList *list = malloc(sizeof(TCircList));
    if (list != NULL)
        list->inicio = NULL;
    return list;
}

bool TCircList_insert_begin(TCircList *list, int info)
{
    TNo *novo = TNo_createNFill(info);
    if (novo == NULL)
        return false;

    if (list->inicio == NULL)
    {
        list->inicio = novo;
        novo->prox = novo;
    }

    TNo *aux = list->inicio;

    aux = aux->prox;
    while (aux->prox != list->inicio)
        aux = aux->prox;
    aux->prox = novo;
    novo->prox = list->inicio;
    list->inicio = novo;

    return true;
}

bool TCircList_insert_end(TCircList *list, int info)
{

    TNo *novo = TNo_createNFill(info);
    if (novo == NULL)
        return false;

    if (list->inicio == NULL)
    {
        list->inicio = novo;
        novo->prox = novo;
    }

    TNo *aux = list->inicio;

    aux = aux->prox;
    while (aux->prox != list->inicio)
        aux = aux->prox;
    aux->prox = novo;
    novo->prox = list->inicio;

    return true;
}

void TCircList_print(TCircList *list)
{

    TNo *aux = list->inicio;
    do
    {

        printf("%d", aux->info);
        aux = aux->prox;
    } while (aux != list->inicio);
}
