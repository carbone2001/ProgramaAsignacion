#include "salidas.h"
#include "hermanos.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main()
{
    int opcion;
    hermano *hnos;
    hnos = (hermano*) malloc(sizeof(hermano));
    FILE * flistaHermanos;
    FILE * fcacheHnos;

    //FILE *flistaSalidas;
    //salida *salidas;
    //salidas = (salida*) malloc(sizeof(salida));

    time_t rawtime;


    time (&rawtime);



    do
    {
        printf("\nTiempo local: %s\n", ctime (&rawtime));
        int longitudLista;

        switch(menu())
        {
        case 1:

            break;
        case 2:
            fflush(stdin);
            if((flistaHermanos = fopen("./listaHermanos.csv","r") )== NULL)
            {

                system("cls");
                printf("\nNo se pudo leer el archivo");
                system("pause");
                system("cls");
                fflush(stdin);
                if((flistaHermanos = fopen("listaHermanos.csv","w") )== NULL)
                {
                    printf("\nERROR AL CREAR ARCHIVO listaHermanos.csv");
                    break;
                }
                fseek(flistaHermanos,0L,SEEK_SET);
                fprintf(flistaHermanos,"%d,%s,%s,%d,%d\n",0,"name","lastName",0,0);
                cargarListaHermanos(flistaHermanos,hnos);

                editarListaHermanos(hnos,flistaHermanos,longitudLista);
                fclose(flistaHermanos);
            }
            else
            {

                system("cls");
                printf("\nSI se pudo leer el archivo");
                system("pause");
                system("cls");
                fflush(stdin);


                //cargarArchivoHermanos(fcacheHnos,hnos);
                /*
                if((flistaHermanos = fopen("listaHermanos.csv","w") )== NULL)
                {
                    printf("\nERROR AL ABRIR ARCHIVO listaHermanos.csv");
                    break;
                }*/

                longitudLista = cargarListaHermanos(flistaHermanos,hnos);

                system("cls");
                printf("\nEl longitudLista = %d",longitudLista);
                system("pause");
                system("cls");
                fclose(flistaHermanos);

                flistaHermanos = fopen("./listaHermanos.csv","w");
                if(flistaHermanos == NULL)
                {
                    printf("\nNo se pudo abrir el archivo en modo escritura");
                    system("pause");
                    break;
                }
                cargarArchivoHermanos(hnos,flistaHermanos,longitudLista);
                editarListaHermanos(hnos,flistaHermanos,longitudLista);
                fclose(flistaHermanos);

            }


            break;
        case 3:
            break;
        case 4:
            opcion=0;
            printf("\n HASTA LUEGO!\n\n");
            Sleep(1000);
            break;
        default:
            printf("\n LA OPCION INGRESADA ES INCORRECTA");
            break;
        }
    }
    while(opcion);
    //fclose(flistaHermanos);
    //fclose(flistaSalidas);
}
