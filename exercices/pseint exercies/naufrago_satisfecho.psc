Proceso naufrago_satisfecho
	Definir hamburguesa_simple,hamburguesa_doble,hamburguesa_triple Como Real;
	Definir cargo Como Real;
	Definir ans Como Caracter;
	Definir subtotal, total, userBurgers, cuentaPago, unidaHamb1, unidaHamb2,unidaHamb3 Como Real;
	Definir opt Como Entero;
	
	hamburguesa_simple <- 50.0;
	hamburguesa_doble <- 70.0;
	hamburguesa_triple <- 100.0;
	
	cargo <- 0.0;
	unidaHamb1 <- 0.0;
	unidaHamb2 <- 0.0;
	unidaHamb3 <- 0.0;
	cuentaPago <- 0.0;
	subtotal <- 0.0;
	total <- 0.0;
	userBurgers <- 0.0;
	
	Escribir "Cuantas hamburguesas quieres ordenar?";
	leer userBurgers;
	Escribir "te gustaria pagar con tarjeta s/n ";
	leer ans;
	
	si ans == 's' O ans == 'S' Entonces
		Escribir "1. hambuerguesa simple";
		Escribir "2. hambuerguesa doble";
		Escribir "3. hambuerguesa triple";
		Escribir "4. si quiere llevar hamburguesa de tipos variados";
		leer opt;
		Segun opt Hacer
			1:
				subtotal <- hamburguesa_simple * userBurgers;
				total <- subtotal + (subtotal * cargo);
				Escribir "Su cuenta con el cargo extra es de: ", total;
			2:
				subtotal <- hamburguesa_doble * userBurgers;
				total <- subtotal + (subtotal * cargo);
				Escribir "Su cuenta con el cargo extra es de: ", total;
			3:
				total <- hamburguesa_triple * userBurgers;
				total <- subtotal + (subtotal * cargo);
				Escribir "Su cuenta con el cargo extra es de: ", total;
			4:
				Escribir "ingrese cantidad de hamburguesas simples ";
				leer unidaHamb1;
				Escribir "ingrese cantidad de hamburguesas dobles ";
				leer unidaHamb2;
				Escribir "ingrese cantidad de hamburguesas triples ";
				leer unidaHamb3;
				
				subtotal <- (hamburguesa_simple * unidaHamb1) + (hamburguesa_doble * unidaHamb2) + (hamburguesa_triple * unidaHamb3);
				total <- subtotal + (subtotal * cargo);
				Escribir "Su cuenta con el cargo extra es de: ", total;
				
			De Otro Modo:
				Escribir "opcion no valida";
		FinSegun
	
	SiNo si ans == 'n' O ans == 'N' Entonces
			Escribir "1. hambuerguesa simple";
			Escribir "2. hambuerguesa doble";
			Escribir "3. hambuerguesa triple";
			Escribir "4. si quiere llevar hamburguesa de tipos variados";
			leer opt;
			Segun opt Hacer
				1:
					subtotal <- hamburguesa_simple * userBurgers;
					total <- subtotal;
					Escribir "Su cuenta sin el cargo extra es de: ", total;
				2:
					subtotal <- hamburguesa_doble * userBurgers;
					total <- subtotal;
					Escribir "Su cuenta sin el cargo extra es de: ", total;
				3:
					total <- hamburguesa_triple * userBurgers;
					total <- subtotal;
					Escribir "Su cuenta sin el cargo extra es de: ", total;
				4:
					Escribir "ingrese cantidad de hamburguesas simples ";
					leer unidaHamb1;
					Escribir "ingrese cantidad de hamburguesas dobles ";
					leer unidaHamb2;
					Escribir "ingrese cantidad de hamburguesas triples ";
					leer unidaHamb3;
					
					subtotal <- (hamburguesa_simple * unidaHamb1) + (hamburguesa_doble * unidaHamb2) + (hamburguesa_triple * unidaHamb3);
					total <- subtotal;
					Escribir "Su cuenta sin el cargo extra es de: ", total;
					
				De Otro Modo:
					Escribir "opcion no valida";
			FinSegun
		FinSi
	FinSi
FinProceso
