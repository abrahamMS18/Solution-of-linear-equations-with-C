/*
    Creado por: Carlos Abraham Mora Hernandez
    Fecha: 01/08/20
    Compilador: Mingw GCC (Compilado en entorno Linux y MacOS)
    Lenguaje: C
    Version: 1.0
    Contenido: Funcion que realiza Gauss-Jordan con una matriz de 2x2 con base a esta estructura:

        En forma de ecuación:
            Ax + By = C
            Dx + Ey = F
        
        En forma matricial:
            | A  B  |  C |
            | D  E  |  F |
    
    Para Gauss-Jordan hay varias vartientes:
        Sistema Linealmente Dependiente
        Sistema Linealmente Independiente
        Sistema sin solucion 
    Estas vertientes las contempla el programa

    La solucion directa directa para X y Y, sin que haya una restriccion de por medio, es la siguiente:

        y = (C*D - F*A)/(B*D - E*A)
        x = ( (B*(C*D - F*A)) - (C*(B*D - E*A)) ) / (-A*(B*D - E*A))

    NOTA: El programa no contempla uso de numeros con punto flotante a la hora de ingresar los datos, de igual manera de que no hay exepciones si se inserta una letra
          POR LO QUE NO INGRESE NUMEROS CON PUNTO FLOTANTE (6.66) O LETRAS (X, Y, U, ETC). 

*/




int mat[2][3]; //Matriz
int i, j; //Iteradores
float A, B, C, D, E, F;
float x, y;

/* Llamado de funciones */
void mostrar_matriz();
void ingresar_datos();
int resultado();
void asignacion_letras();
int iteracion_1();


void matriz_22(){
    /*
        Nombre: matriz_22
        Funcion: Funcion principal que mandara a llamar a todas para la resolucion de gauss-jordan 2x2
        Envía: --
        Recibe: --
    */

   int exito;

    printf("Selecciono la matriz de 2x2\n"); 

    mostrar_matriz();
    ingresar_datos();

    exito = resultado();

    //printf("Exito es igual a ->%d<-", exito);

    switch (exito){

    case 0: 

        if(A == 0 && E == 0){
            printf("Sistema resuelto\n\nX = %.3f\nY = %.3f", F/D, C/B); 
        } else{

            y = (C*D - F*A)/(B*D - E*A);
            x = ( (B*(C*D - F*A)) - (C*(B*D - E*A)) ) / (-A*(B*D - E*A));

            printf("Sistema resuelto\n\nX = %.3f\nY = %.3f", x, y); 

        }
        break;
    
    case 1: printf("Sistema inconsistente o No tiene solucion\n\n"); 
            mostrar_matriz();
        break;

    case 2: printf("El sistema es linealmente dependiente\n\n");
            if(B <= 0){
                printf("X = %.3f(%.3f - %.3fw)\n", 1/A, C, B*-1);
            } else{
                printf("X = %.3f(%.3f - %.3fw)\n", 1/A, C, B);
            }
            printf("Y = w pertenece a los numeros Reales\n\n");
        break;

    }

}

void mostrar_matriz(){
    /*
        Nombre: mostrar_matriz
        Funcion: Muestra la matriz inicial con valores cero
        Envia: --
        Recibe: --
    */
         
    for(i=0;i<2;i++){
        printf("\n");
        for(j=0;j<3;j++){
            printf("%3d", mat[i][j]);
        }
    }

    printf("\n\n");
}

