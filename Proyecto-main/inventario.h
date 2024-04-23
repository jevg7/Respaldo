#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTOS 100
#define MAX_PROVEEDORES 100

struct Producto {
  char nombre[50];
  char tipo[20];
  int cantidad;
};

struct Proveedor {
  char nombre[50];
  char contacto[50];
};

struct Inventario {
  struct Producto productos[MAX_PRODUCTOS];
  int numProductos;
  struct Proveedor proveedores[MAX_PROVEEDORES];
  int numProveedores;
};

void agregarProducto(struct Inventario *inventario) {
  if (inventario->numProductos == MAX_PRODUCTOS) {
    printf("Se ha alcanzado el numero maximo de productos.\n");
    return;
  }

  struct Producto *producto = &inventario->productos[inventario->numProductos];
  printf("Ingrese el nombre del producto: ");
  scanf("%s", producto->nombre);
  printf("Ingrese el tipo del producto: ");
  scanf("%s", producto->tipo);
  printf("Ingrese la cantidad del producto: ");
  scanf("%d", &producto->cantidad);

  inventario->numProductos++;
}

void agregarProveedor(struct Inventario *inventario) {
  if (inventario->numProveedores == MAX_PROVEEDORES) {
    printf("Se ha alcanzado el numero maximo de proveedores.\n");
    return;
  }

  struct Proveedor *proveedor = &inventario->proveedores[inventario->numProveedores];
  printf("Ingrese el nombre del proveedor: ");
  scanf("%s", proveedor->nombre);
  printf("Ingrese la informacion de contacto del proveedor: ");
  scanf("%s", proveedor->contacto);

  inventario->numProveedores++;
}

void imprimirProductos(struct Inventario *inventario) {
  printf("Inventario de Productos:\n");
  for (int i = 0; i < inventario->numProductos; i++) {
    struct Producto *producto = &inventario->productos[i];
    printf("Nombre: %s\tTipo: %s\tCantidad: %d\n", producto->nombre, producto->tipo, producto->cantidad);
  }
}

void imprimirProveedores(struct Inventario *inventario) {
  printf("Lista de Proveedores:\n");
  for (int i = 0; i < inventario->numProveedores; i++) {
    struct Proveedor *proveedor = &inventario->proveedores[i];
    printf("Nombre: %s\tContacto: %s\n", proveedor->nombre, proveedor->contacto);
  }
}

int inventario() {
  struct Inventario inventario;
  inventario.numProductos = 0;
  inventario.numProveedores = 0;

  while (1) {
    int opcion;
    printf("\nSistema de Gestion de Inventario\n");
    printf("1. Agregar producto\n");
    printf("2. Agregar proveedor\n");
    printf("3. Imprimir inventario de productos\n");
    printf("4. Imprimir lista de proveedores\n");
    printf("5. Salir\n");
    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
      case 1:
        agregarProducto(&inventario);
        break;
      case 2:
        agregarProveedor(&inventario);
        break;
      case 3:
        imprimirProductos(&inventario);
        break;
      case 4:
        imprimirProveedores(&inventario);
        break;
      case 5:
        return 0;
      default:
        printf("Opcion invalida. Por favor, intente nuevamente.\n");
    }
  }
}
