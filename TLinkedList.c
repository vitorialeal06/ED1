#include "TLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no
{
    int info;
    struct _no *prox;
} TNo;

struct _list
{
    TNo *inicio;
};
TNo *TNo_createNFill(int info)
{
    TNo *novo = malloc(sizeof(TNo));
    if (novo)
    {
        novo->info = info;
        novo->prox = NULL;
    }
    return novo;
}

TLinkedList *TLinkedList_create()
{
    TLinkedList *list = malloc(sizeof(TLinkedList));
    if (list != NULL)
        list->inicio = NULL;
    return list;
}
bool TLinkedList_insert_begin(TLinkedList *list, int info)
{
    TNo *novo = TNo_createNFill(info);
    if (novo == NULL)
        return false;
    if (list->inicio != NULL)
        novo->prox = list->inicio;
    list->inicio = novo;
    return true;
}
void TLinkedList_print(TLinkedList *list)
{
    TNo *aux = list->inicio;
    while (aux != NULL)
    {
        printf("%d, ", aux->info);
        aux = aux->prox;
    }
    putchar('\n');
}

bool TLinkedList_insert_end(TLinkedList *list, int info)
{
    TNo *novo = TNo_createNFill(info);
    if (list->inicio == NULL)
        list->inicio = novo;
    else
    {
        TNo *aux = list->inicio;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
}




#include "TLinked_List.h"// usando a interface
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct _no{     // criando uma struct 
    int info;           // recebido pelo usuario  
    struct _no *prox;   // recebe endereco de outra struct do mesmo tipo (proxima caixinha)
}TNo;                   // "apelido da struct _no"

struct _list{       // criada na interface TLinkedList.h
    TNo* inicio;   // do tipo ponteiro da struct TNo, que armazena o endereco anterior. Ela é a unica forma de acessar/nao perder as memorias
};


TNo* TNo_create(int info){             // cria o NO que liga todas as memorias
    TNo* novo = malloc(sizeof(TNo));   // variavel novo do tipo TNo que abre espaco na memoria
    if(novo){                          // se tiver alocado memoria:
        novo->info = info;             // armazena a informação passada na struct
        novo->prox = NULL;             // prox é inicializando com null, ou seja é o primeiro dado armazenado
    }
    return novo;
}

TLinkedList* create(){                                  // esta criando as caixinhas que irao armazenas as informacoes
    TLinkedList * list = malloc(sizeof(TLinkedList));   // aloca espaco para a list do tamanho TLinkedList
    if(list != NULL)                                    // se list != null, ou seja,se estiver com lixo
        list -> inicio = NULL;                          // o campo incio recebe null, demostrando que é o primeiro item do encadeamento
    return list;                                        // retorna a list formada
}



bool insert_begin(TLinkedList* list, int info){         //inserção no começo, ou seja, os ultimos serão os primeiros
    TNo* novo = TNo_create(info);                       // novo é um novo NO criado
    if(novo == NULL)return false;                        // o primeiro valor é sempre null, pq é o primeiro/ultimo item
    if(list->inicio != NULL)                            // como inicio armazena endereco anterior, entao se for != null quer dizer que tem mais itens
        novo->prox = list->inicio;                      //prox recebe endereço que estava em inicio, entao o anterior
    list->inicio = novo;                                // inicio recebe o novo endereco

    return true;                                        // nessse caso prox recebe o anterior e inicio recebe o novo pq é como se estivesse empurrando as caixinhas para direita,
                                                        // a primeira sendo a ultima 
}

bool insert_end(TLinkedList* list, int info){   // inserir no final, entao o novo enderro sera o ultimo
    TNo* novo = TNo_create(info);               //abre espaço de memoria
    if(novo == NULL) return false;              // se for null quer dizer que nao tem mais itens para inserir
    if(list->inicio==NULL)                      // mas se inicio for null, ou seja, primeiro item
        list->inicio = novo;                    // inicio recebe o novo endereco, no caso o atual
    else{                                       
        TNo* aux = list->inicio;                //usa-se variavel auxiliar para receber o endereco anterior
        while(aux->prox != NULL)                // enquanto essa variavel não for null, ou seja, não for a utima,
            aux = aux->prox;                    // auxiliar recebe endereco da proximo item. Isso se repete ate chegar no ultimo item da lista
        aux->prox= novo;                        // assim, o proximo endereco armazenado é o que inserimos, no caso se torna o ultimo item e recebe null
    }

    return true;
}

void Tprint(TLinkedList* list){       // printa a lista
    TNo* aux = list->inicio;          // usa variavel auxiliar que recebe o endereco anterior
    while(aux != NULL){               // e enquanto nao for null, enquando nao for o ultimo item da lista
        printf("%i, ", aux->info);    // vai printando o item
        aux = aux->prox;              // forma de "incrementar" para auxiliar ir passando para os proximos endereços ate chegar ao ultimo (null)
    }
    putchar('\n');                    // so fim de linha
}
