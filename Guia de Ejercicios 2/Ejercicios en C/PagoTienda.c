#include <stdio.h>

int main()
{
   char article_name[60];
   float unit_price, sub_total, units, total, DISCOUNT, total_discount, total_discount_iva, total_iva, IVA;

   IVA = 0.15;
   DISCOUNT = 0.20;

   printf("Ingrese el nombre del articulo:\n");
   scanf("%s", article_name); 

   printf("Ingrese el precio del producto por unidad:\n");
   scanf("%f", &unit_price);

   printf("Ingrese la cantidad de producto que desee llevar:\n");
   scanf("%f", &units);

   sub_total = unit_price * units;

     if (units>=2)

      {
        total =  sub_total * DISCOUNT;
        total_discount = sub_total - total;
        total_iva = total_discount * IVA;
        total_discount_iva = total_discount + total_iva;
     
        printf("Por la compra de dos o mas unidades se le aplicara un descuento del 20%:\n");
        printf("El total a pagar es de: C$%.2f\n", total_discount_iva);
      }
      else
      {
      total = sub_total * IVA;
      total_iva= sub_total + total;
      printf("Pagara un total de: C$%.2f\n", total_iva);

       }
 return 0;


}


