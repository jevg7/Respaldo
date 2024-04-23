
#include <stdio.h>
#include <stdbool.h>

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

int main()
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
    // if user pays with a credit card
    if (ans == 121 || ans == 89){
        subtotal = calculateBill(userBurgers);
        total = subtotal + (subtotal * charge);
        printf("Total Bill: %.2f\n", total);
        return 0;
    }
    // if user doesn't pay with a credit card
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