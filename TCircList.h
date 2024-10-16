#ifndef TCIRC_LIST_H
#define TCIRC_LIST_H
#include <stdbool.h>

typedef struct tcirc_list TCircList;

TCircList *TCircList_create();
/**
 * Insere um elemento inteiro na lista circular
 */
bool TCircList_insert_begin(TCircList *, int);
/**
 * Imprime a lista circular
 */
bool TCircList_insert_end(TCircList *, int);
void TCircList_print(TCircList *);

#endif