void ingresar_datos(){
    /*
        Nombre: ingresar_datos
        Funcion: El usuario ingresa el valor de 'x', 'y' y valor contasnte de las dos ecuaciones 
        Envia: --
        Recibe: --
    */

    printf("El sistema de ecuaciones es de la forma: \n\n");
    printf("1) Ax + By = C\n");
    printf("2) Dx + Ey = F\n\n");

    /* Ecuacion 1 */
    printf("Valor de A (x): ");
    scanf("%d", &mat[0][0]);

    printf("Valor de B (y): ");
    scanf("%d", &mat[0][1]);

    printf("Valor de C    : ");
    scanf("%d", &mat[0][2]);

    /* Ecuacion 2 */
    printf("Valor de D (x): ");
    scanf("%d", &mat[1][0]);

    printf("Valor de E (y): ");
    scanf("%d", &mat[1][1]);

    printf("Valor de F    : ");    
    scanf("%d", &mat[1][2]);

    printf("\n\n");

    printf("La matriz quedo de la siguiente manera:\n\n");
    printf("Forma canonica:\n\n");
    printf("1) %dx + %dy = %d\n", mat[0][0], mat[0][1], mat[0][2]);
    printf("2) %dx + %dy = %d\n\n", mat[1][0], mat[1][1], mat[1][2]);

    printf("Forma matricial\n");
    mostrar_matriz();
    printf("\n\n");
}

int resultado(){
    /*
        Nombre: resultado
        Funcion: Realiza el procedimiento de la matriz escalonado, para la realizacion de Gauss-Jordan
        Envia: 0 si fue realizado con exito la operación 
               1 si el sistema es inconsistente
               2 si el sistema es linealmente dependiente
        Recibe: --
    */

    asignacion_letras();   
    
    if (A == 0 && B == 0 && D == 0 && E == 0)
    {
        return 1;
    } else if ((A == 0 && D == 0) || (B == 0 && E == 0))
    {
        return 1;
    } else if ( (A == 0 && B == 0) || (D == 0 && E == 0) ){
        return 1;
    }else{
        int iter1;

        iter1 = iteracion_1();

        return iter1;
        
    }
    
   
}

void asignacion_letras(){
      /*
        Nombre: asignacion_letras
        Funcion: Asigna el numero a cada una de las letras que hay el matriz
        Envia: --
        Recibe: --
    */

    
    //Ecuacion 1: Ax + By = C
    A = mat[0][0];
    B = mat[0][1];
    C = mat[0][2];

    //Ecuacion 2: Dx + Ey = F
    D = mat[1][0];
    E = mat[1][1];
    F = mat[1][2];
}

int iteracion_1(){
    /*
        Nombre: iteracion_1
        Funcion: Resuelve Gauss-Jordan
        Envia: Dos clases de 0:
                    0 si la letra D es ingresada con cero, ya que el procedimiento de Gauss-Jordan no cera necesario
                    0 despues de pasar por todas la restricciones 
                1 si despues de realizar Gauss-Jordan D y E son 0 y F es diferente de cero (0x + 0y = 18), por lo el sistema no tiene solucion
                2 si despues de realizar Gauss-Jordan D, E y F son cero (0x + 0y = 0), por lo que el sistema es linealmente dependiente 
        Recibe: --
    */

    if (D == 0)
    {
        return 0;
    }
    

    for(i=0; i<3;i++){
        mat[0][i] = mat[0][i]*D;

        if(D > 0) {mat[1][i] = mat[1][i]*A;}            
        else {mat[1][i] = mat[1][i]*-A;}
    }

    mat[1][0] = mat[0][0] + mat[1][0];
    mat[1][1] = mat[0][1] + mat[1][1];
    mat[1][2] = mat[0][2] + mat[1][2];

    if(mat[1][0] == 0 && mat[1][1] == 0  && mat[1][2] == 0){
        return 2;
    } else if(mat[1][0] == 0 && mat[1][1] == 0  && mat[1][2] != 0){
        return 1;
    } else{
        return 0;
    }
    

}


/*        
                | 0  B  |  C |
                | 0  E  |  F |

                Ó

                | A  0  |  C |
                | D  0  |  F |

            

             
                | 0  0  |  C |
                | D  E  |  F |

                ó

                | A  B  |  C |
                | 0  0  |  F |
*/





