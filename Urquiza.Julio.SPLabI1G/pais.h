#include "LinkedList.h"
#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct{
    int id;
    char nombre[30];
    int vac1Dosis;
    int vac2Dosis;
    int sinVacunar;
}ePais;

#endif // PAIS_H_INCLUDED

ePais* pais_new();
ePais* pais_newParametros(int id,char* nombre,int recuperados,int infectados,int muertos);
int pais_setId(ePais* pais,int id);
int pais_getId(ePais* pais,int* id);
int pais_setNombre(ePais* pais,char* nombre);
int pais_getNombre(ePais* pais,char* nombre);
int pais_setVac1Dosis(ePais* pais,int vac1Dosis);
int pais_getVac1Dosis(ePais* pais,int* vac1Dosis);
int pais_setVac2Dosis(ePais* pais,int vac2Dosis);
int pais_getVac2Dosis(ePais* pais,int* vac2Dosis);
int pais_setSinVacunar(ePais* pais,int sinVacunar);
int pais_getSinVacunar(ePais* pais,int* sinVacunar);
int pais_ListPais(ePais* pais);
void* asignarValoresAleatorios(void* pais);
