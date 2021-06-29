#ifndef DEFTREEBIN
#define DEFTREEBIN

#define TIPO char
#define DIMP "%c"

typedef struct TreeBin{
    TIPO datos;
    struct TreeBin* derecho;
    struct TreeBin* izquierdo;
}nodoBin;

#endif