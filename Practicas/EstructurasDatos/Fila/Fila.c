#include <stdio.h>
#include <stdlib.h>
#include "defFila.h"

fila* CrearFila(void){
    fila* aux = (fila*)malloc(sizeof(fila));
    if (aux == NULL){
        perror("Error al obtener datos;");
        exit(EXIT_FAILURE);
    }
    aux->length = 0;
    aux->inicio = 0;
    aux->fin = 0;
    return aux;
}
void DestruiFila(fila* fila_F){
    free(fila_F);
}

void Insertar(fila* fila_F, TIPO dato){
    if (fila_F->length == 0){
        fila_F->datos = (TIPO*)malloc(sizeof(TIPO)*3);
        if (fila_F->datos == NULL){
            perror("Error al recervar memoria");
            exit(EXIT_FAILURE);
        }
        fila_F->length = 3;
    }else if(fila_F->length == fila_F->fin){
        fila_F->datos = (TIPO*)realloc(fila_F->datos,sizeof(TIPO)*fila_F->length+3);
        if (fila_F->datos == NULL){
            perror("Error al recervar memoria");
            exit(EXIT_FAILURE);
        }
        fila_F->length = fila_F->length + 3;
    }
    *(fila_F->datos+fila_F->fin++) = dato;
}
TIPO Remover(fila* fila_F){
    if (fila_F->inicio == fila_F->fin||fila_F->length == 0||fila_F ==NULL){
        printf("Fila vacia");
        exit(EXIT_FAILURE);
    }
    return fila_F->datos[fila_F->inicio++]; 
}
int FilaIsEmpty(fila* fila_F){
    if (fila_F == NULL){
        printf("Fila no existe");
        return -1;
    }else if (fila_F->inicio == fila_F->fin){
        return 1;
    }
    return 0;
}
void Imprimir(fila* fila_F){
    if(fila_F == NULL){
        printf("No existe la fila");
    }else{
        printf("INFO Fila: Inicio: %d, Fin: %d, len: %d, cap: %d\n",fila_F->inicio,fila_F->fin,fila_F->fin-fila_F->inicio,fila_F->length);
        for(int ind = fila_F->inicio; ind < fila_F->fin; ind++){
            printf("|");
            printf(DIMP,fila_F->datos[ind]);
            printf("|");
        }
        printf("\n");
    }
}
