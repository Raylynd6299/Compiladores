#include <stdio.h>
#include <stdlib.h>

#define TIPO int


//Cambiar implementacion a usar Lista
typedef struct Nodo_A{
    TIPO data;
    int NumChil;
    struct Nodo_A** children;
}nodeT;

nodeT* CrearNodo(void){
    nodeT* nodeAux = NULL;
    nodeAux = (nodeT *)malloc(sizeof(nodeT));
    if (nodeAux == NULL){
        perror("Error al crear el nodo;");
        exit(EXIT_FAILURE);
    }
    nodeAux->NumChil = 0;
    nodeAux->children = NULL;

    return nodeAux;
}
void InsertNodo(nodeT* nodoF,nodeT* nodoC){
    if(nodoF == NULL||nodoC == NULL){
        printf("Nodo Padre no existe");
        return;
    }
    if (nodoF->NumChil == 0){
        nodoF->children = (nodeT**)malloc(sizeof(nodeT*)*3);
        if(nodoF->children == NULL){
            perror("Error al reservar memoria");
            exit(EXIT_FAILURE);
        }
        for(int ind = 0;ind < 3; ind++)
            *(nodoF->children+ind) = NULL;

        nodoF->NumChil = 3;
    }
    
    short flag = 0;
    for (int ind = 0; ind < nodoF->NumChil; ind++){
        if ( *(nodoF->children+ind) == NULL ){
            *(nodoF->children+ind) = nodoC;
            flag = 1;
            break;
        }
    }
    if (flag == 1){
        nodoF->children = (nodeT**)realloc(nodoF->children,nodoF->NumChil+3);
        if(nodoF->children == NULL){
            perror("Error al reservar memoria");
            exit(EXIT_FAILURE);
        }
        for(int ind = nodoF->NumChil; ind < nodoF->NumChil+3;ind++){
            *(nodoF->children+ind) = NULL;
        }
        *(nodoF->children+nodoF->NumChil) = nodoC;
        nodoF->NumChil = nodoF->NumChil + 3;
    }
}
void RemoverNodoNum(nodeT* nodoF,int NumN){
    if (NumN < nodoF->NumChil && NumN >=0){
        *(nodoF->children+NumN) = NULL;
    }
}
void RemoverNodoRef(nodeT* nodoF,nodeT* nodoE){
    for (int ind = 0; ind < nodoF->NumChil; ind++ ){
        if( *(nodoF->children+ind) == nodoE ){
            *(nodoF->children+ind) = NULL;
            printf("Eliminado");
        }
    }
}
int main(void){
    return 0;
}