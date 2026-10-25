#include <cs50.h>
#include <stdio.h>

int calculate_quaters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents, sum;
    do
    {
        cents = get_int("Changed owed: ");
    }
    while (cents < 0);

    // Calculate how many quarters you should give customer
    int quaters = calculate_quaters(cents);
    // Subtract the value of those quarters from cents
    cents = cents - (quaters * 25);

    // Calculate how many dimes you should give customer
    int dimes = calculate_dimes(cents);
    // Subtract the value of those dimes from cents
    cents = cents - (dimes * 10);

    // Calculate how many nickels you should give customer
    int nickels = calculate_nickels(cents);
    // Subtract the value of those quarters from cents
    cents = cents - (nickels * 5);

    // Calculate how many pennies you should give customer
    int pennies = calculate_pennies(cents);
    // Subtract the value of those quarters from cents
    cents = cents - pennies;

    sum = quaters + dimes + nickels + pennies;
    printf("%d\n", sum);
}

int calculate_quaters(int cents)
{
    // Calculate how many quarters you should give customer
    int quaters = 0;
    while (cents >= 25)
    {
        quaters++;
        cents -= 25;
    }
    return quaters;
}

int calculate_dimes(int cents)
{
    // Calculate how many dimes you should give customer
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents -= 10;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // Calculate how many nickels you should give customer
    int nickels = 0;
    while (cents >= 5)
    {
        nickels++;
        cents -= 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // Calculate how many pennies you should give customer
    int pennies = 0;
    while (cents < 5 && cents > 0)
    {
        pennies++;
        cents -= 1;
    }
    return pennies;
}
