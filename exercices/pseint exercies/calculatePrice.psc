Proceso calculatePrice
	Definir product_name Como Caracter;
	Definir IVA, DISCOUNT Como Real; // consts
	// variables decalration
	Definir dis, product_units, product_price, subTotal, total Como Real;
	// const variables initialization
	IVA <- 0.15;
	DISCOUNT <- 0.20;
	// variables initialization
	dis <- 0.0;
	product_units <- 0.0;
	product_price <- 0.0;
	subTotal <- 0.0;
	total <- 0.0;
	
	Escribir "Nombre de producto: ";
	leer product_name;
	Escribir "precio del producto: ";
	leer product_price;
	Escribir "Unidades compradas: ";
	Leer product_units;
	
	si product_units < 0 Entonces
		Escribir "Valor no válido";
	SiNo si product_units < 2 Entonces
				subTotal <- product_price * product_units;
				total <- (subTotal * IVA) + subTotal;
				Escribir "su producto no aplicó para el decuento";
				Escribir "Subtotal: ", subTotal;
				Escribir "total con IVA: ",total;
			sino
				dis <- (product_price * product_units) * DISCOUNT;
				subTotal <- (product_price * product_units) - dis;
				total <- (subTotal * IVA) + subTotal;
				Escribir "su producto aplicó para el decuento de 20%";
				Escribir "Subtotal: ", subTotal;
				Escribir "total con IVA: ",total;
		FinSi
	FinSi
	
	
	
	
FinProceso
