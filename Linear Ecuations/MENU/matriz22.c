
int mat[2][3]; //Matriz
int i, j; //Iteradores
int A, B, C, D, E, F;
int x, y;

void mostrar_matriz();
void ingresar_datos();
int resultado();
void asignacion_letras();

void matriz_22(){
    /*
        Nombre: matriz_22
        Funcion: Funcion principal que mandara a llamar a todas para la resolucion de gauss-jordan 2x2
        Envía: --
        Recibe: --
    */

   int exito = 0;

    printf("Selecciono la matriz de 2x2\n"); 

    mostrar_matriz();
    ingresar_datos();

    exito = resultado();

    switch (exito){

    case 0: printf("Sistema resuelto\n\nX = %d\nY = %d", x, y); break;
    
    case 1: printf("Sistema inconsistente\n\n"); break;

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
        Recibe: --
    */

    asignacion_letras();   
    
    if(A == 0 && B == 0 && D == 0 && E == 0){
        return 1; //Sistema inconsistente 
    }else{

        x = ( (B*(C*D - F*A)) - (C*(B*D - E*A)) ) / (-A*(B*D - E*A));

        y = (C*D - F*A)/(B*D - E*A);

        return 0;
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









