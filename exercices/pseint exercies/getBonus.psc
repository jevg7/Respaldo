Proceso getBonus
	// variable decarations
	Definir employeeWeeklySalary,employeePerformance,employeeCalls Como Real;
	
	employeeWeeklySalary <- 0.0;
	employeePerformance <- 0.0;
	employeeCalls <- 0.0;
	
	escribir "Insert your weekly salary: ";
	leer employeeWeeklySalary;
	Escribir "How would you rate your employee (0-10)";
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
	
	
FinProceso
 	