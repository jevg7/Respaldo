Proceso NaufragoSatisfecho
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

FinProceso
