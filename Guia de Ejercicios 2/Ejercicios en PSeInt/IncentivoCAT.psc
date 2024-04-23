Proceso IncentivoCAT
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
FinProceso


