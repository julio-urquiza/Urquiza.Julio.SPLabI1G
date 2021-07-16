#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"

ePais* pais_new()
{
    ePais* pais=NULL;

    pais = (ePais*)malloc(sizeof(ePais));

    return pais;

}

ePais* pais_newParametros(int id,char* nombre,int vac1Dosis,int vac2Dosis,int sinVacunar)
{
    ePais* paisRetorno=NULL;
    ePais* aux;

    aux = pais_new();
    if(aux!=NULL)
    {
        if(pais_setId(aux,id) &&
           pais_setNombre(aux,nombre) &&
           pais_setVac1Dosis(aux,vac1Dosis) &&
           pais_setVac2Dosis(aux,vac2Dosis) &&
           pais_setSinVacunar(aux,sinVacunar))
        {
            paisRetorno=aux;
        }
    }

    return paisRetorno;
}

int pais_setId(ePais* pais,int id)
{
    int returnValue=-1;
    if(pais!= NULL && id>0)
    {
        pais->id=id;
        returnValue=1;
    }
    return returnValue;
}

int pais_getId(ePais* pais,int* id)
{
    int returnValue=-1;
    if(pais!= NULL && id!=NULL)
    {
        *id=pais->id;
        returnValue=1;
    }
    return returnValue;
}

int pais_setNombre(ePais* pais,char* nombre)
{
    int returnValue=-1;
    if(pais!= NULL && nombre!=NULL)
    {
        strcpy(pais->nombre,nombre);
        returnValue=1;
    }
    return returnValue;
}

int pais_getNombre(ePais* pais,char* nombre)
{
    int returnValue=-1;
    if(pais!= NULL && nombre!=NULL)
    {
        strcpy(nombre,pais->nombre);
        returnValue=1;
    }
    return returnValue;
}

int pais_setVac1Dosis(ePais* pais,int vac1Dosis)
{
    int returnValue=-1;
    if(pais!= NULL && vac1Dosis>=0)
    {
        pais->vac1Dosis=vac1Dosis;
        returnValue=1;
    }
    return returnValue;
}

int pais_getVac1Dosis(ePais* pais,int* vac1Dosis)
{
    int returnValue=-1;
    if(pais!= NULL && vac1Dosis!=NULL)
    {
        *vac1Dosis=pais->vac1Dosis;
        returnValue=1;
    }
    return returnValue;
}

int pais_setVac2Dosis(ePais* pais,int vac2Dosis)
{
    int returnValue=-1;
    if(pais!= NULL && vac2Dosis>=0)
    {
        pais->vac2Dosis=vac2Dosis;
        returnValue=1;
    }
    return returnValue;
}

int pais_getVac2Dosis(ePais* pais,int* vac2Dosis)
{
    int returnValue=-1;
    if(pais!= NULL && vac2Dosis!=NULL)
    {
        *vac2Dosis=pais->vac2Dosis;
        returnValue=1;
    }
    return returnValue;
}

int pais_setSinVacunar(ePais* pais,int sinVacunar)
{
    int returnValue=-1;
    if(pais!= NULL && sinVacunar>=0)
    {
        pais->sinVacunar=sinVacunar;
        returnValue=1;
    }
    return returnValue;
}

int pais_getSinVacunar(ePais* pais,int* sinVacunar)
{
    int returnValue=-1;
    if(pais!= NULL && sinVacunar!=NULL)
    {
        *sinVacunar=pais->sinVacunar;
        returnValue=1;
    }
    return returnValue;
}

int pais_ListPais(ePais* pais)
{
    int retorno=0;
    int  id;
    char nombre[30];
    int vac1Dosis;
    int vac2Dosis;
    int sinVacunar;

    if(pais!=NULL)
    {
        if(pais_getId(pais,&id)&&
           pais_getNombre(pais,nombre)&&
           pais_getVac1Dosis(pais,&vac1Dosis)&&
           pais_getVac2Dosis(pais,&vac2Dosis)&&
           pais_getSinVacunar(pais,&sinVacunar))
           {
                printf("%5d%20s%11d%11d%11d\n",id,nombre,vac1Dosis,vac2Dosis,sinVacunar);
                retorno=1;
           }
    }
    return retorno;
}

void* asignarValoresAleatorios(void* pais)
{
    int vac1Dosis;
    int vac2Dosis;
    int sinVacunar;
    ePais* auxPais;
    if(pais!=NULL)
    {
        auxPais=(ePais*)pais;
        vac1Dosis=rand()%111+90;
        vac2Dosis=rand()%111+90;
        sinVacunar=1000-(vac1Dosis+vac2Dosis);
        pais_setVac1Dosis(auxPais,vac1Dosis);
        pais_setVac2Dosis(auxPais,vac2Dosis);
        pais_setSinVacunar(auxPais,sinVacunar);
    }
    return auxPais;
}













