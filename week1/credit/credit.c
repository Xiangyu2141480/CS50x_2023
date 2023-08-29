#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long card_number = get_long("Number: ");
    int sum = 0;
    int digits = 0;
    int first_two_digits = 0;
    
    if (card_number < 1e12)
    {
        printf("INVALID\n");
        return 0;
    }

    while (card_number > 0)
    {
        int last_digit = card_number % 10;

        if (digits % 2 == 0)
        {
            sum += last_digit;
        }
        else
        {
            int doubled = last_digit * 2;
            sum += doubled / 10 + doubled % 10;
        }

        card_number /= 10;
        digits++;

        if (card_number > 9 && card_number < 100)
        {
            first_two_digits = card_number;
        }
    }

    if (sum % 10 == 0)
    {
        if (first_two_digits == 34 || first_two_digits == 37)
        {
            printf("AMEX\n");
        }
        else if (first_two_digits >= 51 && first_two_digits <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (first_two_digits / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
