#include <cs50.h>
#include <stdio.h>
// prototype of the functions to calculate how many coins to give customer.
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
int main(void)
{
    // prompt the user for change owed, in cents.
    int cents;
    // loop to ensure that the user enters a non-negative integer.
    do
    {
        cents = get_int("change owed: ");
    }
    while (cents < 0);

    // calculate how many quarters you should give customer.
    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);

    // calculate how many dimes you should give customer.
    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);

    // calculate how many nickels you should give customer.
    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);

    // calculate how many pennies you should give customer.
    int pennies = calculate_pennies(cents);
    cents = cents - (pennies * 1);

    // calculate the total number of coins to give customer.
    int total_coins = quarters + dimes + nickels + pennies;
    printf("%i\n", total_coins);
}
// function to calculate how many quarters you should give customer.
int calculate_quarters(int cents)
{
    // calculate how many quarters you should give customer.
    int quarter = 0;

    // loop to calculate how many quarters you should give customer.
    while (cents >= 25)
    {
        cents = cents - 25;
        quarter++;
    }
    // return the number of quarters to give customer.
    return quarter;
}

// function to calculate how many dimes you should give customer.
int calculate_dimes(int cents)
{
    // calculate how many dimes you should give customer.
    int dimes = 0;
    // loop to calculate how many dimes you should give customer.
    while (cents >= 10)
    {
        cents = cents - 10;
        dimes++;
    }
    // return the number of dimes to give customer.
    return dimes;
}

// function to calculate how many nickels you should give customer.
int calculate_nickels(int cents)
{
    // calculate how many nickels you should give customer.
    int nickels = 0;
    // loop to calculate how many nickels you should give customer.
    while (cents >= 5)
    {
        cents = cents - 5;
        nickels++;
    }
    // return the number of nickels to give customer.
    return nickels;
}

// function to calculate how many pennies you should give customer.
int calculate_pennies(int cents)
{
    // calculate how many pennies you should give customer.
    int pennies = cents;
    // return the number of pennies to give customer.
    return pennies;
}