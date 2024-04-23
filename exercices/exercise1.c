#include <stdio.h>
#include <stdbool.h>

// Constants for the IVA tax rate and the discount rate
const float IVA = 0.15;
const float DISCOUNT = 0.20;

// A character array to store the name of the product
char product_name[50];

// Function prototype for calculating the subtotal without IVA
float calculate_subtotalNoIva(float price, int units);

// Function prototype for determining if the customer is eligible for a discount
bool isEligibleForDiscount(int unitCount);

int main(){
    
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