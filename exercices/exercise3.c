#include <stdio.h>
#include <stdbool.h>

const float social_insurance = 0.07; // Social insurance percentage
const float rangeOfTaxes1 = 0.15; // Tax rate for first salary range
const float rangeOfTaxes2 = 0.20; // Tax rate for second salary range
const float rangeOfTaxes3 = 0.25; // Tax rate for third salary range
const float rangeOfTaxes4 = 0.30; // Tax rate for fourth salary range

// Validation of IR deduction
bool isApplicableForDeduction(float totalIR);

int main(void)
{
    // Upper bounds for each salary range
    float upper_bound1 = 100000.00;
    float upper_bound2 = 200000.00;
    float upper_bound3 = 350000.00;
    float upper_bound4 = 500000.00;

    // Boolean variables declaration for each salary range
    bool annualSalaryRange1 = false;
    bool annualSalaryRange2 = false;
    bool annualSalaryRange3 = false;

    float extraTaxesCalculationIR = 0.0; // Gross salary with IR deduction
    float salaryWithInssDeduction = 0.0; // Salary after social insurance deduction
    float monthlySalary = 0.0;
    float annualGrosSalary = 0.0;
    float inssDeduction = 0.0;
    
    printf("Insert your monthly salary: ");
    scanf(" %f", &monthlySalary);

    annualGrosSalary = monthlySalary * 12.0; 
    inssDeduction =  ( annualGrosSalary * social_insurance);
    salaryWithInssDeduction = annualGrosSalary - inssDeduction;

    // Print various salary values
    printf("Your Gross salary without extra fees is: c$%.2f\n",annualGrosSalary);
    printf("Your Social Insurance deduction (annually) will be: c$%.2f\n",inssDeduction);
    printf("Your salary with the social insurance deduction is: c$%.2f\n", salaryWithInssDeduction);

    // Check which salary range the employee falls under
    annualSalaryRange1 = (salaryWithInssDeduction > 100000.00) && (salaryWithInssDeduction < 200000.00);
    annualSalaryRange2 = (salaryWithInssDeduction > 200000.00) && (salaryWithInssDeduction < 350000.00);
    annualSalaryRange3 = (salaryWithInssDeduction > 350000.00) && (salaryWithInssDeduction < 500000.00);
    
    // If the employee is not applicable for an IR deduction
    if (!isApplicableForDeduction(salaryWithInssDeduction)){
        // Calculate the deduction for each salary range
        if (annualSalaryRange1){
            float baseDeduction = 0.0;
            // this will subtract the salary with the IR and its upper bound (100000)
            baseDeduction = (salaryWithInssDeduction - upper_bound1); 
            extraTaxesCalculationIR = (baseDeduction * rangeOfTaxes1);  // this will calculate the IR
            printf("You must pay (annually) an IR of: c$%.2f\n", extraTaxesCalculationIR); 
            printf("Your total salary with deductions (annually) is: c$%.2f\n",salaryWithInssDeduction - extraTaxesCalculationIR);
            return 0;
        }
        else if (annualSalaryRange2){
            float baseDeduction = 0.0;
            // this will subtract the salary with the IR and its upper bound (200000)
            baseDeduction = (salaryWithInssDeduction - upper_bound2); 
            extraTaxesCalculationIR = (baseDeduction * rangeOfTaxes2) + 15000.00; // this will calculate the IR
            printf("You must pay (annually) an IR of: c$%.2f\n", extraTaxesCalculationIR);
            printf("Your total salary with deductions (annually) is: c$%.2f\n", salaryWithInssDeduction - extraTaxesCalculationIR);
            return 0;
        }
        else if (annualSalaryRange3){
            float baseDeduction = 0.0;
            // this will subtract the salary with the IR and its upper bound (350000)
            baseDeduction = (salaryWithInssDeduction - upper_bound3);
            extraTaxesCalculationIR = (baseDeduction * rangeOfTaxes3) + 45000.0; // this will calculate the IR
            printf("You must pay (annually) an IR of: c$%.2f\n", extraTaxesCalculationIR);
            printf("Your total salary with deductions (annually) is: %.2f\n",salaryWithInssDeduction - extraTaxesCalculationIR);
            return 0;
        }
        else{
            float baseDeduction = 0.0;
            // this will subtract the salary with the IR and its upper bound (500000)
            baseDeduction = (salaryWithInssDeduction - upper_bound4); 
            extraTaxesCalculationIR = (baseDeduction * rangeOfTaxes4) + 82500.0; // this will calculate the IR
            printf("You must pay (annually) an IR of: c$%.2f\n", extraTaxesCalculationIR);
            printf("Your total salary with deductions (annually) is: c$%.2f",salaryWithInssDeduction - extraTaxesCalculationIR);
            return 0;
        }
    }
    //recall so the first range salary, that contains no deduction at all
    printf("You're not applicable for an IR deduction\n");
    printf("Your annual total salary is: %.2f\n", annualGrosSalary);
    return 0;
}
bool isApplicableForDeduction(float totalIR)
{
    if (totalIR > 100000.00){
        return false;
    }
    return true;
}