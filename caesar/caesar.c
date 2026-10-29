#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototype of the rotateion function.
char rotate(char c, int n);
int main(int argc, string argv[])
{
    // check the number of = arguments passed to the program. If not equal to 2, print usage message 
    // and return 1.
    if (argc != 2)
    { 
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // check if the key is a non-negative integer. If not, print usage message and return 1.
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");

            // return 1 to indicate an error.
            return 1;
        }
    }

    // convert the key from string to integer .
    int key = atoi(argv[1]);

    // get the plaintext from the user
    string plaintext = get_string("plaintext: ");

    // print the ciphertext.
    printf("ciphertext: ");

    // loop through each character of the plaintext and apply the rotation function to it.
    int n = strlen(plaintext);
    for (int i = 0; i < n; i++) 
    {
        printf("%c", rotate(plaintext[i], key));
    } 
    // print a new line after the ciphertext.
    printf("\n");
    // return 0 to indicate successful completion of the program.
    return 0;
}   

// function to rotate a character by n positions in the alphabet.
char rotate(char c, int n)
{

    // check if the character is an uppercase letter. If so, rotate it and print the result.
    if (isupper(c))
    {
        return ("%c", ((c - 'A' + n) % 26) + 'A');
    }
    // check if the character is a lowercase letter. If so, rotate it and print the result.
    else if (islower(c))
    {
        return ((c - 'a' + n) % 26) + 'a';
    } 
    // if the character is not a letter, print it as is.
    else 
    {
        return c;
    }
    // return 0 to indicate successful completion of the function.
    return 0;
}

