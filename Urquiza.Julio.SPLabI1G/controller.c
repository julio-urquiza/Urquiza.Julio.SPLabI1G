/*******************************************************************
*Division:1g
*Alumno:Julio Cesar Urquiza
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "pais.h"
#include "parser.h"


int controller_loadFromText(LinkedList* pArrayList)
{
    int retorno=-1;
    FILE* pFile;
    if(pArrayList!=NULL)
    {
        pFile=fopen("vacunas.csv","r");
        if(pFile == NULL)
        {
            printf("El archivo no existe\n");
            exit(EXIT_FAILURE);
        }
        parser_countryFromText(pFile,pArrayList);
        printf("\nDatos Cargados con exito\n");
        fclose(pFile);
        retorno=1;
    }
    return retorno;
}

int controller_listCountries(LinkedList* pArrayList)
{
    int retorno=-1;
    int tam;
    if(pArrayList!=NULL)
    {
        tam=ll_len(pArrayList);
        printf("Hay %d\n elementos\n",tam);
        printf("%5s%20s%11s%11s%11s\n","id","nombre","Vac1Dosis","Vac2Dosis","SinVacunar");
        for(int i=0;i<tam;i++)
        {
            pais_ListPais(ll_get(pArrayList,i));
        }
        retorno=1;
    }
    return retorno;
}

int controller_assignStatistics(LinkedList* pArrayList)
{
    LinkedList* pArrayListMap;
    int retorno=0;
    if(pArrayList!=NULL)
    {
        pArrayListMap=ll_map(pArrayList,asignarValoresAleatorios);
        controller_listCountries(pArrayListMap);
        if(pArrayListMap!=NULL)
        {
            pArrayList=pArrayListMap;
            retorno=1;
        }
    }
    return retorno;
}










