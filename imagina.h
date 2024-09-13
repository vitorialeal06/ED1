#ifndef IMAGINA_H
#define IMAGINA_H

typedef struct _imaginario Imagina;

Imagina* create(int, int);
void destroy(Imagina*);
void soma(Imagina*, Imagina*);
void subtracao(Imagina*, Imagina*);

#endif
