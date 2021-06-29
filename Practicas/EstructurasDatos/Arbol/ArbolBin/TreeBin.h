#include "defTreeBin.h"
#ifndef TREEBIN
#define TREEBIN

nodoBin* CrearNodoBinario(TIPO);
void AgregarNodoBinario(nodoBin*, nodoBin*, short);
void DestruirNodobinario(nodoBin *);
void CambioDeNodo_IzDe(nodoBin*);
void PreOrden(nodoBin*);
void InOrden(nodoBin*);
void PostOrden(nodoBin*);


#endif