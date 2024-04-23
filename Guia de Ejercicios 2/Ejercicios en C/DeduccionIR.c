#include <stdio.h>

int main()
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


}