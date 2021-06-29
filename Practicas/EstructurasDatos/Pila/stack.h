#include "defStack.h"
#ifndef STACK
#define STACK

stack* CrearStack(void);
void DestruirStack(stack*);
void Push(stack*,TIPO);
void Imprimir(stack*);
TIPO Pop(stack*);
int empty(stack*);
TIPO stacktop(stack* pila);

#endif