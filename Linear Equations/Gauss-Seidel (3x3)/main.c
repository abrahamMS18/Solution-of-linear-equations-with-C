#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ren 3
#define col 4

void llenar();
void mostrar();
void ordenar();

int checar_diagonal();
int checar_ladoDerecho();
int checar_renglones();
int checar();

float mat[ren][col];
int i, j;


void main(){

    system("clear");

    llenar();
    mostrar();
    ordenar();
    mostrar();

}

void llenar(){

    srand(time(NULL));

    for (i = 0; i < 3; i++){
        for(j=0; j<4; j++){
            mat[i][j] = rand()%100;    
        }
    }
}

void mostrar(){

    printf("\n\n");

    for (i = 0; i < 3; i++){
        printf("\n");
        for(j=0; j<4; j++){
            printf("   [%.2f]   ", mat[i][j]);
        }
    }

    printf("\n\n");
}

void ordenar(){

    float temp[col];
    int r=0, c=0, x=1, y=0, cont=0;

    for(i=1; i<ren; i++){
        for(j=0; j<ren-i; j++){
            if (mat[j][c] < mat[j+1][c]){
                for(x=0; x<col; x++){
                    temp[x] = mat[j][x];
                    mat[j][x] = mat[j+1][x];
                    mat[j+1][x] = temp[x];
                }//end for
            }//end if
        }//end for
    }//end for

}
