#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hermanos.h"
#include "inputs.h"
int menu(void)
{
    int opcion;
    printf("*** ASIGNACION DE SALIDAS ***       (Soporte. 1159923631)");
    printf("\n1) Generar salidas automaticamente");
    printf("\n2) Editar lista de hermanos");
    printf("\n3) Editar lugares de salida");
    printf("\n4) Salir");
    printf("\n\n Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void editarListaHermanos(FILE * flistaHermanos)
{
    int cant;
    int opcion;
    hermano* hno;
    hermano* error;

    hno = new_hermano();
    flistaHermanos = fopen("listaDeHermanos.bin","rb+");
    if(flistaHermanos == NULL)
    {
        flistaHermanos = fopen("listaDeHermanos.bin","wb+");
        if(flistaHermanos == NULL)
        {
            printf("\n Error al crear el fichero de hermanos.");
            system("pause");
        }
        printf("\nAtencion! Se ha creado un nuevo fichero de hermanos");
        system("pause");

    }

    fseek(flistaHermanos,0L,SEEK_SET);
    cant = fwrite(hno,sizeof(hermano),1,flistaHermanos);
    if(cant != 1)
    {
        printf("Error al crear el hermano de cabezera fantasma");
        system("pause");
    }

    system("cls");
    printf("*** EDITAR LISTA DE HERMANOS ***");
    printf("\n Que desea hacer?");
    printf("\n 1. Agregar hermano");
    printf("\n 2. Eliminar hermano");
    printf("\n 3. Ver lista de hermanos");
    printf("\n 4. Buscar hermano");
    printf("\n 5. Editar hermano");
    printf("\n 6. Ir a menu principal\n");
    scanf("%d",&opcion);
    switch(opcion)
    {
    case 1:
        error = add_hermano(flistaHermanos);
        if(error == NULL)
        {
            printf("\n\nError al agregar hermano. Linea 55 Biblioteca: hermanos.c");
            system("pause");
        }
        break;
    case 2:
        error = delete_hermano(flistaHermanos);
        if(error == NULL)
        {
            printf("\n\nError al eliminar hermano. Linea 68 Biblioteca: hermanos.c");
            system("pause");
        }
        break;
    case 3:
        listarHermanos(flistaHermanos);
        break;
    case 4:
        error = buscarHermanoPor(flistaHermanos);
        if(error == NULL)
        {
            printf("\n\nError al buscar hermano.");
            system("pause");
        }
        break;
    case 5:
        error = editarHermano(flistaHermanos);
        if(error == NULL)
        {
            printf("\n\nError al editar/modificar hermano.");
            system("pause");
        }
        break;
    default:
        system("cls");
        break;
    }
    fclose(flistaHermanos);
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
    /*
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
    */
    return 0;
}


hermano* add_hermano(FILE * flistaHermanos)
{
    int cant;
    hermano* nuevoHermano = new_hermano();
    hermano* anteriorHermano = (hermano*) malloc (sizeof(hermano));
    int id;
    char nombre[31];
    char apellido[31];
    int grupo;
    printf("Usted ha precionado agregar hermano. Tenga en cuenta que \nse utilizara un ID para cada hermano ingresado.\n");
    printf("El mismo es unico y no vuelve a repetirse por mas que\n se elimine al hermano de sistema, por eso, trate de\n agregar cada hermano consientemente.\n");
    printf("\nSi ha leido el mensaje anterior: ");
    system("pause");
    system("cls");
    printf("\n\nIngrese NOMBRE(No debe superar los 30 caracteres): ");
    fflush(stdin);
    gets(nombre);
    printf("\nIngrese APELLIDO(No debe superar los 30 caracteres): ");
    fflush(stdin);
    gets(apellido);
    printf("\nIngrese numero de GRUPO: ");
    scanf("%d",&grupo);
    fseek(flistaHermanos,(long) (-1)*(sizeof(hermano)),SEEK_END);
    cant = fread(anteriorHermano,sizeof(hermano),1,flistaHermanos);
    if(cant!=1)
    {
        printf("\n Error al leer el hermano anterior");
        system("pause");
        return NULL;
    }
    id = anteriorHermano->id + 1;

    nuevoHermano = new_hermanoParam(id,nombre,apellido,grupo,1);
    printf("\n %d     %15s     %15s     %d",nuevoHermano->id,nuevoHermano->nombre,nuevoHermano->apellido,nuevoHermano->grupo);
    system("pause");
    if(nuevoHermano == NULL)
    {
        printf("\nError al crear nuevo hermano. Linea 177 biblioteca: hermanos.c  ");
        system("pause");
        return NULL;
    }
    fseek(flistaHermanos,0L,SEEK_END);
    cant = fwrite(nuevoHermano,sizeof(hermano),1,flistaHermanos);
    if(cant != 1)
    {
        printf("\nError al cargar el nuevo hermano al fichero. Linea 195 biblioteca: hermano.c  ");
        system("pause");
        return NULL;
    }
    printf("\n\n EL HERMANO HA SIDO AGREGADO AL SISTEMA CON EXITO!!! :D\n");
    system("pause");
    system("cls");

    return nuevoHermano;
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
    /*rewind(flistaHermanos);
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
    }*/
}

hermano* listarHermanos(FILE * flistaHermanos)
{
    int cant;
    hermano hno;
    hermano *error = NULL;
    rewind(flistaHermanos);
    printf("\n ID         Nombre         Apellido     Grupo\n");
    while(!feof(flistaHermanos))
    {
        cant = fread(&hno,sizeof(hermano),1,flistaHermanos);
        if(cant!=1)
        {
            if(feof(flistaHermanos))
            {
                printf("\n\nFin de la lista.");
                error = &hno;
                break;
            }
            printf("\n\Error al cargar uno de los hermanos. Linea: 244 Funcion: hermano* listarHermanos(FILE * flistaHermanos) \n\n");
            break;

        }
        if(hno.estado == 1)
        {
            printf("\n %d %15s %15s          %d",hno.id,hno.nombre,hno.apellido,hno.grupo);
        }
    }
    system("pause");
    system("cls");
    return error;
}

hermano* delete_hermano(FILE * flistaHermanos)
{
    int idBuscar;
    int cant;
    hermano *error;
    hermano *hno = (hermano*) malloc (sizeof(hermano));
    system("cls");
    printf("\n Ingrese ID del hermano: ");
    scanf("%d",&idBuscar);
    rewind(flistaHermanos);
    do
    {
        cant = fread(hno,sizeof(hermano),1,flistaHermanos);
        if(cant != 1)
        {
            if(feof(flistaHermanos))
            {
                printf("\nFin de la busqueda. No se hallaron resultados");
                system("pause");
                break;
            }
            printf("\n Error a buscar el hermano. Linea 296 Biblioteca: hermanos.c \n");
            system("pause");
            error = NULL;
            break;
        }
        if(hno->id == idBuscar)
        {
            hno = new_hermanoParam(hno->id,hno->nombre,hno->apellido,hno->grupo,0);
            fseek(flistaHermanos,(long) (-1)*sizeof(hermano),SEEK_CUR);
            cant = fwrite(hno,sizeof(hermano),1,flistaHermanos);
            if(cant != 1)
            {
                if(feof(flistaHermanos))
                {
                    printf("\nFin del archivo. Linea: 309 Biblioteca: hermanos.c \n");
                    system("pause");
                    break;
                }
                printf("\n Error al eliminar el hermanos. Linea 309 Bbiblioteca: hermanos.c \n");
                system("pause");
                error = NULL;
                break;
            }
            break;
        }

    }
    while(!feof(flistaHermanos));
    return error;
}
void* buscarHermanoPor(FILE* flistaHermanos)
{
    int opcion;

    system("cls");
    printf("\n*** BUSCAR HERMANO ***\n");
    printf("\n1)Bucar por grupo");
    printf("\n2)Bucar por ID");
    printf("\n3)Bucar por nombre");
    printf("\n4)Bucar por apellido");
    printf("\n5)Ir al menu principal");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
        buscarPorGrupo(flistaHermanos);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        system("cls");
        break;

    }
    return 0;
}

void* buscarPorGrupo(FILE * flistaHermanos)
{
    int grupoBuscar;
    int cant;
    hermano *error;
    hermano *hno = (hermano*) malloc (sizeof(hermano));
    system("cls");
    printf("\n Ingrese numero del grupo que desea buscar: ");
    scanf("%d",&grupoBuscar);
    rewind(flistaHermanos);
    system("cls");
    printf("\n LOS HERMANOS QUE PERTENCEN AL GRUPO %d SON:\n",grupoBuscar);
    printf("\n Id                 Nombre      Apellido     Grupo");
    do
    {
        cant = fread(hno,sizeof(hermano),1,flistaHermanos);
        if(cant != 1)
        {
            if(feof(flistaHermanos))
            {
                printf("\nFin de la busqueda.");
                system("pause");
                break;
            }
            printf("\n Error a buscar el hermano. Linea 389 Biblioteca: hermanos.c \n");
            system("pause");
            error = NULL;
            break;
        }
        if(hno->grupo == grupoBuscar)
        {
            printf("\n %d     %15s      %15s     %d",hno->id,hno->nombre,hno->apellido,hno->grupo);
        }

    }
    while(!feof(flistaHermanos));
    return error;
}





void* editarHermano(FILE *flistaHermanos)
{
    int idBuscar;
    int cant;
    int opcion;
    hermano *error;
    hermano *hno = (hermano*) malloc (sizeof(hermano));

    char nombre[31];
    char apellido[31];
    int grupo;

    system("cls");
    printf("\n Ingrese ID del hermano que desea editar: ");
    scanf("%d",&idBuscar);
    rewind(flistaHermanos);
    do
    {
        cant = fread(hno,sizeof(hermano),1,flistaHermanos);
        if(cant != 1)
        {
            if(feof(flistaHermanos))
            {
                printf("\nFin de la busqueda. No se hallaron resultados");
                system("pause");
                break;
            }
            printf("\n Error a buscar el hermano. Linea 296 Biblioteca: hermanos.c \n");
            system("pause");
            error = NULL;
            break;
        }
        if(hno->id == idBuscar && hno->estado == 1)
        {

            printf("El hermano de ID %d",hno->id);
            printf("\nId                 Nombre      Apellido     Grupo");
            printf("\n%d     %15s      %15s     %d\n",hno->id,hno->nombre,hno->apellido,hno->grupo);
            printf("\n1)Editar nombre");
            printf("\n2)Editar apellido");
            printf("\n3)Editar grupo\n");
            printf("\nIngrese opcion: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                if(getString(nombre,"\nIngrese nuevo nombre (No debe superar los 30 caracteres)\n","El nombre no debe superar los 30 caracteres!!",30,5) == 1)
                {
                    printf("\nNo se pudo realizar la operacion de edicion");
                    system("pause");
                    return NULL;
                }
                hno = new_hermanoParam(hno->id,nombre,hno->apellido,hno->grupo,1);
                break;
            case 2:
                if(getString(nombre,"\nIngrese nuevo apellido (No debe superar los 30 caracteres)\n","El apellido no debe superar los 30 caracteres!!",30,5) == 1)
                {
                    printf("\nNo se pudo realizar la operacion de edicion");
                    system("pause");
                    return NULL;
                }
                hno = new_hermanoParam(hno->id,hno->nombre,apellido,hno->grupo,1);
                break;
            case 3:
                printf("\nIngrese nuevo numero de grupo: ");
                scanf("%d",&grupo);
                hno = new_hermanoParam(hno->id,hno->nombre,hno->apellido,grupo,1);
                break;
            default:
                system("cls");
                break;

            }

            fseek(flistaHermanos,(long) (-1)*sizeof(hermano),SEEK_CUR);
            cant = fwrite(hno,sizeof(hermano),1,flistaHermanos);
            if(cant != 1)
            {
                if(feof(flistaHermanos))
                {
                    printf("\nFin del archivo. Linea: 309 Biblioteca: hermanos.c \n");
                    system("pause");
                    break;
                }
                printf("\n Error al eliminar el hermanos. Linea 309 Bbiblioteca: hermanos.c \n");
                system("pause");
                error = NULL;
                break;
            }
            break;
        }

    }
    while(!feof(flistaHermanos));


    return error;
}
