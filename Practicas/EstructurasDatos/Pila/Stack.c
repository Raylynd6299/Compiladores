#include <stdio.h>
#include <stdlib.h>
#include "defStack.h"


stack* CrearStack(void){
    stack* pila = (stack*)malloc(sizeof(stack));
    if (pila == NULL){
        perror("Error al recervar memoria");
        exit(EXIT_FAILURE);
    }
    pila->top = 0;
    pila->longitud = 0;
    return pila;
}
void DestruirStack(stack *stack){
    free(stack);
}

void Push(stack* pila,TIPO dato){
    if (pila->longitud == 0){
        pila->datos = (TIPO*)malloc(sizeof(TIPO)*3);
        if (pila->datos == NULL){
            perror("Error al recervar memoria");
            exit(EXIT_FAILURE);
        }
        pila->longitud = 3;
    }else if(pila->longitud == pila->top){
        pila->datos = (TIPO*)realloc(pila->datos,sizeof(TIPO)*pila->longitud+3);
        if (pila->datos == NULL){
            perror("Error al recervar memoria");
            exit(EXIT_FAILURE);
        }
        pila->longitud = pila->longitud + 3;
    }
    *(pila->datos+pila->top++) = dato;
}
TIPO Pop(stack* pila){
    if (pila->top == 0){
        perror("StackUnderFlow");
        exit(EXIT_FAILURE);
    }    
    return *(pila->datos+(--pila->top));
}
void Imprimir(stack* pila){
    if(pila == NULL){
        printf("No existe la pila");
    }else
        for(int ind = pila->top-1; ind > -1; ind--){
            printf("|");
            printf(DIMP,pila->datos[ind]);
            printf("|\n");
        }
}
int empty(stack* pila){
    return (pila->top == 0) ? 1: 0;
}
TIPO stacktop(stack* pila){
    return pila->datos[pila->top-1];
}