#include <stdio.h>
#include <stdbool.h>

// EXERCISE 1 GLOBALS VARIABLES AND PROTOTYPES
    // Constants for the IVA tax rate and the discount rate
    const float IVA = 0.15; 
    const float DISCOUNT = 0.20;

    // A character array to store the name of the product
    char product_name[50];
    // Function prototype for calculating the subtotal without IVA
    float calculate_subtotalNoIva(float price, int units);

    // Function prototype for determining if the customer is eligible for a discount
    bool isEligibleForDiscount(int unitCount);

    // Function to calculate the product price with IVA
    int get_productPriceIva();

// EXERCISE 2 GLOBALS VARIABLES AND PROTOTYPES
    // Define constant prices for each type of burger and a service charge percentage
    const float plain_burger = 50.0;
    const float double_burger = 70.0;
    const float triple_burger = 100.0;
    const float charge = 0.05;

    // Define arrays of characters for each type of burger
    char burgerType1[] = "Plain burger";
    char burgerType2[] = "Double burger";
    char burgerType3[] = "Triple burger";

    // Define a global variable to keep track of the current bill amount
    float billAmount = 0;

    // Function to calculate the bill for a given number of burgers
    float calculateBill(int amountOfBurgers);

    //function int getBill() prototype
    int getBill();


// EXERCISE 3 GLOBALS VARIABLES AND PROTOTYPES
    const float social_insurance = 0.07; // Social insurance percentage
    const float rangeOfTaxes1 = 0.15; // Tax rate for first salary range
    const float rangeOfTaxes2 = 0.20; // Tax rate for second salary range
    const float rangeOfTaxes3 = 0.25; // Tax rate for third salary range
    const float rangeOfTaxes4 = 0.30; // Tax rate for fourth salary range

    // Validation of IR deduction
    bool isApplicableForDeduction(float totalIR);
    // function int getGrassSalaryIR() prototype
    int getGrassSalaryIR(void);

// EXERCISE 4 GLOBALS VARIABLES AND PROTOTYPES
    // prototype to calculate the net salary with INSS and IR deductions
    void calculateNetSalary( float employeeRemuneration);
    // validates user's input
    bool isValidDigit(int performanceDigit, float salary);
    // function int get_employeeBonus() prototype
    int get_employeeBonus(void);

int main(void)
{
    int optionIdentification = 0;
    printf("********MENU********\n");
    printf("1.Calculate Product Price With IVA.\n2.Make a burger order.\n3.Calculate your annual Grass Salary with fees deductions.\n");
    printf("4.Calculate your weekly gross salary  and your annual net salary with bonuses If there's any applicable.\n5.exit\n");
    printf("Insert option wanted: ");
    scanf(" %i", &optionIdentification);

    switch (optionIdentification)
    {
        case 1:
            // Call the get_productPriceIva function to calculate the product price with IVA
            get_productPriceIva();
            break;
        case 2:
            // This function calculates the bill amount for the customer
            getBill();
            break;
        case 3:
            // This function calculates the employee's annual gross salary after deducting the income tax
            getGrassSalaryIR();
            break;
        case 4:
            // This function calculates the employee's bonus based on their performance and number of calls
            get_employeeBonus();
            break;
        case 5:
            printf("****YOU'VE EXIT THE MENU****\n");
            break;
        default:
            printf("****INVALID OPTION****\n");
            main();
            break;
    }
}
// exercise 1
int get_productPriceIva()
{
    
    // Variables for the product price, number of units purchased, and the subtotal and total amounts
    int product_units = 0;
    float product_price = 0.0;
    float subTotal = 0.0;
    float total = 0.0;

    // Prompt the user to enter the product's name, price, and number of units purchased
    printf("Insert product's name: ");
    scanf("%49s", product_name);
    printf("Insert product's price: ");
    scanf("%f", &product_price);
    printf("How many units of %s did you buy? ", product_name);
    scanf("%i", &product_units);

    // validate that the user has inputted a positive number
    if (product_units < 0){
        printf("Invalid option");
        return 1;
    }
    // If the customer is not eligible for a discount, calculate the subtotal and total with IVA
    if (!isEligibleForDiscount(product_units)){
        subTotal = product_price * (float) product_units;
        total = (subTotal * IVA) + subTotal;
        printf("Your purchase did not apply for a discount\n");
        printf("Subtotal: %.2f\n", subTotal);
        printf("Total with extra fees: %.2f\n", total);
        return 0;
    }

    // If the customer is eligible for a discount, calculate the subtotal with the discount and the total with IVA
    subTotal = calculate_subtotalNoIva(product_price,product_units);
    total = (subTotal * IVA) + subTotal;
    printf("Your purchase applied for a discount of the 20%% off\n");
    printf("Subtotal with discount: %.2f\n",subTotal);
    printf("Total With extra fees: %.2f\n", total);
    return 0;
}

