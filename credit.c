#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long long n;

    do
    {
        n = get_long_long("Number:");
    }
    while (n <= 0);
    long long n1 = n;
    int fTotal = 0;

    //Luhn algorithm
    while (n1 != 0)
    {
        //very last digit of n1
        int digit1 = n1 % 10;
        //second to the last digit times 2 of n1
        int digit = (n1 / 10 % 10) * 2;

        if (digit > 9)
        {
            fTotal = (digit / 10) + (digit % 10) + fTotal;
        }
        else
        {
            fTotal = digit + fTotal;
        }
        fTotal = digit1 + fTotal;
        n1 = n1 / 100;
    }

    //get first digit
    long long n5 = n;
    while (n5 >= 10)
    {
        n5 = n5 / 10;
    }

    //get first two digits
    long long n3 = n;
    while (n3 >= 100)
    {
        n3 = n3 / 10;
    }

    //count the digits of the card
    int count = 0;
    long long countn = n;
    while (countn != 0)
    {
        countn = countn / 10;
        count++;
    }

    if (fTotal % 10 == 0 && (n3 == 34 || n3 == 37) && count == 15)
    {
        printf("AMEX\n");
    }
    else if (fTotal % 10 == 0 && (n3 >= 51 && n3 <= 55) && count == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (fTotal % 10 == 0 && n5 == 4 && (count >= 13 && count <= 16))
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }

}
