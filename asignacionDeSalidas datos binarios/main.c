#include "salidas.h"
#include "hermanos.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main()
{
    int opcion;
    FILE * flistaHermanos;
    //FILE *flistaSalidas;
    //salida *salidas;
    //salidas = (salida*) malloc(sizeof(salida));
    time_t rawtime;
    time (&rawtime);



    do
    {
        printf("\nTiempo local: %s\n", ctime (&rawtime));

        switch(menu())
        {
        case 1:
            break;
        case 2:
            editarListaHermanos(flistaHermanos);
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
