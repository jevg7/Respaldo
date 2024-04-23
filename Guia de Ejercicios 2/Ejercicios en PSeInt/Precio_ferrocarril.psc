Proceso Precio_ferrocarril
	
	Definir distancia, dias_estancia, total, total_reduccion, precio_km, reduccion, total_con_reduccion Como Real;
	
	precio_km<- 25;
	reduccion<- 0.30;
	Escribir " ¿Cual es la distancia a recorrer? (km) ";
	Leer distancia;
	
	Escribir " ¿Cuantos dias sera su su estadia? ";
	Leer dias_estancia;
	
	Si distancia>800 y dias_estancia>7  Entonces
		total<-distancia*precio_km;
		total_reduccion<- total*reduccion;
		total_con_reduccion <-total-total_reduccion;		Escribir "El total a pagar con una reduccion del 30% es: ", total_con_reduccion,"C$";
		
	SiNo
		total<- distancia*precio_km;
		Escribir "El total a pagar es: " ,total,"C$";
			
		
		
	FinSi
	
	
	
	
	

	 
	
FinProceso
