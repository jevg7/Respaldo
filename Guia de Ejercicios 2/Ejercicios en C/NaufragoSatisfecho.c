#include <stdio.h>

int main()
{
  float opcion, cantidad, precio_unidad, sub_total, total, CARGO, IVA, metodo_pago, total_cargo;
  printf("**************!Bienvenido a El Naufrago Satisfecho!**************\n");
  printf("Ingrese la hamburguesa deseada:\n");
  printf("1.Hamburguesa sencilla (C$50.00)\n");
  printf("2.Hamburguesa doble (C$75.00)\n");
  printf("3.Hamburguesa triple (C$100.00)\n");
  scanf("%f", &opcion);


  printf("¿Cuantas hamburguesas desea llevar?\n");
  scanf("%f", &cantidad);

  printf("Seleccione su metodo de pago\n");
  printf("1.Efectivo\n");
  printf("2.Tarjeta de credito\n");
  scanf("%f", &metodo_pago);

  if (opcion == 1)
   {
    precio_unidad =50;
    
   }

   if (opcion == 2)
   {
     precio_unidad =75;

   }

   if (opcion == 3)
    {
      precio_unidad =100;

    }

 sub_total = precio_unidad * cantidad;

   if (metodo_pago==2)
   {
    sub_total = precio_unidad * cantidad;
    IVA = sub_total * 0.15;
    total = sub_total + IVA;
    CARGO = total * 0.05;
    total_cargo = total + CARGO;

    printf("El Sub Total es de: C$%.2f\n", sub_total);
    printf("Al pagar con tarjeta se le suma un cargo de 5 por ciento por uso\n");
    printf("El Total es de: C$%.2f\n", total_cargo);

   }

   if (metodo_pago==1)
   {
    sub_total = precio_unidad * cantidad;
     IVA = sub_total * 0.15;
     total = sub_total + IVA;

     printf("El Sub Total es de: C$%.2f\n", sub_total);
     printf("El Total es de: C$%.2f\n", total);

   }

    return 0;


}