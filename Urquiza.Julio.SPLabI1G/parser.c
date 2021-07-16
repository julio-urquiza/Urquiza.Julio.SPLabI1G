/*******************************************************************
*Division:1g
*Alumno:Julio Cesar Urquiza
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "pais.h"

int parser_countryFromText(FILE* pFile, LinkedList* pArrayList)
{
    int r;
    int id;
    char encavezado[100];
    char nombre[30];
    int vac1Dosis;
    int vac2Dosis;
    int sinVacunar;
    ePais* aux;
    if(pArrayList!=NULL && pFile!=NULL)
    {
        fscanf(pFile,"%[^\n]",encavezado);
        do{
            r = fscanf(pFile,"%d,%[^,],%d,%d,%d\n",&id,nombre,&vac1Dosis,&vac2Dosis,&sinVacunar);
            if(r==5)
            {
                aux=pais_newParametros(id,nombre,vac1Dosis,vac2Dosis,sinVacunar);
                ll_add(pArrayList,aux);
            }
            else
            {
                break;
            }
        }while(!feof(pFile));
    }

    return 1;
}
