#include <stdlib.h>
#include <stdio.h>
#ifndef HERMANOS_H_INCLUDED
#define HERMANOS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[21];
    char apellido[21];
    int grupo;
    int estado;

}hermano;

int menu(void);
void editarListaHermanos(hermano * listaHermanos, FILE * flistaHermanos,int longitudLista);
hermano* new_hermanoParam(int id,char *nombre, char *apellido, int grupo,int estado);
hermano* new_hermano();
int cargarListaHermanos(FILE * listaHnos, hermano* listaHno);
void cargarArchivoHermanos(hermano * hnos,FILE * flistaHermanos,int longitudLista);
hermano* add_hermano(hermano * listaHermanos, FILE * flistaHermanos,int longitudLista);
int fileEmpty(FILE * flista);
#endif // HERMANOS_H_INCLUDED


