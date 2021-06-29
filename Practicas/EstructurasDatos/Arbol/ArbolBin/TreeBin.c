#include <stdio.h>
#include <stdlib.h>
#include "defTreeBin.h"


nodoBin* CrearNodoBinario(TIPO data){
    nodoBin* aux = (nodoBin*)malloc(sizeof(nodoBin));
    if ( aux == NULL ){
        perror("Error al crear nodo Binario");
        exit(EXIT_FAILURE);
    }
    aux->datos = data;
    aux->derecho = aux->izquierdo = NULL;
    return aux;
}
void AgregarNodoBinario(nodoBin* padre, nodoBin* hijo, short lado){
    /*
        lado:
            -1 = lado izquierdo
             1 = lado derecho
    */
    if ( padre == NULL || hijo == NULL || lado == 0){
        perror("Error al agregar nodo Binario");
        exit(EXIT_FAILURE);
    }
    if( lado == -1 ){
        padre->izquierdo = hijo;
    }else if( lado == 1){
        padre->derecho = hijo;
    }
}
void DestruirNodobinario(nodoBin* nodo){
    free(nodo);
}
void CambioDeNodo_IzDe(nodoBin* padre){
    nodoBin* aux = padre->izquierdo;
    padre->izquierdo = padre->derecho;
    padre->derecho = aux;
}
void PreOrden(nodoBin* nodo){
    printf("%d->",nodo->datos);
    if (nodo->izquierdo != NULL)
        PreOrden(nodo->izquierdo);
    if (nodo->derecho != NULL)
        PreOrden(nodo->derecho);
}
void InOrden(nodoBin* nodo){
    if (nodo->izquierdo != NULL)
        InOrden(nodo->izquierdo);
    printf("%d->",nodo->datos);
    if (nodo->derecho != NULL)
        InOrden(nodo->derecho);
}
void PostOrden(nodoBin* nodo){
    if (nodo->izquierdo != NULL)
        PostOrden(nodo->izquierdo);
    if (nodo->derecho != NULL)
        PostOrden(nodo->derecho);
    printf("%d->",nodo->datos);
}
