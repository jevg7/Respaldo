#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Factura.h"
#include "inventario.h"

int main(int argc, char const *argv[])
{
    int opcion = 0;
    int bandera = 0;
    FILE *fileFact = NULL;

    while(!bandera){

        opcion = menu();
        CleanBuffer();
        int opcSMenu=0;
        int bandera2 = 0;
        int bandera3 = 0;
        switch (opcion) //switch principal
        {
            case 1://Menu - Gestión de Invetario
                while (!bandera2)
                {
                    system("cls");
                    CleanBuffer();
                    opcSMenu = menuInventario();
                    CleanBuffer();
                    switch (opcSMenu)
                    {
                    case 1://Visualizar Productos en existencia
                        while (!bandera3)
                        {
                            system("cls");
                            CleanBuffer();
                            opcSMenu = menuProducExistencia();
                            CleanBuffer();
                            switch (opcSMenu)
                            {
                            case 1: //Visualizar todos los productos
                                system("cls");
                                CleanBuffer();
                                break;
                            case 2: //Buscar un producto
                                system("cls");
                                CleanBuffer();
                                break;
                            case 3: //Salir
                                system("cls");
                                bandera3 = 1;
                                CleanBuffer();
                                break;
                            default:
                                OpcionInvalida();
                                break;
                            }
                            CleanBuffer();
                        }
                        break;
                    case 2://Agregar nuevo producto
                        system("cls");
                        CleanBuffer();
                        break;
                    case 3: //Editar datos de un producto
                        system("cls");
                        CleanBuffer();
                        break;
                    case 4: //Eliminar un producto
                        system("cls");
                        CleanBuffer();                        
                        break;
                    case 5: //Menu Proveedores
                        while (!bandera2)
                        {
                            system("cls");
                            CleanBuffer();
                            opcSMenu = menuProveedores();
                            switch (opcSMenu)
                            {
                            case 1: //Visualizar proveedores
                                system("cls");
                                CleanBuffer();
                                break;
                            case 2: //Agregar nuevo proveedor
                                system("cls");
                                CleanBuffer();
                                break;
                            case 3: //Editar datos de un proveedor
                                system("cls");
                                CleanBuffer();
                                break;
                            case 4: //Eliminar Proveedor
                                system("cls");
                                CleanBuffer();
                                break;
                            case 5: //Salir
                                system("cls");
                                bandera2 = 1;
                                CleanBuffer();
                                break;
                            default:
                                break;
                            }
                        }                        
                        break;
                    case 6: //Salir
                        system("cls");
                        bandera2 = 1;
                        CleanBuffer();
                        break;
                    default:
                        OpcionInvalida();
                        break;
                    }
                }                
                break;
            
            case 2: //Menu - Gestión de Facturación
                while (!bandera2)
                {
                    bandera2 = 0;
                    system("cls");
                    CleanBuffer();
                    opcSMenu = menuFacturacion();
                    CleanBuffer();
                    break;
                }
            
            case 3: //Menu - Gestión de Pacientes
                system("cls");
                opcSMenu = menuPacientes();
                CleanBuffer();
                break;
            
            case 4: //Salir de ¡ZAS!CLINIC
                CleanBuffer();
                SaltoLinea();   printf("Hasta pronto!!!");  SaltoLinea();
                bandera = 1;
                break;

            default:
                OpcionInvalida();
                system("pause");
                system("cls");
                break;
        } //cierra el switch
    }
    return 0;
}
