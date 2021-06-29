#include "defFila.h"

#ifndef FILA
#define FILA

fila* CrearFila(void);
void DestruiFila(fila*);
void Insertar(fila*, TIPO);
TIPO Remover(fila*);
int FilaIsEmpty(fila*);
void Imprimir(fila*);

#endif