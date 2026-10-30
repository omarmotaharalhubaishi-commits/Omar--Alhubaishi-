#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    // ask the user for the height and ensure it is between 1and 8.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // building the pyramid row bv row.

    for (int i = 0; i < height; i++)

    // printing spaces.

    {
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        // printing hash symbols#.

        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        // move to a new line.
        printf("\n");
    }
}