#include <stdio.h>
#include <string.h>

void SaltoLinea()
{
    printf("\n");
}
void CleanBuffer()
{
    fflush(stdin);
    fflush(stdout);
}
void OpcionInvalida()
{
    printf("Ingrese una opcion valida!!");
}
int menu()
{
    int opc = 0;
    printf("******************* ¡ZAS!CLINIC *******************"); SaltoLinea(); SaltoLinea();
    printf("- Opcion 1: Menu Gestion de Inventario"); SaltoLinea();
    printf("- Opcion 2: Menu Gestion de la Facturacion"); SaltoLinea();
    printf("- Opcion 3: Menu Gestion de Pacientes"); SaltoLinea();
    printf("- Opcion 4: Salir"); SaltoLinea();
    printf("- Digite su opcion: ");
    scanf("%d", &opc); CleanBuffer();
    return opc;
}
int menuInventario()
{
    int opc = 0;
    printf("******************* Menu - Gestion de Inventario *******************"); SaltoLinea(); SaltoLinea();
    printf("- Opcion 1: Visualizar Productos en Exitensia"); SaltoLinea();
    printf("- Opcion 2: Agregar Nuevo Producto"); SaltoLinea();
    printf("- Opcion 3: Editar Datos de un Producto"); SaltoLinea();
    printf("- Opcion 4: Eliminar un Producto"); SaltoLinea();
    printf("- Opcion 5: Menu Proveedores"); SaltoLinea();
    printf("- Opcion 6: Salir"); SaltoLinea();
    printf("- Digite su opcion: ");
    scanf("%d", &opc); CleanBuffer();
    return opc;
}
int menuProducExistencia()
{
    int opc = 0;
    printf("******************* Menu - Productos en Existensia *******************"); SaltoLinea(); SaltoLinea();
    printf("- Opcion 1: Visualizar Todos los productos"); SaltoLinea();
    printf("- Opcion 2: Buscar un producto"); SaltoLinea();
    printf("- Opcion 3: Salir"); SaltoLinea();
    printf("- Digite su opcion: ");
    scanf("%d", &opc); CleanBuffer();
    return opc;
}
int menuProveedores()
{
    int opc = 0;
    printf("******************* Menu - Proveedores *******************"); SaltoLinea(); SaltoLinea();
    printf("- Opcion 1: Visualizar Proveedores"); SaltoLinea();
    printf("- Opcion 2: Agregar Nuevo Proveedor"); SaltoLinea();
    printf("- Opcion 3: Editar Datos de Proveedor"); SaltoLinea();
    printf("- Opcion 4: Eliminar Proveedor"); SaltoLinea();
    printf("- Opcion 5: Salir"); SaltoLinea();
    printf("- Digite su opcion: ");
    scanf("%d", &opc); CleanBuffer();
}
int menuPacientes()
{
    int opc = 0;
    printf("******************* Menu - Gestion de Pacientes *******************"); SaltoLinea(); SaltoLinea();
    printf("- Opcion 1: Agregar Paciente"); SaltoLinea();
    printf("- Opcion 2: Eliminar Paciente"); SaltoLinea();
    printf("- Opcion 3: Visualizar Paciente"); SaltoLinea();
    printf("- Opcion 4: Salir"); SaltoLinea();
    printf("- Digite su opcion: ");
    scanf("%d", &opc); CleanBuffer();
    return opc;
}
int submenuPacientes()
{
    int opc = 0;
    printf("******************* Menu - Visualizar Pacientes *******************"); SaltoLinea(); SaltoLinea();
    printf("- Opcion 1: Datos del Paciente"); SaltoLinea();
    printf("- Opcion 2: Datos de Emergencia"); SaltoLinea();
    printf("- Opcion 3: Datos Clinicos"); SaltoLinea();
    printf("- Opcion 4: Salir"); SaltoLinea();
    printf("- Digite su opcion: ");
    scanf("%d", &opc); CleanBuffer();
    return opc;
}
