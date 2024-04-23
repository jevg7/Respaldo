#include <stdio.h>

int main() {
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
     printf("Por lo tanto usted no aplica a un bono\n");
     printf("Su salario neto es de: C$%.2f\n", salario_neto);
     }   
      if (llamadas <= 50 && evaluacion_recibida >= 6 && evaluacion_recibida < 8) 
      {
     bono_aplicable = 0;
     salario_neto = salario_bruto + bono_aplicable;
     printf("Su salario bruto es de: C$%d\n", salario_bruto);
     printf("Su rendimiento fue aceptable\n");
     printf("Por lo tanto usted no aplica a un bono\n");
     printf("Su salario neto es de: C$%d\n", salario_neto);
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
     printf("Por lo tanto usted no aplica a un bono\n");
     printf("Su salario neto es de: C$ %.2f\n", salario_neto);
    }

     if (llamadas > 50 && llamadas <= 100 && evaluacion_recibida >= 6 && evaluacion_recibida < 8) 
    {
        bono_aplicable = 1000;
        salario_neto = salario_bruto + bono_aplicable;

     printf("Su salario bruto es de: C$ %.2f\n", salario_bruto);
     printf("Su rendimiento fue aceptable\n");
     printf("Por lo tanto usted aplica a un bono de C$1000\n");
     printf("Su salario neto es de: C$ %.2f\n", salario_neto);
    }

     if (llamadas > 50 && llamadas <= 100 && evaluacion_recibida >= 8 && evaluacion_recibida <= 10) 
    {
        bono_aplicable = 1000;
        salario_neto = salario_bruto + bono_aplicable;

     printf("Su salario bruto es de: C$ %.2f\n", salario_bruto);
     printf("¡Felicidades, su rendimiento fue excelente!\n");
     printf("Por lo tanto usted aplica a un bono de C$1000\n");
     printf("Su salario neto es de: C$ %.2f\n", salario_neto);
    }

     if (llamadas > 100 && llamadas <= 150 && evaluacion_recibida >= 1 && evaluacion_recibida < 6) 
    {
        bono_aplicable = 0;
        salario_neto = salario_bruto + bono_aplicable;

     printf("Su salario bruto es de: C$ %.2f\n", salario_bruto);
     printf("Su rendimiento fue deficiente\n");
     printf("Por lo tanto usted no aplica a un bono\n");
     printf("Su salario neto es de: C$ %.2f\n", salario_neto);
    }

     if (llamadas > 100 && llamadas <= 150 && evaluacion_recibida >= 6 && evaluacion_recibida < 8)
     {
        bono_aplicable = 1500;
        salario_neto = salario_bruto + bono_aplicable;
    
     printf("Su salario bruto es de: C$%.2f\n", salario_bruto);
     printf("Su rendimiento fue aceptable\n");
     printf("Por lo tanto usted aplica a un bono de C$%.2f\n", bono_aplicable);
     printf("Su salario neto es de: C$%.2f\n", salario_neto);
     } 
     if (llamadas > 100 && llamadas <= 150 && evaluacion_recibida >= 8 && evaluacion_recibida <= 10) 
     {
     bono_aplicable = 1500;
     salario_neto = salario_bruto + bono_aplicable;
    
     printf("Su salario bruto es de: C$%.2f\n", salario_bruto);
     printf("¡Felicidades, su rendimiento fue excelente!\n");
     printf("Por lo tanto usted aplica a un bono de C$%.2f\n", bono_aplicable);
     printf("Su salario neto es de: C$%.2f\n", salario_neto);
     } 
     if (llamadas > 150 && evaluacion_recibida >= 1 && evaluacion_recibida < 6) 
     {
     bono_aplicable = 0;
     salario_neto = salario_bruto + bono_aplicable;
    
     printf("Su salario bruto es de: C$%.2f\n", salario_bruto);
     printf("Su rendimiento fue deficiente\n");
     printf("Por lo tanto usted no aplica a un bono\n");
     printf("Su salario neto es de: C$%.2f\n", salario_neto);
     } 
     if (llamadas > 150 && evaluacion_recibida >= 6 && evaluacion_recibida < 8) 
     {
     bono_aplicable = 2000;
     salario_neto = salario_bruto + bono_aplicable;
    
     printf("Su salario bruto es de: C$%.2f\n", salario_bruto);
     printf("Su rendimiento fue aceptable\n");
     printf("Por lo tanto usted aplica a un bono de C$%.2f\n", bono_aplicable);
     printf("Su salario neto es de: C$%.2f\n", salario_neto);
     } 
     if (llamadas > 150 && evaluacion_recibida >= 8 && evaluacion_recibida <= 10) 
     {
     bono_aplicable = 2000;
     salario_neto = salario_bruto + bono_aplicable;
    
     printf("Su salario bruto es de: C$%.2f\n", salario_bruto);
     printf("¡Felicidades, su rendimiento fue excelente!\n");
     printf("Por lo tanto usted aplica a un bono de C$%.2f\n", bono_aplicable);
     printf("Su salario neto es de: C$%.2f\n", salario_neto);
} 

}