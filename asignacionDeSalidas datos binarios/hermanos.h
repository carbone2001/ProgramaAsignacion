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
void editarListaHermanos(FILE * flistaHermanos);
hermano* new_hermanoParam(int id,char *nombre, char *apellido, int grupo,int estado);
hermano* new_hermano();
int cargarListaHermanos(FILE * listaHnos, hermano* listaHno);
void cargarArchivoHermanos(hermano * hnos,FILE * flistaHermanos,int longitudLista);
hermano* add_hermano(FILE * flistaHermanos);
int fileEmpty(FILE * flista);
hermano* listarHermanos(FILE * flistaHermanos);
hermano* delete_hermano(FILE * flistaHermanos);
void* buscarHermanoPor(FILE* flistaHermanos);
void* buscarPorGrupo(FILE * flistaHermanos);
void* editarHermano(FILE *flistaHermanos);
#endif // HERMANOS_H_INCLUDED


