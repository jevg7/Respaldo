Proceso ImpuestoSobreRenta
	
	Definir salario_mensual,salario_anual, salario_bruto_inss, salario_neto, deduccionIR, pago_anualIR  Como Real;
	Definir INSS Como Real;
	
	Escribir "Ingrese su salario mensual: ";
	Leer salario_mensual;
	
	salario_anual <- salario_mensual * 12;
	
	Escribir "Su salario anual bruto es de: C$", salario_anual;
	
	INSS<- salario_anual * 0.07;
	
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
	
	
FinProceso
