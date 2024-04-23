#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "datos.h"
#include "funciones.h"

int main(int argc, char const *argv[])
{
    struct Atleta ats;
    int opcion = 0;
    int bandera = 0;
    FILE *fileAt = NULL;
    
    while(!bandera){

        opcion = menu();
        limpiarBuffer();
        switch (opcion) //switch principal
        {
            case 1:
                system("cls");
                limpiarBuffer();
                int opcSMenu=0;
                opcSMenu = menuFichero();
                limpiarBuffer();
                switch (opcSMenu) //switch submenu fichero
                {
                case 1:
                    limpiarBuffer();
                    fileAt = abrirFichero();
                    system("pause");
                    system("cls");
                    break;
                    
                case 2:
                    limpiarBuffer();
                    fileAt = abrirFicheroA();
                    system("pause");
                    system("cls");
                    break;

                case 3:
                    limpiarBuffer();
                    fileAt = nuevoFichero();
                    system("pause");
                    system("cls");
                    break;

                case 4:
                    limpiarBuffer();
                    eliminarFichero(fileAt);
                    system("pause");
                    system("cls");
                    break;

                case 5:
                    limpiarBuffer();
                    system("cls");
                    printf("\nRegresando al menu principal... \n");
                    break;

                
                default:
                    printf("Digite una opcion valida!!! \n");
                    system("pause");
                    system("cls");
                    break;
                }
                break;
            
            case 2:
                system("cls");
                limpiarBuffer();
                newAtleta(fileAt, ats);
                break;
            
            case 3:
                system("cls");
                limpiarBuffer();
                visualizarAtletas(fileAt, ats);
                break;
            
            case 4: 
                system("cls");
                limpiarBuffer();
                editarAtleta(fileAt, ats);
                break;
            
            case 5:                
                system("cls");
                limpiarBuffer();
                eliminarAtleta(fileAt, ats);
                break;
            
            case 6:               
                system("cls");
                limpiarBuffer();
                break;

            case 7:
                limpiarBuffer();
                printf("Hasta pronto!!! \n");
                system("pause");
                bandera = 1;
                system("cls");
                break;
        
            default:
                printf("Digite una opcion valida!!! \n");
                system("pause");
                system("cls");
                break;
        } //cierra el switch





    }//cierra el while


    return 0;
}//cierra la funcion main()