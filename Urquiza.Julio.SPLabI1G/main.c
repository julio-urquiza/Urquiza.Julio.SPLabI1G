#include <stdio.h>
#include <stdlib.h>
#include "Validaciòn.h"
#include "controller.h"
#include <time.h>

void opciones(void);

int main()
{
    srand(time(NULL));
    LinkedList* lista=ll_newLinkedList();
    int opcion=1;
    do{
        opciones();
        switch(opcionSwitch("Ingrese un numero: ","ERROR,",1,8))
        {
            case 1:
                controller_loadFromText(lista);
                break;
            case 2:
                controller_listCountries(lista);
                break;
            case 3:
                controller_assignStatistics(lista);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                opcion=0;
                break;
        }
        system("pause");
    }while(opcion);
    return 0;
}
void opciones(void)
{
   system("cls");
   printf("1.Cargar Archivo\n");
   printf("2.Mostrar los datos\n");
   printf("3.Asignar Estadistocas\n");
   printf("4.\n");
   printf("5.\n");
   printf("7.\n");
   printf("8.salir\n");
}
