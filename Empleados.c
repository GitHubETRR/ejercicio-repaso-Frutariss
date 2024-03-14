#include <stdio.h>
#include <stdint.h>

#define MaxLengthName 99
#define CantEmpleadosMax 20

typedef struct{
    char nombre[MaxLengthName];
    int edad;
    float salario;
}empleado_t;

void IngresarDatos(empleado_t[], int);
void ProcesarDatos(empleado_t[], int);
void MostrarDatos(empleado_t[], int);


int main (void){
    empleado_t empleados[CantEmpleadosMax];
    int CantEmplAct=0;
    int opcion;

    printf(" \n----- Menu -----");
    printf(" \n1. Ingresar datos de un empleado.");
    printf(" \n2. Procesar y mostrar informacion relevante.");
    printf(" \n3. Salir.\n");

    while(1){

        printf(" \nIngrese su opcion: ");
        scanf(" \n%d",&opcion);

        switch(opcion){
            case 1:
                IngresarDatos(empleados, CantEmplAct);
                CantEmplAct++;
                break;
            case 2:
                MostrarDatos(empleados, CantEmplAct);
                ProcesarDatos(empleados, CantEmplAct);
                break;
            case 3:
                printf("\nHasta luego");
                return 0;
            default:
                printf("\nOpcion incorrecta");
        }
   }

}

void IngresarDatos(empleado_t empleados[], int CantEmplAct){
    while(1){
        printf("Nombre del empleado: ");
        scanf(" \n%[^\n]%*c",&empleados[CantEmplAct+1].nombre);
        printf("Edad del empleado: ");
        scanf(" \n%d",&empleados[CantEmplAct+1].edad);
        printf("Salario del empleado: ");
        scanf(" \n%f",&empleados[CantEmplAct+1].salario);

        if(empleados[CantEmplAct].edad>0 && empleados[CantEmplAct].salario>=0){
            break;
        }
        printf("Hay un error en la edad o salario del empleado\n");
    }
}

void ProcesarDatos(empleado_t empleados[], int CantEmplAct){
    int ISalMaxs[CantEmpleadosMax];
    float SalProm=0;
    float SalMax=0;
    int ISalMax=0;
    int CantMax=0;
    int i2=0;
  
    //Promedio
    for(int i=1;i<=CantEmplAct;i++){
        SalProm+=empleados[i].salario;
    }
    SalProm/=CantEmplAct;
    printf("\n\nPromedio de salarios: $%.2f", SalProm);

    //Maximo
    for(int i=1;i<=CantEmplAct;i++){
        if(empleados[i].salario>SalMax){
            CantMax=0;
            SalMax=empleados[i].salario;
            ISalMax=i;
            i2=0;
            for(int a=0;a<CantEmplAct;a++){
                ISalMaxs[a]=0;
            }
        }else if (empleados[i].salario==SalMax){
            CantMax=1;
            ISalMaxs[i2]=i;
            i2++;
        }
    }
    if(CantMax==0){
        printf("\nEmpleado con el salario mas alto: %s", empleados[ISalMax].nombre);
    }else if(CantMax==1){
        printf("\nLos empleados con el salario mas alto son:");
        for(int i=0;i<i2;i++){
            printf("\n %s", empleados[ISalMaxs[i]].nombre);
        }
    }
}


void MostrarDatos(empleado_t empleados[], int CantEmplAct){
    printf("\n--- Informacion de Empleados ---");
    for(int i=1;i<=CantEmplAct;i++){
        printf("\n%d. Nombre: %s, Edad: %d, Salario: %.2f", (i), empleados[i].nombre, empleados[i].edad, empleados[i].salario);
    }
}