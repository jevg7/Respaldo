Proceso CalculateNetSalary
	// define consts
	Definir INSS,rangoImp1, rangoImp2, rangoImp3, rangoImp4, exceso1, exceso2, exceso3, exceso4  Como Real;
	
	// initialize consts
	INSS <- 0.07;
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
	
	
	
FinProceso
