Proceso pseudoCodeUnited
	Definir resp Como Entero;
	
	Escribir "********MENU********";
	Escribir  "1.Calculate Product Price With IVA.";
	Escribir  "2.Make a burger order.";
	Escribir  "3.Calculate your annual Grass Salary with fees deductions.";
	Escribir  "4.Calculate your weekly gross salary  and your annual net salary with bonuses If there is any applicable.";
	Escribir  "5.Exit";
	Leer resp;
	Segun resp Hacer
		1:
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

		2:
			
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
			
		3:
			// define consts
			Definir INSS,rangoImp1, rangoImp2, rangoImp3, rangoImp4, exceso1, exceso2, exceso3, exceso4  Como Real;
			
			// initialize consts
			INSS <- 0.0625;
			rangoImp1 <- 0.15;
			rangoImp2 <- 0.20;
			rangoImp3 <- 0.25;
			rangoImp4 <- 0.30;
			exceso1 <- 100000.0;
			exceso2 <- 200000.0;
			exceso3 <- 350000.0;
			exceso4 <- 500000.0;
			
			// define my variables
			Definir baseDeduction,extraTaxesCalculationIR, salaryWithInssDeduction, monthlySalary, annualGrosSalary, inssDeduction Como Real;
			// initialize variables
			baseDeduction <- 0.0;
			extraTaxesCalculationIR <- 0.0; 
			salaryWithInssDeduction <- 0.0; 
			monthlySalary <- 0.0;
			annualGrosSalary <- 0.0;
			inssDeduction <- 0.0;
			
			Escribir  "Insert your monthly salary ";
			Leer  monthlySalary;
			
			annualGrosSalary <- monthlySalary * 12.0; 
			inssDeduction <-  ( annualGrosSalary * INSS);
			salaryWithInssDeduction <- annualGrosSalary - inssDeduction;
			
			Escribir "Your Gross salary without extra fees is: c$",annualGrosSalary;
			Escribir "Your Social Insurance deduction (annually) will be: c$",inssDeduction;
			Escribir "Your salary with the social insurance deduction is: c$", salaryWithInssDeduction;
			
			si (salaryWithInssDeduction > 0.01) Y (salaryWithInssDeduction < 100000.00) Entonces
				Escribir "You are not applicable for an IR deduction";
				Escribir "Your annual total salary is: ", annualGrosSalary;
			SiNo si (salaryWithInssDeduction > 100000.00) Y (salaryWithInssDeduction < 200000.00) Entonces
					baseDeduction <- (salaryWithInssDeduction - exceso1); 
					extraTaxesCalculationIR <- (baseDeduction * rangoImp1);  // this will calculate the IR
					Escribir "You must pay (annually) an IR of: c$", extraTaxesCalculationIR; 
					Escribir "Your total salary with deductions (annually) is: c$",salaryWithInssDeduction - extraTaxesCalculationIR;
				SiNo si (salaryWithInssDeduction > 200000.00) Y (salaryWithInssDeduction < 350000.00) Entonces
						baseDeduction <- (salaryWithInssDeduction - exceso2); 
						extraTaxesCalculationIR <- (baseDeduction * rangoImp2) + 15000.00; // this will calculate the IR
						Escribir "You must pay (annually) an IR of: c$", extraTaxesCalculationIR;
						Escribir "Your total salary with deductions (annually) is: c$", salaryWithInssDeduction - extraTaxesCalculationIR;
					SiNo si (salaryWithInssDeduction > 350000.00) Y (salaryWithInssDeduction < 500000.00) Entonces
							baseDeduction <- (salaryWithInssDeduction - rangoImp3); 
							extraTaxesCalculationIR <- (baseDeduction * rangeOfTaxes2) + 45000.00; // this will calculate the IR
							Escribir "You must pay (annually) an IR of: c$", extraTaxesCalculationIR;
							Escribir "Your total salary with deductions (annually) is: c$", salaryWithInssDeduction - extraTaxesCalculationIR;	
						SiNo
							baseDeduction <- (salaryWithInssDeduction - exceso4); 
							extraTaxesCalculationIR <- (baseDeduction * rangoImp4) + 82500.0; // this will calculate the IR
							Escribir "You must pay (annually) an IR of: c$", extraTaxesCalculationIR;
							Escribir "Your total salary with deductions (annually) is: c$",salaryWithInssDeduction - extraTaxesCalculationIR;
							
						FinSi
					FinSi
				FinSi
			FinSi
			
		4:
			
			// variable decarations
			Definir employeeWeeklySalary,employeePerformance,employeeCalls Como Real;
			
			employeeWeeklySalary <- 0.0;
			employeePerformance <- 0.0;
			employeeCalls <- 0.0;
			
			escribir "Insert your weekly salary: ";
			leer employeeWeeklySalary;
			Escribir "How would you rate your employee (1-10)";
			leer employeePerformance;
			Escribir "how many calls did your employee take? ";
			leer employeeCalls;
			
			si (employeePerformance > 5 Y employeePerformance < 9) Entonces
				si (employeeCalls > 50 Y employeeCalls < 101) Entonces
					employeeWeeklySalary <- employeeWeeklySalary + 1000.00;
					Escribir "the employee had an acceptable performance and applied for a bonus";
					Escribir "The employee will have a bonus of c$1000";
					Escribir "the grass salary (weekly) of the employee is: ", employeeWeeklySalary;
				SiNo 
					si (employeeCalls > 100 Y employeeCalls < 151) Entonces
						employeeWeeklySalary <- employeeWeeklySalary +1500.00;
						Escribir "the employee had an acceptable performance and applied for a bonus";
						Escribir "The employee will have a bonus of c$1000";
						Escribir "the grass salary (weekly) of the employee is: ", employeeWeeklySalary;
					SiNo
						si employeeCalls > 100 Entonces
							employeeWeeklySalary <- employeeWeeklySalary + 2000.00;
							Escribir "the employee had an acceptable performance and applied for a bonus";
							Escribir "The employee will have a bonus of c$1000";
							Escribir "the grass salary (weekly) of the employee is: ", employeeWeeklySalary;
						SiNo
							Escribir "the employee had an excellent performance but did not applied for a bonus";
							Escribir "the grass salary (weekly) of the employee remain the same: ", employeeWeeklySalary;
						FinSi
					FinSi
				FinSi
				
			SiNo 
				si (employeePerformance > 8 Y employeePerformance < 11) Entonces
					si (employeeCalls > 50 Y employeeCalls < 101) Entonces
						employeeWeeklySalary <- employeeWeeklySalary + 1000.00;
						Escribir "the employee had an excellent performance and applied for a bonus";
						Escribir "The employee will have a bonus of c$1000";
						Escribir "the grass salary (weekly) of the employee is: ", employeeWeeklySalary;
					SiNo 
						si (employeeCalls > 100 Y employeeCalls < 151) Entonces
							employeeWeeklySalary <- employeeWeeklySalary + 1500.00;
							Escribir "the employee had an excellentperformance and applied for a bonus";
							Escribir "The employee will have a bonus of c$1000";
							Escribir "the grass salary (weekly) of the employee is: ", employeeWeeklySalary;
							
							
						SiNo
							si employeeCalls > 100 Entonces
								employeeWeeklySalary <- employeeWeeklySalary + 2000.00;
								Escribir "the employee had an excellent performance and applied for a bonus";
								Escribir "The employee will have a bonus of c$1000";
								Escribir "the grass salary (weekly) of the employee is: ", employeeWeeklySalary;	
							SiNo
								Escribir "the employee had an excellent performance but did not applied for a bonus";
								Escribir "the grass salary (weekly) of the employee remain the same: ", employeeWeeklySalary;
								
							FinSi
						FinSi
					FinSi
				SiNo
					Escribir "the employee had a bad performance but did not applied for a bonus";
					Escribir "the grass salary (weekly) of the employee remain the same: ", employeeWeeklySalary;
				FinSi
			FinSi
			
		5:
			Escribir "****YOU HAVE EXITED SUCCESSFULLY**";
		De Otro Modo:
			Escribir "****INVALID OPTION****";
	FinSegun
	
FinProceso
