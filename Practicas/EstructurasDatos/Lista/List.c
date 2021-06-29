#include <stdio.h>
#include <stdlib.h>
#include "defList.h"


void MostrarLista( List *lista ){
    for( ; lista ; lista = lista->sig )
        printf("|%d|", lista->datos );
    printf("\n");
}

void EliminarLista( List *lista ){
    List *aux = NULL;
    if ( lista ){
        while ( lista ){
            aux = lista;
            lista = lista->sig;
            free( aux );
        }
    }
}

List* CrearNodoLista( TIPO dato ){
    List *Nuevo = (List*) malloc ( sizeof( List ) );
    if ( !Nuevo ){
        perror( "Error al crear nodo de la Lista" );
        exit(EXIT_FAILURE);
    }
    Nuevo->datos = dato;
    Nuevo->sig = NULL;
    return Nuevo;
}

int ListaVacia( List *lista ){
    return ( lista == NULL );
}

void Append( List **lista, TIPO nodo ){

    List *aux = *lista;
    if( !(*lista) ){
        (*lista) = CrearNodoLista( nodo );
        return ;
    }

    while( aux->sig  != NULL )
        aux = aux->sig;

    aux->sig = CrearNodoLista( nodo );

}

void EliminarNodoLista( List **lista, TIPO dato){

    if ( !lista ){
        perror( "Error lista vacia" );
        exit(EXIT_FAILURE);
    }
    
    List *ant = NULL, *act = NULL;
        
    act = *lista;
    while( act ){
        if ( act->datos == dato )
            break;
        
        ant = act;
        act = act->sig;
    }
    if ( !ant ){
        *lista = act->sig;
    }else if( !act->sig ) {
        ant->sig = NULL;
    }else{
        ant->sig = act->sig;
    }
}

