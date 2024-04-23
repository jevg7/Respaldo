#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

/* DEFINICION DE LA ESTRUCTURA ATLETA */
struct datos_olimpicos
{
    char deporte[100];
    int nMedallas;
    char descRecord[200];
};

struct Atleta
{
    char cedula[20];
    char nombreCompleto[100];
    int edad;
    char sexo;
    char telefono[20];
    char direccion[200];
    char pais[30];
    struct datos_olimpicos dop;
};

#endif //