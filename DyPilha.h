#ifndef DYPILHA_H
#define DYPILHA_H

typedef struct _list Stack;

Stack* create();
bool push(Stack*, int);
bool pop(Stack*, int);
int head(Stack*, int);
int qty(Stack*);
void destroy(Stack*);
bool full(Stack*);
bool empty(Stack*);


#endif
