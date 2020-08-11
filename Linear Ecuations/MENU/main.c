#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Librerias externas */
#include "matriz22.c"
#include "matriz33.c"
#include "matriznn.c"

/* Constantes */
#define SALIR 4

int main(){

    //int mat_22, mat_33, mat_nn;
    int opc=0;

    do
    {

        printf("\n\n\n");
        printf("\tBIENVENIDO\n");
        printf("ESTO ES UN PROGRAMA QUE TRATA SIMULAR GAUSS-JORDAN CON MATRICES DE 2X2 3X3 Ó NXN\n\n");

        printf("PARA ACCEDER PRESIONE:\n");

        printf("1) Gauss-Jordan (Matriz 2x2)\n");
        printf("2) Gauss-Jordan (Matriz 3x3)\n");
        printf("3) Gauss-Jordan (Matriz NxN)\n");
        printf("4) Salir\n");

        printf("Selecione una opcion: ");
        scanf("%d", &opc);
        system("clear");

        switch (opc)
        {
            case 1: matriz_22();
                break;
            
            case 2: matriz_33();
                break;

            case 3: matriz_nn();
                break;

            case 4: printf("V U E L V E   P R O N T O\n\n");
                break;

            default: printf("ERROR");
                break;
        }


    } while (opc != 4);
    
    



    return 0;
}