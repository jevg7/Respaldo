#include <stdio.h>

int main(void) 
{
    int opt;

    printf("Menu de opciones\n");
    printf("1. Pago en una tienda\n");
    printf("2. Naufrago Satisfecho\n");
    printf("3. Deduccion de IR\n");
    printf("4. Incentivo CAT\n");
    printf("5. Salir del programa\n");
    printf("Elija la opcion a la que desea ingresar:\n ");
    scanf("%i", &opt);

    switch (opt) 
    {
        case 1: {
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

            if (units >= 2) {
                total = sub_total * DISCOUNT;
                total_discount = sub_total - total;
                total_iva = total_discount * IVA;
                total_discount_iva = total_discount + total_iva;

                printf("Por la compra de dos o mas unidades se le aplicara un descuento del 20%%:\n");
                printf("El total a pagar es de: C$%.2f\n", total_discount_iva);
            } else {
                total = sub_total * IVA;
                total_iva = sub_total + total;
                printf("Pagara un total de: C$%.2f\n", total_iva);
            }
            break;
        }

        case 2: 
        {
            float opcion, cantidad, precio_unidad, sub_total, total, CARGO, IVA, metodo_pago, total_cargo;
            printf("**************!Bienvenido a El Naufrago Satisfecho!**************\n");
            printf("Ingrese la hamburguesa deseada:\n");
            printf("1. Hamburguesa sencilla (C$50.00)\n");
            printf("2. Hamburguesa doble (C$75.00)\n");
            printf("3. Hamburguesa triple (C$100.00)\n");
            scanf("%f", &opcion);

            printf("¿Cuantas hamburguesas desea llevar?\n");
            scanf("%f", &cantidad);

            printf("Seleccione su metodo de pago\n");
            printf("1. Efectivo\n");
            printf("2. Tarjeta de credito\n");
            scanf("%f", &metodo_pago);

            if (opcion == 1) 
             {
                precio_unidad = 50;
             } 
             if (opcion == 2) 
             {
                precio_unidad = 75;
             }
              if (opcion == 3) 
             {
                precio_unidad = 100;
             }

             sub_total = precio_unidad * cantidad;

             if (metodo_pago == 2) 
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
            break;
        }
        case 3: 
        {
            float salario_mensual, salario_anual, salario_bruto_inss, salario_neto, deduccionIR, pago_anualIR, INSS;

            printf("Ingrese su salario mensual:\n");
          scanf("%f", &salario_mensual);

         salario_anual = salario_mensual * 12;

         printf("Su salario anual bruto es de: C$%2.f\n",salario_anual);

         INSS = salario_anual * 0.07;

            salario_bruto_inss = salario_anual-INSS;

            printf("Se le aplicara la deduccion del seguro social de: C$%2.f\n",INSS);
            printf("Su salario es de: C$%.2f\n", salario_bruto_inss);

            if ( (salario_bruto_inss>0.01) && (salario_bruto_inss<=100000) )
            {
                printf("No se le aplica deduccion de IR");
            }
            
            if ( (salario_bruto_inss>=100000.01) && (salario_bruto_inss<=200000) )
            {
                deduccionIR = salario_bruto_inss - 100000;
                pago_anualIR = deduccionIR * 0.15;
                salario_neto = salario_bruto_inss - pago_anualIR;

                printf("Usted debe pagar una deduccion anual de: C$%.2f\n",pago_anualIR);
                printf("Su salario neto es de: C$%.2f\n", salario_neto);

            }
            
            if ( (salario_bruto_inss>=200000.01) && (salario_bruto_inss<=350000) )
            {
                deduccionIR = salario_bruto_inss - 200000;
                pago_anualIR = (deduccionIR * 0.20)+15000;
                salario_neto = salario_bruto_inss - pago_anualIR;

                printf("Usted debe pagar una deduccion anual de: C$%.2f\n",pago_anualIR);
                printf("Su salario neto es de: C$%.2f\n", salario_neto);

            }

            if ( (salario_bruto_inss>=350000.01) && (salario_bruto_inss<=500000) )
            {
                deduccionIR = salario_bruto_inss - 350000;
                pago_anualIR = (deduccionIR * 0.25)+45000;
                salario_neto = salario_bruto_inss - pago_anualIR;

                printf("Usted debe pagar una deduccion anual de: C$%.2f\n",pago_anualIR);
                printf("Su salario neto es de: C$%.2f\n", salario_neto);

            }

            if ( (salario_bruto_inss>=500000.01) )
            {
                deduccionIR = salario_bruto_inss - 500000;
                pago_anualIR = (deduccionIR * 0.30)+82500;
                salario_neto = salario_bruto_inss - pago_anualIR;

                printf("Usted debe pagar una deduccion anual de: C$%.2f\n",pago_anualIR);
                printf("Su salario neto es de: C$%.2f\n", salario_neto);

            }
                break;
                    }

          case 4:
           {
            float salario_bruto, bono_aplicable, evaluacion_recibida, salario_neto, llamadas;

            printf("Ingrese su salario semanal: \n");
            scanf("%f", &salario_bruto);

            printf("¿Cual la evaluacion recibida por parte de su jefe? (0-10):\n");
            scanf("%f", &evaluacion_recibida);

            printf("Ingrese la cantidad de llamadas atendidas en el mes:\n");
            scanf("%f", &llamadas);

            if (llamadas <= 50 && evaluacion_recibida >= 1 && evaluacion_recibida <= 5) 
            {
            bono_aplicable = 0;
            salario_neto = salario_bruto + bono_aplicable;
            printf("Su salario bruto es de: C$%.2f\n", salario_bruto);
            printf("Su rendimiento fue deficiente\n");
            printf(" Usted no aplica a un bono\n");
            printf("Su salario neto es de: C$%.2f\n", salario_neto);
            }   
            if (llamadas <= 50 && evaluacion_recibida >= 6 && evaluacion_recibida < 8) 
            {
            bono_aplicable = 0;
            salario_neto = salario_bruto + bono_aplicable;
            printf("Su salario bruto es de: C$%.2f\n", salario_bruto);
            printf("Su rendimiento fue aceptable\n");
            printf(" Usted no aplica a un bono\n");
            printf("Su salario neto es de: C$%.2f\n", salario_neto);
            }    
            if (llamadas <= 50 && evaluacion_recibida >= 8 && evaluacion_recibida <= 10) 
            {
            bono_aplicable = 0;
            salario_neto = salario_bruto + bono_aplicable;
            printf("Su salario bruto es de: C$%.2f\n", salario_bruto);
            printf("Su rendimiento fue deficiente\n");
            printf("¡Felicidades, su rendimiento fue excelente!, pero no aplica a un bono\n");
            printf("Su salario neto es de: C$%.2f\n", salario_neto);
            }


            if (llamadas > 1 && evaluacion_recibida == 0) 
            {
            printf("Su rendimiento es asqueroso\n");
            printf("Lamentablemente usted sera despedido\n");
            printf("Su ultimo salario sera de: C$ %.2f\n", salario_bruto);
            }

            if (llamadas > 50 && llamadas <= 100 && evaluacion_recibida > 1 && evaluacion_recibida <= 5) 
            {
                bono_aplicable = 0;
                salario_neto = salario_bruto + bono_aplicable;

            printf("Su salario bruto es de: C$ %.2f\n", salario_bruto);
            printf("Su rendimiento fue deficiente\n");
            printf(" Usted no aplica a un bono\n");
            printf("Su salario neto es de: C$ %.2f\n", salario_neto);
            }

            if (llamadas > 50 && llamadas <= 100 && evaluacion_recibida >= 6 && evaluacion_recibida < 8) 
            {
                bono_aplicable = 1000;
                salario_neto = salario_bruto + bono_aplicable;

            printf("Su salario bruto es de: C$ %.2f\n", salario_bruto);
            printf("Su rendimiento fue aceptable\n");
            printf(" Usted aplica a un bono de C$1000\n");
            printf("Su salario neto es de: C$ %.2f\n", salario_neto);
            }

            if (llamadas > 50 && llamadas <= 100 && evaluacion_recibida >= 8 && evaluacion_recibida <= 10) 
            {
                bono_aplicable = 1000;
                salario_neto = salario_bruto + bono_aplicable;

            printf("Su salario bruto es de: C$ %.2f\n", salario_bruto);
            printf("¡Felicidades, su rendimiento fue excelente!\n");
            printf(" Usted aplica a un bono de C$1000\n");
            printf("Su salario neto es de: C$ %.2f\n", salario_neto);
            }

            if (llamadas > 100 && llamadas <= 150 && evaluacion_recibida >= 1 && evaluacion_recibida < 6) 
            {
                bono_aplicable = 0;
                salario_neto = salario_bruto + bono_aplicable;

            printf("Su salario bruto es de: C$ %.2f\n", salario_bruto);
            printf("Su rendimiento fue deficiente\n");
            printf(" Usted no aplica a un bono\n");
            printf("Su salario neto es de: C$ %.2f\n", salario_neto);
            }

            if (llamadas > 100 && llamadas <= 150 && evaluacion_recibida >= 6 && evaluacion_recibida < 8)
            {
                bono_aplicable = 1500;
                salario_neto = salario_bruto + bono_aplicable;
            
            printf("Su salario bruto es de: C$%.2f\n", salario_bruto);
            printf("Su rendimiento fue aceptable\n");
            printf(" Usted aplica a un bono de C$%.2f\n", bono_aplicable);
            printf("Su salario neto es de: C$%.2f\n", salario_neto);
            } 
            if (llamadas > 100 && llamadas <= 150 && evaluacion_recibida >= 8 && evaluacion_recibida <= 10) 
            {
            bono_aplicable = 1500;
            salario_neto = salario_bruto + bono_aplicable;
            
            printf("Su salario bruto es de: C$%.2f\n", salario_bruto);
            printf("¡Felicidades, su rendimiento fue excelente!\n");
            printf(" Usted aplica a un bono de C$%.2f\n", bono_aplicable);
            printf("Su salario neto es de: C$%.2f\n", salario_neto);
            } 
            if (llamadas > 150 && evaluacion_recibida >= 1 && evaluacion_recibida < 6) 
            {
            bono_aplicable = 0;
            salario_neto = salario_bruto + bono_aplicable;
            
            printf("Su salario bruto es de: C$%.2f\n", salario_bruto);
            printf("Su rendimiento fue deficiente\n");
            printf(" Usted no aplica a un bono\n");
            printf("Su salario neto es de: C$%.2f\n", salario_neto);
            } 
            if (llamadas > 150 && evaluacion_recibida >= 6 && evaluacion_recibida < 8) 
            {
            bono_aplicable = 2000;
            salario_neto = salario_bruto + bono_aplicable;
            
            printf("Su salario bruto es de: C$%.2f\n", salario_bruto);
            printf("Su rendimiento fue aceptable\n");
            printf(" Usted aplica a un bono de C$%.2f\n", bono_aplicable);
            printf("Su salario neto es de: C$%.2f\n", salario_neto);
            } 
            if (llamadas > 150 && evaluacion_recibida >= 8 && evaluacion_recibida <= 10) 
            {
            bono_aplicable = 2000;
            salario_neto = salario_bruto + bono_aplicable;
            
            printf("Su salario bruto es de: C$%.2f\n", salario_bruto);
            printf("¡Felicidades, su rendimiento fue excelente!\n");
            printf(" Usted aplica a un bono de C$%.2f\n", bono_aplicable);
            printf("Su salario neto es de: C$%.2f\n", salario_neto);
            } 
            
         case 5:
         {
            printf("Hasta pronto");
            break;
         }

        default:
            printf("Opcion invalida\n");
            break;
          }    
    } 
}
       



    



