#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    do
    {
        card = get_long("Number: ");
    }
    while (card < 0);

    int length = 0;
    long tempcard = card;

    do
    {
        length++;
        tempcard /= 10;
    }
    while (tempcard > 0);

    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    int sum_without2 = 0, sum_with2 = 0, total = 0;
    long mod1, mod2, div, rem;
    tempcard = card;

    do
    {
        // to remove and save the last digit
        mod1 = tempcard % 10;
        sum_without2 += mod1;
        tempcard /= 10;

        // to extract the last second digit
        mod2 = tempcard % 10;
        mod2 *= 2;       // 6 * 2 = 12
        div = mod2 / 10; // 1.2 = 1
        rem = mod2 % 10; // 2
        sum_with2 = div + rem + sum_with2;

        // remove the last second value
        tempcard /= 10;
    }
    while (tempcard > 0);

    // total
    total = sum_without2 + sum_with2;

    // checking if total isnot divisible by 10
    if (total % 10 != 0)
    {
        printf("INVALID\n");
    }
    // check the type of card it is, by checking the starting 2 digits of it
    else
    {
        long starts = card;
        do
        {
            starts /= 10;
        }
        while (starts >= 100);

        if (length == 15 && (starts == 33 || starts == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 &&
                 (starts == 51 || starts == 52 || starts == 53 || starts == 54 || starts == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && (starts / 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    return 0;
}
