Proceso GuiaDeEjercicos2
	Definir op Como Entero;
	Escribir "Menu";
	Escribir "1.Pago en tienda";
	Escribir "2. Naufrago Satisfecho";
	Escribir "3. Deduccion IR";
	Escribir "4. Incentivo CAT";
	Escribir "5. Salir del programa";
	
	Leer op;
	
	Si op = 1 Entonces
		Definir art_name Como Caracter;
		Definir unit_price, sub_total, units, total, iva, dis, total_dis, total_dis_iva, total_iva Como Real;
		
		iva<- 0.15;
		dis<-0.20; 
		
		Escribir "Ingrese el nombre del articulo:";
		Leer art_name;
		
		Escribir "Ingrese el precio del producto por unidad:";
		Leer unit_price;
		
		Escribir "Ingrese la cantidad del producto:";
		Leer units;
		
		sub_total<- unit_price * units;
		
		Si units>=2 Entonces
			total<- sub_total * dis;
			
			total_dis<- sub_total - total;
			
			total_iva<- total_dis * iva;
			
			total_dis_iva<- total_dis + total_iva;
			
			Escribir "Por la compra de dos o mas unidades se le aplicara un descuento del 20%";
			
			Escribir "El total a pagar es de: C$", total_dis_iva;
		SiNo
			total<- sub_total * iva;
			total_iva<- sub_total + total;
			Escribir " Pagara un total de: C$", total_iva;
			
		FinSi
	FinSi
	
	Si op = 2 Entonces
		Definir opcion, cantidad, precio_unidad, sub_total, total, CARGO, IVA, metodo_pago,total_cargo Como Real;
		
		Escribir "!Bienvenido a El Naufrago Satisfecho!";
		Escribir "Ingrese la hamburguesa deseada:";
		Escribir "1.Hamburguesa sencilla (C$50)";
		Escribir "2.Hamburguesa doble (C$75)";
		Escribir "3.Hamburguesa triple (C$100)";
		Leer opcion;
		
		Escribir "¿Cuantas hamburguesas desea llevar?";
		Leer cantidad;
		
		Escribir "Ingrese su metodo de pago";
		Escribir "1.Efectivo";
		Escribir "2.Tarjeta de credito";
		Leer metodo_pago;
		
		Si opcion = 1 Entonces
			precio_unidad <- 50.00;
			
		FinSi
		
		Si opcion = 2 Entonces
			precio_unidad <- 75.00;
			
		FinSi
		
		Si opcion = 3 Entonces
			precio_unidad <- 100.00;
			
		FinSi
		
		sub_total<- precio_unidad * cantidad;
		
		Si metodo_pago = 2 Entonces
			IVA<- sub_total * 0.15;
			total<- sub_total + IVA;
			CARGO<- total*0.05;
			
			
			total_cargo<- total + CARGO;
			
			Escribir " El Sub Total es de: C$", sub_total;
			
			Escribir "Al pagar con tarjeta se le suma un cargo de 5% por uso";
			Escribir " El Total es de: C$", total_cargo;
		FinSi
		
		Si metodo_pago = 1 Entonces
			
			IVA<- sub_total * 0.15;
			total<- sub_total + IVA;
			
			Escribir "El Sub Total es de: C$", sub_total;
			
			Escribir "El Total es de: C$",total;
			
			
		FinSi
	FinSi
	
	Si op = 3 Entonces
		Definir salario_mensual,salario_anual, salario_bruto_inss, salario_neto, deduccionIR, pago_anualIR  Como Real;
		Definir INSS Como Real;
		
		Escribir "Ingrese su salario mensual: ";
		Leer salario_mensual;
		
		salario_anual <- salario_mensual * 12;
		
		Escribir "Su salario anual bruto es de: C$", salario_anual;
		
		INSS<- salario_anual * 0.0625;
		
		salario_bruto_inss<- salario_anual - INSS;
		
		Escribir "Se le aplicara la deduccion del seguro social de: C$", INSS;
		Escribir "Su salario es de: C$", salario_bruto_inss;
		
		Si salario_bruto_inss>0.01 y salario_bruto_inss<=100000 Entonces
			
			Escribir "No se aplicaran deducciones de IR";
			
		FinSi
		
		Si salario_bruto_inss>=100000.01 y salario_bruto_inss<=200000 Entonces
			
			deduccionIR<- salario_bruto_inss - 100000;
			pago_anualIR<- deduccionIR * 0.15;
			salario_neto<- salario_bruto_inss - pago_anualIR;
			
			Escribir "Usted debe pagar una deduccion anual de: C$", pago_anualIR;
			Escribir "Su salario neto es de: C$", salario_neto;
			
		FinSi
		
		Si salario_bruto_inss>=200000.01 y salario_bruto_inss<=350000 Entonces
			
			deduccionIR<- salario_bruto_inss - 200000;
			pago_anualIR<- (deduccionIR * 0.20) +15000;
			salario_neto<- salario_bruto_inss - pago_anualIR;
			
			Escribir "Usted debe pagar una deduccion anual de: C$", pago_anualIR;
			Escribir "Su salario neto es de: C$", salario_neto;
			
			
		FinSi
		
		Si salario_bruto_inss>=350000.01 y salario_bruto_inss<=500000 Entonces
			
			deduccionIR<- salario_bruto_inss - 350000;
			pago_anualIR<- (deduccionIR * 0.25) +45000;
			salario_neto<- salario_bruto_inss - pago_anualIR;
			
			Escribir "Usted debe pagar una deduccion anual de: C$", pago_anualIR;
			Escribir "Su salario neto es de: C$", salario_neto;
			
			
		FinSi
		
		Si salario_bruto_inss>=500000.01 Entonces
			
			deduccionIR<- salario_bruto_inss - 500000;
			pago_anualIR<- (deduccionIR * 0.30) +82500;
			salario_neto<- salario_bruto_inss - pago_anualIR;
			
			Escribir "Usted debe pagar una deduccion anual de: C$", pago_anualIR;
			Escribir "Su salario neto es de: C$", salario_neto;
			
			
		FinSi
		
	FinSi
	
	Si op = 4 Entonces
		Definir salario_bruto, bono_aplicable, evaluacion_recibida, salario_neto, llamadas Como Real;
		
		
		Escribir "Ingrese su salario semanal: ";
		Leer salario_bruto;
		
		Escribir "¿Cual la evaluacion recibida por parte de su jefe? (0-10):";
		Leer evaluacion_recibida;
		
		Escribir "Ingrese la cantidad de llamdas atendidas en el mes:";
		Leer llamadas;
		
		Si llamadas<=50 y evaluacion_recibida>=1 y evaluacion_recibida<=5 Entonces
			
			bono_aplicable<-0;
			salario_neto<- salario_bruto + bono_aplicable;
			Escribir "Su salario bruto es de: C$", salario_bruto;
			Escribir "Su desempeño fue deficiente";
			Escribir "Por lo tanto usted no aplica a un bono";
			Escribir "Su salario neto es de: C$", salario_neto;
			
		FinSi
		Si llamadas<=50 y evaluacion_recibida>=6 y evaluacion_recibida<8 Entonces
			
			bono_aplicable<-0;
			salario_neto<- salario_bruto + bono_aplicable;
			Escribir "Su salario bruto es de: C$", salario_bruto;
			Escribir "Su desempeño fue deficiente";
			Escribir "Por lo tanto usted no aplica a un bono";
			Escribir "Su salario neto es de: C$", salario_neto;
			
		FinSi
		Si llamadas<=50 y evaluacion_recibida>=8 y evaluacion_recibida<=10 Entonces
			
			bono_aplicable<-0;
			salario_neto<- salario_bruto + bono_aplicable;
			Escribir "Su salario bruto es de: C$", salario_bruto;
			Escribir "Su desempeño fue deficiente";
			Escribir "Por lo tanto usted no aplica a un bono";
			Escribir "Su salario neto es de: C$", salario_neto;
			
		FinSi
		Si llamadas>1 y evaluacion_recibida = 0 Entonces
			Escribir "Su desempeño es asqueroso";
			Escribir "Lamentablemente usted sera despedido";
			Escribir "Su ultimo salario sera de: C$", salario_bruto;
			
		FinSi
		Si  llamadas>50 y llamadas<=100  y evaluacion_recibida>=1 y evaluacion_recibida<=5 Entonces
			
			bono_aplicable<-0;
			salario_neto<- salario_bruto + bono_aplicable;
			Escribir "Su salario bruto es de: C$", salario_bruto;
			Escribir "Su desempeño fue deficiente";
			Escribir "Por lo tanto usted no aplica a un bono";
			Escribir "Su salario neto es de: C$", salario_neto;
			
		FinSi
		
		Si llamadas>50 y llamadas<=100 y evaluacion_recibida>=6 y evaluacion_recibida<8 Entonces
			
			bono_aplicable<- 1000;
			salario_neto<- salario_bruto + bono_aplicable;
			
			Escribir "Su salario bruto es de: C$", salario_bruto;
			Escribir "Su desempeño fue aceptable";
			Escribir "Por lo tanto usted aplica a un bono de C$1000";
			Escribir "Su salario neto es de: C$", salario_neto;
			
		FinSi
		
		Si llamadas>50 y llamadas<=100 y evaluacion_recibida>=8 y evaluacion_recibida<=10 Entonces
			
			bono_aplicable<- 1000;
			salario_neto<- salario_bruto + bono_aplicable;
			
			Escribir "Su salario bruto es de: C$", salario_bruto;
			Escribir "¡Felicidades, su desempeño fue excelente!";
			Escribir "Por lo tanto usted aplica a un bono de C$1000";
			Escribir "Su salario neto es de: C$", salario_neto;
			
		FinSi
		Si llamadas>100 y llamadas<=150 y evaluacion_recibida>=1 y evaluacion_recibida<6 Entonces
			
			bono_aplicable<- 0;
			salario_neto<- salario_bruto + bono_aplicable;
			
			Escribir "Su salario bruto es de: C$", salario_bruto;
			Escribir "Su desempeño fue deficiente";
			Escribir "Por lo tanto usted no aplica a un bono";
			Escribir "Su salario neto es de: C$", salario_neto;
			
		FinSi
		Si llamadas>100 y llamadas<=150 y evaluacion_recibida>=6 y evaluacion_recibida<8 Entonces
			
			bono_aplicable<- 1500;
			salario_neto<- salario_bruto + bono_aplicable;
			
			Escribir "Su salario bruto es de: C$", salario_bruto;
			Escribir "Su desempeño fue aceptable";
			Escribir "Por lo tanto usted aplica a un bono de C$1500";
			Escribir "Su salario neto es de: C$", salario_neto;
			
		FinSi
		Si llamadas>100 y llamadas<=150 y evaluacion_recibida>=8 y evaluacion_recibida<=10 Entonces
			
			bono_aplicable<- 1500;
			salario_neto<- salario_bruto + bono_aplicable;
			
			Escribir "Su salario bruto es de: C$", salario_bruto;
			Escribir "¡Felicidades, su desempeño fue excelente!";
			Escribir "Por lo tanto usted aplica a un bono de C$1500";
			Escribir "Su salario neto es de: C$", salario_neto;
			
		FinSi
		Si llamadas>150 y evaluacion_recibida>=1 y evaluacion_recibida<6 Entonces
			
			bono_aplicable<- 0;
			salario_neto<- salario_bruto + bono_aplicable;
			
			Escribir "Su salario bruto es de: C$", salario_bruto;
			Escribir "Su desempeño fue deficiente";
			Escribir "Por lo tanto usted no aplica a un bono";
			Escribir "Su salario neto es de: C$", salario_neto;
			
		FinSi
		Si llamadas>150 y evaluacion_recibida>=6 y evaluacion_recibida<8 Entonces
			
			bono_aplicable<- 2000;
			salario_neto<- salario_bruto + bono_aplicable;
			
			Escribir "Su salario bruto es de: C$", salario_bruto;
			Escribir "Su desempeño fue aceptable";
			Escribir "Por lo tanto usted aplica a un bono de C$2000";
			Escribir "Su salario neto es de: C$", salario_neto;
			
		FinSi
		Si llamadas>150 y evaluacion_recibida>=8 y evaluacion_recibida<=10 Entonces
			
			bono_aplicable<- 2000;
			salario_neto<- salario_bruto + bono_aplicable;
			
			Escribir "Su salario bruto es de: C$", salario_bruto;
			Escribir "¡Felicidades, su desempeño fue excelente!";
			Escribir "Por lo tanto usted aplica a un bono de C$2000";
			Escribir "Su salario neto es de: C$", salario_neto;
		
	 FinSi
 FinSi
 
 Si op = 5 Entonces
	 Escribir "Hasta pronto";
 FinSi
 
 si op >5 Entonces
	 Escribir "Opcion invalida";
 FinSi

	
FinProceso
