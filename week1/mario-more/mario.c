#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_pattern(int size);

int main(void)
{
    // get size
    int size = get_size();
    // print pattern
    print_pattern(size);
}

int get_size(void)
{
    int size;
    do
    {
        size = get_int("Size: ");
    }
    while (size < 1 || size > 8);
    return size;
}

void print_pattern(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i + j < size - 1)
                printf(" ");
            else
                printf("#");
        }
        printf("  ");

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
