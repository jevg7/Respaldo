#include <stdio.h>
#include <stdbool.h>

// prototype to calculate the net salary with INSS and IR deductions
void calculateNetSalary( float employeeRemuneration);
// validates user's input
bool isValidDigit(int performanceDigit, float salary);

int main(void)
{
    float employeeWeeklySalary = 0.0; // this will store the employee salary
    int employeePerformance = 0; // this will store the employee rating performance
    int employeeCalls = 0; // this will store the calls that the employee made

    // prompt the employee for its salary
    printf("What's your weekly salary? ");
    scanf(" %f", &employeeWeeklySalary);
    // prompt the boss for a rating 
    printf("How'd you rate your employee performance (0-10)? ");
    scanf(" %d", &employeePerformance);
    // prompt the employee for the calls performed 
    printf("How many calls did your employee take? ");
    scanf(" %d", &employeeCalls);


    if (!isValidDigit(employeePerformance,employeeWeeklySalary)) // validates a positive int withint the range
    {
        // This code block checks if an employee's performance and number of calls made fall within certain ranges to determine if they are eligible for a bonus.
        if (employeePerformance > 5 && employeePerformance < 9){
            if (employeeCalls > 50 && employeeCalls < 101){
                employeeWeeklySalary += 1000.00;
                printf("the employee had an acceptable performance %d/10 and applied for a bonus\n", employeePerformance);
                printf("The employee will have a bonus of c$1000\n");
                printf("the grass salary (weekly) of the employee is: %.2f\n", employeeWeeklySalary);
                calculateNetSalary(employeeWeeklySalary);
                return 0;
            }
            else if (employeeCalls > 100 && employeeCalls < 151){
                employeeWeeklySalary += 1500.00;
                printf("the employee had an acceptable performance %d/10 and applied for a bonus\n", employeePerformance);
                printf("The employee will have a bonus of c$1500\n");
                printf("the grass salary (weekly) of the employee is: %.2f\n", employeeWeeklySalary);
                calculateNetSalary(employeeWeeklySalary);
                return 0;
            }
            else{
                employeeWeeklySalary += 2000.00;
                printf("the employee had an acceptable performance %d/10 and applied for a bonus\n", employeePerformance);
                printf("The employee will have a bonus of c$2000\n");
                printf("the grass salary (weekly) of the employee is: %.2f\n", employeeWeeklySalary);
                calculateNetSalary(employeeWeeklySalary);
                return 0;
            }
            printf("the employee had an acceptable performance %d/10 but did not applied for a bonus\n", employeePerformance);
        }
        else if(employeePerformance > 8 && employeePerformance < 11){
            if (employeeCalls > 50 && employeeCalls < 101){
                employeeWeeklySalary += 1000.00;
                printf("the employee had an excellent performance %d/10 and applied for a bonus\n", employeePerformance);
                printf("The employee will have a bonus of c$1000\n");
                printf("the grass salary (weekly) of the employee is: %.2f\n", employeeWeeklySalary);
                calculateNetSalary(employeeWeeklySalary);
                return 0;
            }
            else if (employeeCalls > 100 && employeeCalls < 151){
                employeeWeeklySalary += 1500.00;
                printf("the employee had an excellent performance %d/10 and applied for a bonus\n", employeePerformance);
                printf("The employee will have a bonus of c$1500\n");
                printf("the grass salary (weekly) of the employee is: %.2f\n", employeeWeeklySalary);
                calculateNetSalary(employeeWeeklySalary);
                return 0;
            }
            else{
                employeeWeeklySalary += 2000.00;
                printf("the employee had an excellent performance %d/10 and applied for a bonus\n", employeePerformance);
                printf("The employee will have a bonus of c$2000\n");
                printf("the grass salary (weekly) of the employee is: %.2f\n", employeeWeeklySalary);
                calculateNetSalary(employeeWeeklySalary);
                return 0;
            }
            printf("the employee had an excellent performance %d/10 but did not applied for a bonus\n", employeePerformance);
            printf("the grass salary (weekly) of the employee remain the same: %.2f\n", employeeWeeklySalary);
            calculateNetSalary(employeeWeeklySalary);
            return 0;
        }
        printf("The employee had a bad performance %d/10 and did not applied for any bonuses\n", employeePerformance);
        printf("the grass salary (weekly) of the employee remain the same: %.2f\n", employeeWeeklySalary);
        calculateNetSalary(employeeWeeklySalary);
        return 0;
    }
    printf("invalid input\n");
    return 0;
}
bool isValidDigit(int performanceDigit, float salary)
{
    // Check if performanceDigit is outside of the range of 0-10, or if salary is less than 1
    if (performanceDigit < 0 || performanceDigit > 10){
        if(salary < 1){
            // If either condition is true, return true to indicate invalid input
            return true;
        }
    }
    // Return false if input is valid
    return false;
}
void calculateNetSalary(float employeeRemuneration)
{
    const float INSS = 0.0625; // Social insurance percentage
    const float rangeFees1 = 0.15; // Tax rate for first salary range
    const float rangeFees2 = 0.20; // Tax rate for second salary range
    const float rangeFees3 = 0.25; // Tax rate for third salary range
    const float rangeFees4 = 0.30; // Tax rate for fourth salary range
    // Upper bounds for each salary range
    const float bound1 = 100000.00;
    const float bound2 = 200000.00;
    const float bound3 = 350000.00;
    const float bound4 = 500000.00;

    float irFeeCalculous = 0.0; // Gross salary with IR deduction
    float remunerationWithFees = 0.0; // Salary after social insurance deduction
    float yearGrossSalary = 0.0;
    float amountOfFeesDeduction = 0.0;


    yearGrossSalary = employeeRemuneration * 52.1; 
    amountOfFeesDeduction =  ( yearGrossSalary * INSS);
    remunerationWithFees = yearGrossSalary - amountOfFeesDeduction;

    // Boolean variables declaration for each salary range
    bool annualSalaryRange1 = (employeeRemuneration > 100000.00) && (employeeRemuneration < 200000.00);
    bool annualSalaryRange2 = (employeeRemuneration > 200000.00) && (employeeRemuneration < 350000.00);
    bool annualSalaryRange3 = (employeeRemuneration > 350000.00) && (employeeRemuneration < 500000.00);

    if (annualSalaryRange1){
            float standardDeduction = 0.0;
            // this will subtract the salary with the IR and its upper bound (100000)
            standardDeduction = (remunerationWithFees - bound1); 
            irFeeCalculous = (standardDeduction * rangeFees1);  // this will calculate the IR
            printf("Your total salary with deductions (annually) is: c$%.2f\n",remunerationWithFees - irFeeCalculous);
            return;
        }
    else if (annualSalaryRange2){
        float standardDeduction = 0.0;
        // this will subtract the salary with the IR and its upper bound (200000)
        standardDeduction = (remunerationWithFees - bound2); 
        irFeeCalculous = (standardDeduction * rangeFees2) + 15000.00; // this will calculate the IR
        printf("Your total salary with deductions (annually) is: %.2f\n", remunerationWithFees - irFeeCalculous);
        return;
    }
    else if (annualSalaryRange3){
        float standardDeduction = 0.0;
        // this will subtract the salary with the IR and its upper bound (350000)
        standardDeduction = (remunerationWithFees - bound3);
        irFeeCalculous = (standardDeduction * rangeFees3) + 45000.0; // this will calculate the IR
        printf("Your total salary with deductions (annually) is: %.2f\n",remunerationWithFees - irFeeCalculous);
        return;
    }
    else{
        float standardDeduction = 0.0;
        // this will subtract the salary with the IR and its upper bound (500000)
        standardDeduction = (remunerationWithFees - bound4); 
        irFeeCalculous = (standardDeduction * rangeFees4) + 82500.0; // this will calculate the IR
        printf("Your total salary with deductions (annually) is: %.2f",remunerationWithFees - irFeeCalculous);
        return;
    }
    //recall so the first range salary, that contains no deduction at all
    printf("You're not applicable for an IR deduction\n");
    printf("Your annual total salary is: %.2f\n", yearGrossSalary);
    return;
}