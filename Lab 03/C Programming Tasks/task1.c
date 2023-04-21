

#include <stdio.h>
#include <stdlib.h>

/*
Question:
Suppose you and your friends go to have breakfast in a restaurant. Each of you order Paratha,
Vegetable and Mineral Water. Treat each of the ordered items as structures and each of the
structures will have two properties which are: quantity and unit price. Each property of the
structure will be taken as input from the user. After taking all the inputs calculate what is the
total bill and also, take input from the user how many people are there in total. Lastly calculate
how much each of the person will have to pay and print it (Note: This value will be float).
*/

// Structure for Paratha
struct Paratha
{
    int quantity;
    float unit_price;
};

// Structure for Vegetable
struct Vegetable
{
    int quantity;
    float unit_price;
};

// Structure for Mineral Water
struct MineralWater
{
    int quantity;
    float unit_price;
};

// Function to calculate total bill
float calculate_bill(struct Paratha paratha, struct Vegetable vegetable, struct MineralWater mineral_water, int num_people)
{
    float total_bill = 0;
    total_bill = (paratha.quantity * paratha.unit_price) + (vegetable.quantity * vegetable.unit_price) + (mineral_water.quantity * mineral_water.unit_price);
    return total_bill / num_people;
}

// main function
int main()
{
    // Declaring variables
    struct Paratha paratha;
    struct Vegetable vegetable;
    struct MineralWater mineral_water;
    float bill;
    int number_of_people;

    // Taking input from the user
    printf("\nQuantity of Paratha: ");
    scanf("%d", &paratha.quantity);
    printf("Unit Price: ");
    scanf("%f", &paratha.unit_price);
    printf("\nQuantity of Vegetable: ");
    scanf("%d", &vegetable.quantity);
    printf("Unit Price: ");
    scanf("%f", &vegetable.unit_price);
    printf("\nQuantity of Mineral Water: ");
    scanf("%d", &mineral_water.quantity);
    printf("Unit Price: ");
    scanf("%f", &mineral_water.unit_price);
    printf("\nNumber of People: ");
    scanf("%d", &number_of_people);

    // Calling the function to calculate total bill
    bill = calculate_bill(paratha, vegetable, mineral_water, number_of_people);

    // Printing the result
    printf("\nIndividual people will pay: %.2f\n", bill);

    return 0;
}
