#ifndef DEFILA
#define DEFILA

//Declaracion de macros
#define TIPO int

#if TIPO == int
    #define DIMP "%d"
#elif TIPO == float
    #define DIMP "%f"
#elif TIPO == char
    #define DIMP "%c"
#elif TIPO == double
    #define DIMP "%lf"
#elif TIPO == long double
    #define DIMP "%Lf"
#elif TIPO == long
    #define DIMP "%ld"
#endif

//Definicion de estructuras
typedef struct Fila{
    int length;
    int inicio;
    int fin;
    TIPO* datos;
}fila;

#endif