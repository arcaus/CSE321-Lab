// written by [24341087]

#include <stdio.h>

struct Breakfast
{
    int quantity;
    float unit_price;
};

int main()
{

    struct Breakfast paratha, vegetables, water;
    int num_people;
    float total_bill, individual_payment;

    printf("Quantity Of Paratha: ");
    scanf("%d", &paratha.quantity);
    printf("Unit Price: ");
    scanf("%f", &paratha.unit_price);

    printf("Quantity Of Vegetables: ");
    scanf("%d", &vegetables.quantity);
    printf("Unit Price: ");
    scanf("%f", &vegetables.unit_price);

    printf("Quantity Of Mineral Water: ");
    scanf("%d", &water.quantity);
    printf("Unit Price: ");
    scanf("%f", &water.unit_price);

    printf("Number of People: ");
    scanf("%d", &num_people);

    total_bill = (paratha.quantity * paratha.unit_price) + (vegetables.quantity * vegetables.unit_price) + (water.quantity * water.unit_price);

    individual_payment = total_bill / num_people;

    printf("Individual people will pay: %.2f tk\n", individual_payment);

    return 0;
}