// Function to determine if the customer is eligible for a discount based on the number of units purchased
bool isEligibleForDiscount(int unitCount)
{
    if (unitCount == 1){
        return false;
    }
    return true;
}

// Function to calculate the subtotal without IVA after applying the discount
float calculate_subtotalNoIva(float price, int units)
{
    float dis = 0.0; 
    float sub = 0.0; 
    dis = (price * (float) units) * DISCOUNT;
    sub = (price * (float) units) - dis;
    return sub;
}

// exercise 2
int getBill()
{
    // Define variables for user input and bill calculations
    char ans;
    float subtotal = 0.0;
    float total = 0.0;
    int userBurgers = 0;
    
    // Print a welcome message and ask the user how many burgers they want to order
    printf("******WELCOME TO THE NAUFRAGO SATISFECHO******\n");
    printf("How many burgers would you like?\n");
    scanf("%d", &userBurgers);
    
    // Ask the user if they want to pay with a credit card or not
    printf("Would you like to pay with a credit card? y/n ");
    scanf(" %c", &ans);
    
    // Check the user's answer and calculate the bill accordingly
    if (ans == 121 || ans == 89){
        subtotal = calculateBill(userBurgers);
        total = subtotal + (subtotal * charge);
        printf("Total Bill: %.2f\n", total);
        return 0;
    }
    else if(ans == 110 || ans == 78){
        subtotal = calculateBill(userBurgers);
        total = subtotal;
        printf("Total Bill: %.2f\n", total);
        return 0;
    }
    else{
        printf ("**Invalid payment method**");
        return 1;
    }
}

float calculateBill(int amountOfBurgers)
{
    // Define a variable to keep track of the user's selected burger option
    int option = 0;
    
    // Base case: if there are no more burgers to order, return the current bill amount
    if (amountOfBurgers == 0){
        return billAmount;
    }
    
    // Otherwise, ask the user to select a burger option and update the current bill accordingly
    printf("1. Plain burger c$%.2f\n2. Double burger c$%.2f\n3. Triple burger c$%.2f\n", plain_burger, double_burger, triple_burger);
    printf("Enter your option: ");
    scanf(" %d", &option);
    
    switch (option)
    {
        case 1:
            printf("Your option was: %s %.2f\n", burgerType1, plain_burger);
            billAmount += plain_burger;
            break;
        case 2:
            printf("Your option was: %s %.2f\n", burgerType2, double_burger);
            billAmount += double_burger;
            break;
        case 3:
            printf("Your option was: %s %.2f\n", burgerType3, triple_burger);
            billAmount += triple_burger;
            break;
        default:
            printf("Invalid option\n");
            printf("Bill so far: %.2f\n", billAmount);
            break;
    }
    // Recursively call the calculateBill function with one less burger to order
    calculateBill(amountOfBurgers - 1);
}

// exercise 3
int getGrassSalaryIR(void)
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
            printf("Your total salary with deductions (annually) is: %.2f\n",salaryWithInssDeduction - extraTaxesCalculationIR);
            return 0;
        }
        else if (annualSalaryRange2){
            float baseDeduction = 0.0;
            // this will subtract the salary with the IR and its upper bound (200000)
            baseDeduction = (salaryWithInssDeduction - upper_bound2); 
            extraTaxesCalculationIR = (baseDeduction * rangeOfTaxes2) + 15000.00; // this will calculate the IR
            printf("You must pay (annually) an IR of: c$%.2f\n", extraTaxesCalculationIR);
            printf("Your total salary with deductions (annually) is: %.2f\n", salaryWithInssDeduction - extraTaxesCalculationIR);
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
            printf("Your total salary with deductions (annually) is: %.2f",salaryWithInssDeduction - extraTaxesCalculationIR);
            return 0;
        }
    }
    //recall so the first range salary, that contains no deduction at all
    printf("You're not applicable for an IR deduction\n");
    printf("Your annual total salary is: c$%.2f\n", annualGrosSalary);
    return 0;
}
bool isApplicableForDeduction(float totalIR)
{
    if (totalIR > 100000.00){
        return false;
    }
    return true;
}

// exercise 4
int get_employeeBonus(void)
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
            printf("the employee had an acceptable performance %d/10 but did not applied for a bonus\n", employeePerformance);
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