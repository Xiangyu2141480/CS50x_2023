#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    // Get message from user
    string message = get_string("Message: ");

    // Iterate over characters in message
    for (int i = 0, len = strlen(message); i < len; i++)
    {
        // Get ASCII value of current character
        int c = (int) message[i];

        // Print 8 bulbs for current character
        for (int j = 7; j >= 0; j--)
        {
            int bit = (c >> j) & 1;
            print_bulb(bit);
        }

        // Newline after 8 bits
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
