#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hermanos.h"
int menu(void)
{
    int opcion;
    printf("\n *** ASIGNACION DE SALIDAS ***       (Soporte. 1159923631)");
    printf("\n1. Generar salidas automaticamente");
    printf("\n2. Editar lista de hermanos");
    printf("\n3. Editar lugares de salida");
    printf("\n4. Salir");
    printf("\n\n Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void editarListaHermanos(hermano * listaHermanos, FILE * flistaHermanos,int longitudLista)
{
    int opcion;
    hermano* aux;
    //int auxInt;
    //int len=1;
    //int cant;
    //FILE * r;
    //int listaHnos;

    system("cls");
    printf("*** EDITAR LISTA DE HERMANOS ***");
    printf("\n Que desea hacer?");
    printf("\n 1. Agregar hermano");
    printf("\n 2. Bajar hermano");
    printf("\n 3. Ir a menu principal\n");
    scanf("%d",&opcion);
    switch(opcion)
    {
    case 1:



        add_hermano(listaHermanos,flistaHermanos,longitudLista);
        if(listaHermanos==NULL)
        {
            printf("ERROR AL AGREGAR EL NUEVO HERMANO");
            system("pause");
            break;
        }
        printf("\nEl hermano ha sido agregado con exito");
        /*fseek(flistaHermanos,0L,SEEK_END);
        aux = add_hermano(listaHermanos);
        if(aux==NULL)
        {
            printf("ERROR AL AGREGAR EL NUEVO HERMANO");
            system("pause");
            break;
        }
        listaHermanos = aux;
        //strlen(listaHermanos);

        printf("%d,%s,%s,%d,%d\n",(listaHermanos+(len))->id,(listaHermanos+(len))->nombre,(listaHermanos+(len))->apellido,(listaHermanos+(len))->grupo,(listaHermanos+(len))->estado);

        cant = fprintf(flistaHermanos,"%d,%s,%s,%d,%d\n",(listaHermanos+(len-1))->id,(listaHermanos+(len-1))->nombre,(listaHermanos+(len-1))->apellido,(listaHermanos+(len-1))->grupo,(listaHermanos+(len-1))->estado);
        if(cant<5)
        {
            printf("\nError al cargar el hermano al archivo de lista de hermanos");
        }*/
        break;
    case 2:
        break;
    case 3:
        system("cls");
        break;
    }


    //fclose(listaHnos);
}

hermano* new_hermano()
{
    hermano *hno = (hermano*) malloc (sizeof(hermano));
    if(hno != NULL)
    {
        hno->id=0;
        strcpy(hno->nombre,"");
        strcpy(hno->apellido,"");
        hno->grupo=0;
        hno->estado=0;
    }
    return hno;
}

hermano* new_hermanoParam(int id,char *nombre, char *apellido, int grupo,int estado)
{
    hermano *hno = (hermano*) malloc (sizeof(hermano));
    if(hno!=NULL)
    {
        hno->id = id;
        strcpy(hno->nombre,nombre);
        strcpy(hno->apellido,apellido);
        hno->grupo = grupo;
        hno->estado = estado;
    }
    return hno;
}


int cargarListaHermanos(FILE * listaHnos, hermano* listaHno)
{

    int cant;
    hermano *listaHermanos = (hermano*) malloc (sizeof(hermano));
    int contador=0;
    char buffer[5][31];
    hermano *newHno = (hermano*) malloc (sizeof(hermano));
    hermano *auxHno; //= (hermano*) malloc (sizeof(hermano));
    rewind(listaHnos);
    while(!feof(listaHnos))
    {
        fflush(stdin);
        cant = fscanf(listaHnos,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);

        if(cant<5)
        {
            if(!feof(listaHnos))
            {
                printf("\n\nHubo un error antes del final de archivo\n\n");
            }
            break;

        }
        printf("%s,%s,%s,%s,%s\n",buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
        newHno = new_hermanoParam(atoi(buffer[1]),buffer[2],buffer[3],atoi(buffer[4]),atoi(buffer[5]));
        if(newHno == NULL)
        {
            printf("\n\nError en la carga de lista hermanos");
            return NULL;
        }
        *(listaHermanos+contador) = *newHno;
        contador++;

        auxHno = (hermano*) realloc (listaHermanos,sizeof(listaHermanos)+sizeof(hermano));

        //auxHno = (hermano*) malloc (sizeof(hermano)* (contador+1));
        if(auxHno == NULL)
        {
            printf("\n\nError en la carga de lista hermanos");
            return NULL;
        }
        listaHno = auxHno;

    }

    return contador;

}


hermano* add_hermano(hermano * listaHermanos, FILE * flistaHermanos,int longitudLista)
{
    //int len=0;
    int cant;
    hermano* nuevoHermano;
    hermano* auxHno;
    char * idAnterior = (char *) malloc (sizeof(char)*5);
    int id;
    //long estadoLista;
    char nombre[31];
    char apellido[31];
    int grupo;
    //int estado;

    printf("Usted ha precionado agregar hermano. Tenga en cuenta que \nse utilizara un ID para cada hermano ingresado.\n");
    printf("El mismo es unico y no vuelve a repetirse por mas que\n se elimine al hermano de sistema, por eso, trate de\n agregar cada hermano consientemente.\n");
    printf("\nPrecione cualquier tecla si ha leido el mensaje anterior\n");
    system("pause");
    system("cls");
    printf("\nIngrese nombre(No debe superar los 30 caracteres): ");
    fflush(stdin);
    gets(nombre);
    printf("\nIngrese apellido(No debe superar los 30 caracteres): ");
    fflush(stdin);
    gets(apellido);
    printf("\nIngrese grupo");
    scanf("%d",&grupo);
    rewind(flistaHermanos);
    if(longitudLista)
    {

        fseek(flistaHermanos,(long) (longitudLista-1)*(sizeof(hermano)),SEEK_END);
        fscanf(flistaHermanos,"%[^,]",idAnterior);
        id=atoi(idAnterior)+1;
        printf("\n\n longitud lista %d",longitudLista);
        printf("\n\n id=atoi(idAnterior)+1 => %d",id);
        nuevoHermano = new_hermanoParam(id,nombre,apellido,grupo,1);
        if(nuevoHermano==NULL)
        {
            printf("\nNo se ha podido agregar nuevo hermano");
            system("pause");
            return NULL;
        }
        fseek(flistaHermanos,0L,SEEK_END);
        fflush(stdin);
        cant = fprintf(flistaHermanos,"%d,%s,%s,%d,%d\n",nuevoHermano->id,nuevoHermano->nombre,nuevoHermano->apellido,nuevoHermano->grupo,nuevoHermano->estado);
        if(cant < 5)
        {
            printf("Error al escribir los datos");
        }
    }
    else
    {
        nuevoHermano = new_hermanoParam(1,nombre,apellido,grupo,1);
        if(nuevoHermano==NULL)
        {
            printf("\nNo se ha podido agregar nuevo hermano");
            system("pause");
            return NULL;
        }
        fseek(flistaHermanos,0L,SEEK_END);
        fflush(stdin);
        cant = fprintf(flistaHermanos,"%d,%s,%s,%d,%d\n",nuevoHermano->id,nuevoHermano->nombre,nuevoHermano->apellido,nuevoHermano->grupo,nuevoHermano->estado);
        if(cant < 5)
        {
            printf("Error al escribir los datos");
        }
    }
    cargarListaHermanos(flistaHermanos,auxHno);





    //fseek(flistaHermanos,0L,SEEK_END);

    /*
    else
    {

        nuevoHermano = new_hermanoParam(1,nombre,apellido,grupo,1);
        if(nuevoHermano==NULL)
        {
            printf("\nNo se ha podido agregar nuevo hermano");
            system("pause");
            return NULL;
        }
        fseek(flistaHermanos,0L,SEEK_SET);
        cant = fprintf(flistaHermanos,"%d,%s,%s,%d,%d\n",nuevoHermano->id,nuevoHermano->nombre,nuevoHermano->apellido,nuevoHermano->grupo,nuevoHermano->estado);
        if(cant != 5)
        {
            printf("Error al escribir los datos");
        }
    }*/
    //listaHermanos = cargarListaHermanos(listaHermanos);

    /*len = strlen(listaHermanos);
    printf("\nlen: %d",len);
    aux = (hermano*) realloc(listaHermanos,sizeof(hermano)*len+sizeof(hermano));
    if(aux == NULL)
    {
        printf("\nNo se ha podido agrandar lista de hermanos");
        system("pause");
        return NULL;
    }
    listaHermanos = aux;*/
    /*id = generarId(listaHermanos);
    if(id == 0)
    {
        printf("\nError al generarse ID");
        system("pause");
    }
    else
    {
        estado = 1;
        aux = (hermano*) realloc (listaHermanos,sizeof(listaHermanos)+sizeof(hermano));
        if(aux!=NULL)
        {
            len += strlen(listaHermanos);
            //printf("\n\nEl valor de len de listaHErmanos en la funcion add_Hermanos es: %d",len);
            listaHermanos = aux;
            nuevoHermano = new_hermanoParam(id,nombre,apellido,grupo,estado);
            if(nuevoHermano == NULL)
            {
                printf("\nERROR AL AGREGAR NUEVO HERMANO (void* add_hermano(hermano *listaHermanos))");
                system("pause");
                return NULL;
            }
            *(listaHermanos+len) = *nuevoHermano;

        }
    }*/

    return listaHermanos;
}
/*int generarId(void* listaHnos)
{
    int id=1;
    id += strlen(listaHnos);
    return id;
}*/

/*int fileEmpty(FILE * flista)
{
    rewind(flista);
    int contador=-1;
    if(!feof(flista))
    {


        contador++;
        printf("\n\nfallo feof");
    }
    return contador;
}*/
void cargarArchivoHermanos(hermano * hnos,FILE * flistaHermanos,int longitudLista)
{
    rewind(flistaHermanos);
    int cant;
    for(int i=0;i<longitudLista;i++)
    {
        cant = fprintf(hnos,"%d,%s,%s,%d,%d\n",atoi((hnos+i)->id),(hnos+i)->nombre,(hnos+i)->apellido,atoi((hnos+i)->grupo),atoi((hnos+i)->estado));
        printf("%d,%s,%s,%d,%d\n",atoi((hnos+i)->id),(hnos+i)->nombre,(hnos+i)->apellido,atoi((hnos+i)->grupo),atoi((hnos+i)->estado));
        if(cant<5)
        {
            printf("Error al cargar el archivo hermanos");
            system("pause");
            break;
        }
    }
}
