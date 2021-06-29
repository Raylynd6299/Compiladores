#ifndef DELISTH
#define DELISTH

#define TIPO int

typedef struct nodo{
    TIPO datos;
    struct nodo* sig;
}List;

#endif