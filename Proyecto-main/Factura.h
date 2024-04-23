#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generarFactura(const char* nombreArchivo, const char* nombreVendedor, const char* nombreCliente, const char productos[][50], const float precios[], const int cantidades[], int numProductos, int numFactura)
{
    // Obtener la fecha y hora actual
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    system("cls");
    printf("                    ¡ZAS!CLINIC                    \n");
    printf("                 Sucursal Las Vegas                \n\n");
    printf("===================================================\n");
    printf("N° Factura: %03d\n", numFactura);
    printf("Fecha: %02d/%02d/%4d\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    printf("Hora: %02d:%02d:%02d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    printf("Vendedor: %s\n", nombreVendedor);
    printf("Cliente: %s\n", nombreCliente);
    printf("===================================================\n\n");

    float subtotal = 0.0;
    printf("---------------------------------------------------\n");
    printf("Productos \t\tPrec. Unit. \t\tCantidad \n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < numProductos; i++) {
        printf("- %s  \t\t%.2f        \t\t%d\n", productos[i], precios[i], cantidades[i]);
        subtotal += precios[i] * cantidades[i];
    }
    printf("---------------------------------------------------\n\n");
    // Calcular IVA y total
    float IVA = subtotal * 0.15;
    float total = subtotal + IVA;

    printf("Subtotal:      \t\t%.2f\n", subtotal);
    printf("IVA (15%%):    \t\t%.2f\n", IVA);
    printf("Total con IVA: \t\t%.2f\n", total);
    printf("\n");
    system("pause");

    // Abrir el archivo de texto para escribir la factura
    FILE* archivo = fopen(nombreArchivo, "a");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    // Escribir los datos de la factura en el archivo
    fprintf(archivo, "                    ¡ZAS!CLINIC                    \n");
    fprintf(archivo, "                 Sucursal Las Vegas                \n\n");
    fprintf(archivo, "===================================================\n");
    fprintf(archivo, "N° Factura: %03d\n", numFactura);
    fprintf(archivo, "Fecha: %02d/%02d/%4d\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    fprintf(archivo, "Hora: %02d:%02d:%02d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);    
    fprintf(archivo, "Vendedor: %s\n", nombreVendedor);
    fprintf(archivo, "Cliente: %s\n", nombreCliente);
    fprintf(archivo, "===================================================\n\n");

    fprintf(archivo, "---------------------------------------------------\n");
    fprintf(archivo, "Productos \t\tPrec. Unit. \t\tCantidad \n");
    fprintf(archivo, "---------------------------------------------------\n");
    for (int i = 0; i < numProductos; i++) {
        fprintf(archivo, "- %s  \t\t%.2f        \t\t%d\n", productos[i], precios[i], cantidades[i]);
    }

    fprintf(archivo, "---------------------------------------------------\n\n");
    fprintf(archivo, "Subtotal: %.2f\n", subtotal);
    fprintf(archivo, "IVA (15%%): %.2f\n", IVA);
    fprintf(archivo, "Total con IVA: %.2f\n", total);
    fprintf(archivo, "\n");

    // Cerrar el archivo
    fclose(archivo);
}

void visualizarFactura(const char* nombreArchivo)
{
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char caracter;
    while ((caracter = fgetc(archivo)) != EOF) {
        putchar(caracter);
    }

    fclose(archivo);
    system("pause");
}

void guardarNumeroFactura(int numFactura)
{
    FILE* archivo = fopen("numero_factura.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para guardar el número de factura.\n");
        return;
    }

    fprintf(archivo, "%d", numFactura);

    fclose(archivo);
}

int obtenerNumeroFactura()
{
    FILE* archivo = fopen("numero_factura.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para obtener el número de factura.\n");
        return 1;
    }

    int numFactura;
    fscanf(archivo, "%d", &numFactura);

    fclose(archivo);

    return numFactura;
}

int menuFacturacion()
{    
    int numFactura = obtenerNumeroFactura();
    int opc;
    while (1)
    {
        system("cls");
        printf("******************* Menu - Gestion de la Facturacion *******************\n\n");
        printf("- Opcion 1: Crear Nueva factura\n"); 
        printf("- Opcion 2: Visualizar Facturas\n");
        printf("- Opcion 3: Salir\n");
        printf("- Digite su opcion: ");
        scanf("%d", &opc); system("cls");        

        if (opc == 1) {
            char nombreVendedor[50];
            char nombreCliente[50];
            int numProductos;

            printf("Ingrese el nombre del vendedor: ");
            scanf("%s", nombreVendedor);
            printf("Ingrese el nombre del cliente: ");
            scanf("%s", nombreCliente);
            printf("Ingrese el número de productos: ");
            scanf("%d", &numProductos);

            char productos[numProductos][50];
            float precios[numProductos];
            int cantidades[numProductos];

            for (int i = 0; i < numProductos; i++) {
                printf("\nIngrese los datos del producto #%d:\n", i + 1);
                printf("Nombre del producto: ");
                scanf(" %[^\n]s", productos[i]);
                printf("Precio unitario: ");
                scanf("%f", &precios[i]);
                printf("Cantidad: ");
                scanf("%d", &cantidades[i]);
            }

            // Generar un nombre único para el archivo de factura
            char nombreArchivo[50];
            sprintf(nombreArchivo, "factura_%03d.txt", numFactura);

            generarFactura(nombreArchivo, nombreVendedor, nombreCliente, productos, precios, cantidades, numProductos, numFactura);

            numFactura++; // Incrementar el número de factura para la siguiente factura
            guardarNumeroFactura(numFactura);
            system("cls");
        } else if (opc == 2) {
            int numFacturaMostrar;
            printf("Ingrese el número de factura a visualizar: ");
            scanf("%d", &numFacturaMostrar);

            char nombreArchivo[50];
            sprintf(nombreArchivo, "factura_%03d.txt", numFacturaMostrar);

            visualizarFactura(nombreArchivo);
        } else if (opc == 3) {
            printf("\nSaliendo del programa...\n");
            break;
        } else {
            printf("Opción inválida. Por favor, ingrese una opción válida.\n");
        }
    }

    return 0;
}
